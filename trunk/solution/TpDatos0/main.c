#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


void SelectionSort(char* Vect, int n){
   int minimo=0,i,j;
   int swap;
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

void ExportarCadena(char* cadena,unsigned int longitud ){

    unsigned int i=0;
    for(i=0;i<longitud;i=i+1){
       fputc(cadena[i], stdout); // puede salir por consola o a archivo, segun a donde se redireccione desde afuera.
    }
}

char* SubLeer(char* PunteroArutaDeArchivo,unsigned int longitud){
        FILE* ArchivoFisico = fopen(PunteroArutaDeArchivo,"r");
            if(ArchivoFisico==NULL)return NULL;//archivo no existe
        char c;
        char* CadenaBruta= (char*) malloc(sizeof(char));
        longitud = 0;//nunca esta de mas asegurarse
        while(c!=EOF){
            c=fgetc(ArchivoFisico);
            longitud=longitud+1;
            CadenaBruta = (char*)realloc(CadenaBruta,sizeof(char)*longitud);
            CadenaBruta[longitud-1]=c;
            }
        fclose(ArchivoFisico);
    return CadenaBruta;
}

char* LeerArchivoDeCaracteres(char* PunteroArutaDeArchivo,unsigned int& longitud){
    char* Cadena=NULL;
    if(PunteroArutaDeArchivo!=NULL) {Cadena=SubLeer(PunteroArutaDeArchivo,longitud);}
    return Cadena;
}

int main(int argc, char *argv[]){

    int ParametroLeido=0;
    int longitud=0;
  /* Lista de las opciones cortas válidas */
  const char* const OpcionesCortas = "hvm:s:" ;

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

  while (1)
  {
      int FlagMergeSort=0;
      int FlagSelectionSort=0;
      /* Llamamos a la función getopt */
      ParametroLeido = getopt_long (argc, argv, OpcionesCortas, OpcionesLargas, NULL);

      if (ParametroLeido == -1)
          break; /* No hay más opciones. Rompemos el bucle */

      switch (ParametroLeido)
      {
          case 'h' : /* -h o --help */
              Menu();
              exit(EXIT_SUCCESS);

          case 'v' : /* -v o --version */
              printf("%s","Programa version:1.0 Creditos:TomReaFpiechoLeanRo\n");
              break;

          case 'm' :
              FlagMergeSort=1;
              break;

          case 's' :
            FlagSelectionSort=1;
              break;

          case '?' : /* opción no valida */
              printf("%s","Opcion no valida.Tipee -h o help y pruebe de vuelta");
              exit(EXIT_SUCCESS);

          case -1 : /* No hay más opciones */
              break;

          default : /* Algo más? Quizas archivo ordenandose por metodo default */
            FlagMergeSort=1;//merge sort elegido para default.
              break;
	  }
    if(FlagMergeSort  ^ FlagSelectionSort){
        char* Ruta= optarg;//optarg es como una variable global que viene
        //con la libreria getopt.h y que modifica el metodo getopt.Apunta al argumento de un parametro ("-x:<arg>").
        //LOGICA por si son varios archivos va aca.
        char* Cadena = LeerArchivoDeCaracteres(Ruta,longitud);
        if(Cadena!=NULL){

            printf("%s","Cadena leida desde el archivo no es NULL");

            if(FlagMergeSort)MergeSort(Cadena,longitud);
            if(FlagSelectionSort)SelectionSort(Cadena,longitud);
            ExportarCadena(Cadena,longitud);
            }else{printf("%s","No existe el archivo.");}
        }
    }

    getc(stdin);
    return 0;
}
