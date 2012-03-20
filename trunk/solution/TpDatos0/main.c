#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


void SelectionSort(char* Vect, int n){
    if(n>1){
        int minimo=0,i,j;
        char swap;
        for(i=0 ; i<n-1 ; i++)
        {
            minimo=i;
            for(j=i+1 ; j<n ; j++)
            if (Vect[minimo] > Vect[j])
            minimo=j;
            swap=Vect[minimo];
            Vect[minimo]=Vect[i];
            Vect[i]=swap;
            }
        }
}

void Merge(char arreglo1[], int n1, char arreglo2[], int n2, char arreglo3[]){
    //posicion dentro del array
    int x1=0, x2=0, x3=0;

    while (x1<n1 && x2<n2) {
        if (arreglo1[x1] < arreglo2[x2]) {
            arreglo3[x3] = arreglo1[x1];
            x1++;
        } else {
            arreglo3[x3] = arreglo2[x2];
            x2++;
        }
        x3++;
    }
    while (x1<n1) {
        arreglo3[x3] = arreglo1[x1];
        x1++;
        x3++;
    }
    while (x2<n2) {
        arreglo3[x3] = arreglo2[x2];
        x2++;
        x3++;
    }
}

void MergeSort(char VectorAordenar[], int n){

    char *vector1, *vector2;
    int n1, n2,x,y;
    if (n>1)
    {
        //la idea aca bajo es partir el vector en 2...considerando el caso donde se puede dividir en partes iguales o no
        if (n%2 == 0)
            n1=n2=(int) n / 2;
        else
        {
            n1=(int) n / 2;n2=n1+1;
        }
        //pido espacio para los 2 vectores, guardo punteros a esas posiciones de memoria
        vector1=(char *) malloc(sizeof(char)*n1);
        vector2=(char *) malloc(sizeof(char)*n2);
        //cargo mis 2 vectores, cada uno con la "mitad" de los datos del vector Original
        for(x=0;x<n1;x++)
            vector1[x]=VectorAordenar[x];
        for(y=0;y<n2;x++,y++)
            vector2[y]=VectorAordenar[x];
        //la idea es divir la lista hasta tener los pedazos individuales, y aplicar merge recursivamente a las listas que
        //van formando
        MergeSort(vector1, n1);
        MergeSort(vector2, n2);
        Merge(vector1, n1, vector2, n2, VectorAordenar);
        free(vector1);
        free(vector2);
    }
}

void Menu(){
    printf("%s","-h :  ayuda\n");
    printf("%s","-v :  version\n");
    printf("%s","-m :  merge sort\n");
    printf("%s","-s : selection sort\n");
}

void ExportarCadena(char* Cadena,unsigned int longitud ){

    printf("%s","Empieza Exportar cadena.\n");
  //  unsigned int i=0;
   // for(i=0;i<longitud;i=i+1){
     //  fputc(Cadena[i], stdout); // puede salir por consola o a archivo, segun a donde se redireccione desde afuera.
   printf("%s",Cadena);
   // }
     printf("%s","Termino de exportar cadena.\n");
}

char* LeerArchivoDeCaracteres(char* RutaDeArchivo,unsigned int* lon,char* Cadena){
    if(RutaDeArchivo!=NULL){
         FILE* ArchivoFisico = fopen(RutaDeArchivo,"r");
            if(ArchivoFisico==NULL){
                printf("%s","Archivo fisico null\n");
                }else{
                    char c;
                    c=5;
                    while(c!=EOF){
                        c=fgetc(ArchivoFisico);
                        if(c!=EOF){
                            *lon=(*lon)+1;
                            Cadena = (char*)realloc(Cadena,(sizeof(char)) * (*lon));
                            Cadena[(*lon)-1]=c;
                            }
                    }
                    *lon=*lon-1;//leo uno de mas
                fclose(ArchivoFisico);
                if(Cadena==NULL)printf("%s","Cadena NULA!\n");
            }
    }
    return Cadena;
}

int main(int argc, char *argv[]){
    int FlagMergeSort=0;
    int FlagSelectionSort=0;//por default viene ACTIVADO este
  /* Lista de las opciones cortas válidas */
    const char* const OpcionesCortas = "hvms" ;

  /* Una estructura de varios arrays describiendo los valores largos */
  const struct option OpcionesLargas[] =
  {
      { "help",         0,  NULL,   'h'},
      { "version",      0,  NULL,   'v'},
      { "merge sort",       1,  NULL,   'm'},
      { "selection sort",   1,  NULL,  's' }
  };

    /* Si se ejecuta sin parámetros ni opciones */
  if (argc == 1){Menu();exit(EXIT_SUCCESS);}

  char* Cadena=(char*) malloc(sizeof(char));//importante

  unsigned int LongitudCadenaAexportar=0;

  while (1){
      int ParametroLeido;
      /* Llamamos a la función getopt */
      ParametroLeido = getopt_long (argc, argv, OpcionesCortas, OpcionesLargas, NULL);
      //char* Ruta= optarg;//optarg es como una variable global que viene
        //con la libreria getopt.h y que modifica el metodo getopt.Apunta al argumento de un parametro ("-x:<arg>").
        //LOGICA por si son varios archivos va aca.

      if (ParametroLeido == -1){
          if( FlagMergeSort && FlagSelectionSort){
              FlagMergeSort=0;
              FlagSelectionSort=0;
              printf("%s","Opcion no valida.Tipee -h o --help y pruebe de vuelta\n");
              exit(EXIT_SUCCESS);
          }
          break; /* No hay más opciones. Rompemos el bucle */
          }

      switch (ParametroLeido){
          case 'h' : /* -h o --help */
              Menu();
              exit(EXIT_SUCCESS);

          case 'v' : /* -v o --version */
              printf("%s","Programa version:1.0 Creditos:TomReaFpiechoLeanRo\n");
              exit(EXIT_SUCCESS);
              break;

          case 'm' :
          FlagMergeSort=1;
              break;

          case 's' :
          FlagSelectionSort=1;
              break;

          case '?' : /* opción no valida */
              printf("%s","Opcion no valida.Tipee -h o --help y pruebe de vuelta\n");
              exit(EXIT_SUCCESS);

          case -1 :
              break;

          default :
              break;
        }
  }//se procesaron todos los parametros

    while (optind < argc){//optind es variable global usada por libreria getopt

        printf("%d",optind);
        printf("%s","\n");
        printf("%s",argv[optind]);
        printf("%s","\n");
        Cadena=LeerArchivoDeCaracteres(argv[optind],&LongitudCadenaAexportar,Cadena);
        optind=optind+1;
        //argv es donde estan las supuestas"rutas" de los archivos a leer
        }
        printf("%s","Longitud de la cadena=");
        printf("%d",LongitudCadenaAexportar);
        printf("%s"," .\n");
        printf("%s","------------------------------\n");

        printf("%s","Antes de ordenar, almacenado en memoria: \n");
        ExportarCadena(Cadena ,LongitudCadenaAexportar);
        printf("%s","------------------------------\n");

    //se leyeron todos los argumentos del programa

    if( LongitudCadenaAexportar!=0 ){//por claridad, preferi dejarlo asi
        if( FlagMergeSort)MergeSort(Cadena,LongitudCadenaAexportar);
        if( FlagSelectionSort)SelectionSort(Cadena,LongitudCadenaAexportar);
        if(FlagMergeSort==0 && FlagSelectionSort==0)SelectionSort(Cadena,LongitudCadenaAexportar);
        ExportarCadena(Cadena,LongitudCadenaAexportar);
    }
    return 0;
}
