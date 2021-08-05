#include<stdio.h>
#include<stdlib.h>

struct arrChar
{
    char string[400];
};

int main()
{
    // Archivo donde esta el codigo
    char inputFilename[] = "entrada.txt";
    // Aqui se guardaran los errores y lecturas
    char outputFilename[] = "salida.txt";

    struct arrChar aux;
    *aux.string = "";

    int lineaActual=0;
    char *devf;

    FILE *ifp;
    ifp = fopen(inputFilename, "r");

    for(int i=0; devf!=NULL; i++)
    {
        lineaActual = i;
        devf = fgets(aux.string, 4000, ifp);

        /// Aqui adentro haremos las comprobaciones linea a linea si hay errores o no.
        printf("%s", devf);

    }

    printf("\n\nEl archivo tiene %d lineas\n", lineaActual);
    fclose (ifp);

    return 0;
}
