#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void SelectionSort(char* Vect, int n)
{
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

void MergeSort(char VectorAordenar[], int n)
{
    void Merge(char arreglo1[], int n1, char arreglo2[], int n2, char arreglo3[])
{
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


int main(int argc, char *argv[]){

    int ParametroLeido;

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
  if (argc == 1)
  {
      Menu();
      exit(EXIT_SUCCESS);
  }

  while (true)
  {
      FlagVersion=false;
      FlagMergeSort=false;
      FlagSelectionSort=false;

      /* Llamamos a la función getopt */
      ParametroLeido = getopt_long (argc, argv, OpcionesCortas, OpcionesLargas, NULL);

      if (ParametroLeido == -1)
          break; /* No hay más opciones. Rompemos el bucle */

      switch (ParametroLeido)
      {
          case 'h' : /* -h o --help */
              imprime_uso();
              exit(EXIT_SUCCESS);

          case 'v' : /* -v o --version */
              FlagVersion = true ;
              break;

          case 'o' : /* -o ó --output */
              fichero_salida = optarg; /* optarg contiene el argumento de -o */
              break;

          case '?' : /* opción no valida */
              imprime_uso(); /* código de salida 1 */
              exit(1);

          case -1 : /* No hay más opciones */
              break;

          default : /* Algo más? No esperado. Abortamos */
              abort();
	  }
  }



    return 0;
}
