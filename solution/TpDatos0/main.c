#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include<string.h>

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

void BorrarFinDeLinea(char LastChar,unsigned int* longitud){

    if(LastChar==10){//codigo ascii del ULTIMO /n
        *longitud=*longitud-1;
        }
    }

void Menu(){
    printf("%s","-h :  ayuda\n");
    printf("%s","-v :  version\n");
    printf("%s","-m :  merge sort\n");
    printf("%s","-s : selection sort\n");
    printf("%s","Si se ejecuta el programa sin especificar ninguna cadena");
    printf("%s","se puede ingresar luego, usando el teclado.\n");
}

void ExportarCadena(char* Cadena,unsigned int longitud ){

    unsigned int i=0;
    for(i=0;i<longitud;i=i+1)
     fputc(Cadena[i], stdout); // puede salir por consola o a archivo, segun a donde se redireccione desde afuera.
     printf("%s","\n");
}

char* LeerArchivoDeCaracteres(char* RutaDeArchivo,unsigned int* lon,char* Cadena){
    if(RutaDeArchivo!=NULL){
         FILE* ArchivoFisico = fopen(RutaDeArchivo,"r");
            if(ArchivoFisico==NULL){
                printf("%s","Archivo fisico null\n");
                }else{

                    unsigned int LongTemp =0;
                    unsigned int CantidadAleerPorPasada=5;
                    unsigned int CantidadDeLeidos= CantidadAleerPorPasada+1;//asi entra al while
                    char* LecturaTemporal=(char*) malloc(sizeof(char) * CantidadAleerPorPasada);
                    char* CadenaTemporal= NULL;

                    while( !(CantidadDeLeidos<CantidadAleerPorPasada)){
                            CantidadDeLeidos=fread(LecturaTemporal,sizeof(char), CantidadAleerPorPasada, ArchivoFisico);
                            //printf("%s","Leyo: ");
                            //printf("%d",CantidadDeLeidos);
                            //printf("%s"," char de ");
                            //printf("%s\n",RutaDeArchivo);
                            LongTemp=LongTemp+CantidadDeLeidos;
                            CadenaTemporal = (char*)realloc(CadenaTemporal,(sizeof(char)*LongTemp));
                            CadenaTemporal[LongTemp-CantidadDeLeidos]='\0';
                            strcat(CadenaTemporal,LecturaTemporal);
                    }//al salir del while lei todo el archivo, y este esta en CadenaTemporal
                    *lon=*lon+LongTemp;
                    Cadena = (char*) realloc(Cadena,sizeof(char) * (*lon));
                    Cadena[(*lon-LongTemp)]='\0';
                    strcat(Cadena,CadenaTemporal);
                    //*lon=*lon-1;
                    //printf("%s","Longitud: ");
                    //printf("%d\n",*lon);
                    //printf("%s\n","---------------");
                    fclose(ArchivoFisico);
                    free(CadenaTemporal);
                    free(LecturaTemporal);
                    CadenaTemporal=NULL;
                    LecturaTemporal=NULL;
                    //printf("%s\n","Termino de leer");
            }
    }
    BorrarFinDeLinea(Cadena[*lon-1],lon);
    return Cadena;
}

int main(int argc, char *argv[]){

  char* Cadena=NULL;
  unsigned int LongitudCadenaAexportar=0;

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

  while (1){
      int ParametroLeido;
      /* Llamamos a la función getopt */
      ParametroLeido = getopt_long (argc, argv, OpcionesCortas, OpcionesLargas, NULL);
      //char* Ruta= optarg;//optarg es como una variable global que viene
        //con la libreria getopt.h y que modifica el metodo getopt.Apunta al argumento de un parametro ("-x:<arg>").
        //LOGICA por si son varios archivos va aca.

      if (ParametroLeido == -1){
          if( FlagMergeSort && FlagSelectionSort){// no quedan mas parametros, pero se eligieron 2 modos
              FlagMergeSort=0;
              FlagSelectionSort=0;
              printf("%s","Opcion no valida.Tipee -h o --help y pruebe de vuelta\n");
              exit(EXIT_SUCCESS);
              }else{
                  break;
                  }
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

          default :
              break;
        }
  }//se procesaron todos los parametros opciones

    if (optind < argc){

        while (optind < argc){//optind es variable global usada por libreria getopt,
        //Es el indice para verificar parametros que no son opciones
            Cadena=LeerArchivoDeCaracteres(argv[optind],&LongitudCadenaAexportar,Cadena);
            optind=optind+1;
        //argv es donde estan las supuestas"rutas" de los archivos a leer
        }
        //se leyeron todos los parametros NO opciones
        }else{
        int cantidad=10;
        size_t TamInicial=sizeof(char)*cantidad;
        Cadena = (char *) malloc (TamInicial);
        LongitudCadenaAexportar = getline (&Cadena, &TamInicial, stdin);
         }


    if( LongitudCadenaAexportar!=0 ){//por claridad, preferi dejarlo asi
        if( FlagMergeSort)MergeSort(Cadena,LongitudCadenaAexportar);
        if( FlagSelectionSort)SelectionSort(Cadena,LongitudCadenaAexportar);
        if(FlagMergeSort==0 && FlagSelectionSort==0)SelectionSort(Cadena,LongitudCadenaAexportar);//busqueda default
        ExportarCadena(Cadena,LongitudCadenaAexportar);
        }
        free(Cadena);
        Cadena=NULL;
    return 0;
}
