#include "AL, Mientras.c"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char TablaSimbolosTipos[][16] = {"ENTERO", "FLOTANTE", "BYTE", "NUMERO", "BOOL", "LETRA", "STRING", "COLOR"};
//int longitudPTST[8] = {6, 8, 4, 6, 4, 5, 6, 5};

bool declaracion();
bool declaracionFuncion();

int main()
{
    printf("%i\n", declaracion("BYTE AA = 0 + 1 + 2 + 3"));
    printf("%i\n", declaracion("BYTE AA,BB,CC"));
    //printf("%i", strlen(TablaSimbolosTipos[1]));
    return 0;
}


bool declaracion(char cadena[])
{
    typedef enum {q0,q1,q2,q3,qe} TEstado;

    TEstado Estado = q0;

    int longitud = strlen(cadena);


    char scTipo[16];
    bool tipoEncontrado = false;
    int inicioTipo = 0;
    int tipo = 0;
    for(int i=0; i<longitud; i++)
    {
        for(int j=0; j<strlen(TablaSimbolosTipos); j++)
        {
            if(cadena[i] == TablaSimbolosTipos[j][0])
            {
                tipoEncontrado = true;
                inicioTipo = i;
                tipo = j;

                strncpy(scTipo, &cadena[i], strlen(TablaSimbolosTipos[j]));
                scTipo[strlen(TablaSimbolosTipos[j])] = '\0';
                //printf("%s : %i\n", scTipo, strlen(scTipo));
                break;
            }
        }

        if(tipoEncontrado)
        {
            break;
        }
    }

    if(tipoEncontrado==true)
    {
        Estado = q1;


        //printf("%i\n", tipo);
        //printf("%i\n", inicioTipo);
        //printf("%i\n", longitud-strlen(TablaSimbolosTipos[tipo]));

        char subCadena_1[longitud-strlen(TablaSimbolosTipos[tipo]) + 1];
        strncpy(subCadena_1, &cadena[strlen(TablaSimbolosTipos[tipo])+1], longitud-strlen(TablaSimbolosTipos[tipo]));
        subCadena_1[longitud-strlen(TablaSimbolosTipos[tipo])] = '\0';
        //printf("%s : %i\n", subCadena_1, strlen(subCadena_1));

        char *token;
        token = strtok(subCadena_1, ",");

        while(token != NULL)
        {
            //printf("%s : %i\n", token, strlen(token));
            switch(Estado)
            {
                case q1:
                {
                    if(variable(token) || asignacion(token))
                    {
                        Estado = q2;
                    }
                    else
                    {
                        Estado = qe;
                        //printf("Error q1: ");
                    }
                    break;
                }
                case q2:
                {
                    if(variable(token) || asignacion(token))
                    {
                        Estado = q2;
                    }
                    else
                    {
                        Estado = qe;
                        //printf("Error q2: ");
                    }
                    break;
                }
            }

            token = strtok(NULL, ",");
        }
    }
    else
    {
        Estado = qe;
        printf("Error q0: ");
    }

    if(Estado == q2)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool declaracionFuncion(char cadena[])
{
}
