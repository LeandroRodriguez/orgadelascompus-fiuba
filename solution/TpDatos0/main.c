#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#define CAleerPorPasada 100

void SelectionSort(unsigned char* Vect, int n){
    if(n>1){
        int minimo=0,i,j;
        unsigned char swap;
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

void Merge(unsigned char arreglo1[], int n1, unsigned char arreglo2[], int n2, unsigned char arreglo3[]){
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

void MergeSort(unsigned char VectorAordenar[], int n){

    unsigned char *vector1, *vector2;
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
        vector1=(unsigned char *) malloc(sizeof(unsigned char)*n1);
        vector2=(unsigned char *) malloc(sizeof(unsigned char)*n2);
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
    printf("%s","Si se ejecuta el programa sin especificar ninguna cadena");
    printf("%s","se puede ingresar luego, usando el teclado.\n");
}

void ExportarCadena(unsigned char* Cadena,unsigned int longitud ){
    unsigned int i=0;
    for (i = 0; i < longitud; i++)
        printf ("%c", Cadena[i]);
    printf ("\n");
}

unsigned char* LeerArchivoDeCaracteres(char* RutaArchivo,unsigned int* LongitudTotalDelArchivo){

    if ( RutaArchivo==NULL )return NULL;
    size_t TU = sizeof(unsigned char);
    FILE* ArchivoFisico = fopen(RutaArchivo,"rb");
    if (ArchivoFisico==NULL)return NULL;

	unsigned int Cleidos = 0;
	unsigned int longitud = 0;
	unsigned int TamBuf = CAleerPorPasada ;
	unsigned char* LecturaTemporal = malloc(TU*CAleerPorPasada);
	unsigned char* CadenaFinal = malloc(TU*CAleerPorPasada);
    unsigned char* Aux = NULL;

	while( (Cleidos = fread(LecturaTemporal,TU,CAleerPorPasada, ArchivoFisico))!=0 ) {
		if (longitud+Cleidos >= TamBuf){
			TamBuf = TamBuf * 3;
			Aux = (unsigned char*) realloc(CadenaFinal,TU*TamBuf );
			if (!Aux){break;}
			CadenaFinal=Aux;
		}
		memcpy( CadenaFinal+longitud , LecturaTemporal,Cleidos);//en un principio longitud esta en 0
		// es como pasarle el puntero a stream, simplemente
		longitud = longitud + Cleidos;// la siguiente vez coloca las cosas desde aca.

		//http://stackoverflow.com/questions/2939091/realloc-invalid-next-size
	}

	free(LecturaTemporal);
	Aux = realloc(CadenaFinal, TU* longitud);//lo achica, sacandole las espacios de mas

	if (!Aux){
	    CadenaFinal=Aux;
	    }
	*LongitudTotalDelArchivo=longitud;
	fclose(ArchivoFisico);
	return CadenaFinal;
}

unsigned char* SumarCadenas(unsigned char* V1,unsigned int n1,unsigned char* V2,unsigned int n2){
	unsigned char* Suma = (unsigned char*) malloc(sizeof(unsigned char)*(n1+n2));

	 int i=0;
	 for ( i = 0 ; i < n1 ; i++ ) {
		 Suma[i] = V1[i];
	 }
	 for ( i = n1 ; i < (n1 + n2) ; i++ ){
		 Suma[i] = V2[i-n1];
	 }
	 return Suma;
}

int main(int argc, char *argv[]){

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

    unsigned char* Aux=malloc(1);
    unsigned char* CadenaTotal=malloc(1);

    if (optind < argc){
        while (optind < argc){
            unsigned int LongitudArchivo=0;
            unsigned char* Cadena = LeerArchivoDeCaracteres(argv[optind],&LongitudArchivo);
         //   unsigned char* Cadena = LeerArchivoDeCaracteres(archivo,&LongitudArchivo);
            optind=optind+1;

            if (Cadena!=NULL){
                Aux=SumarCadenas(CadenaTotal,LongitudCadenaAexportar,Cadena,LongitudArchivo);

                if( Aux!=NULL){
                    CadenaTotal=Aux;
                    LongitudCadenaAexportar=LongitudCadenaAexportar+LongitudArchivo;
                    free(Cadena);
                    Aux=NULL;
                }
            }
        }
    }else{
        int c;
        while (EOF != (c = fgetc(stdin))) {
         LongitudCadenaAexportar++;
        }


    }


    if( LongitudCadenaAexportar!=0 ){//por claridad, preferi dejarlo asi
        if( FlagMergeSort)MergeSort(CadenaTotal,LongitudCadenaAexportar);
        if( FlagSelectionSort)SelectionSort(CadenaTotal,LongitudCadenaAexportar);
        if(FlagMergeSort==0 && FlagSelectionSort==0)SelectionSort(CadenaTotal,LongitudCadenaAexportar);//busqueda default
        ExportarCadena(CadenaTotal,LongitudCadenaAexportar);
        free(CadenaTotal);
        CadenaTotal=NULL;
    }
    return 0;
}
