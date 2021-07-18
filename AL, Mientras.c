#include "AL, Expresiones.c"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/// Falta idear la manera de que detecte el FIN de cierre
// Posible: contador de cuantas cosas se Abren, y que al finalizar de revisar el archivo verifique si la cantidad de Cierres es equivalente

char TablaSimbolos[][16] = {"MIENTRAS", "HACER", "FIN"};
int longitudPTS[3] = {8, 5, 3};

bool mientras(char cadena[]);

/*
int main()
{
    //printf("%s", TablaSimbolos[0]);
    //printf("%i", strlen(TablaSimbolos[0]));

    printf("%i\n", mientras("MIENTRAS (YHWH == 26) HACER"));
    printf("%i\n", mientras("     MIENTRAS   (Adam    Y       Jawah)   HACER   "));
    printf("%i\n", mientras("MIENTRAS (YHWH ## 26) HACER"));
    printf("%i\n", mientras("MAENTRAS (YHWH == 26) HACAR"));

    return 0;
}
*/

bool mientras(char cadena[])
{
    typedef enum {q0,q1,q2,q3,qe} TEstado;

    TEstado Estado = q0;

    int longitud = strlen(cadena);

    if(longitud >= strlen(TablaSimbolos[0]))
    {
        int inicioMIENTRAS;
        for(int i=0; i<longitud; i++)
        {
            if(cadena[i] == TablaSimbolos[0][0])
            {
                inicioMIENTRAS = i;
                break;
            }
        }
        char subCadena_1[longitudPTS[0]+1];
        strncpy(subCadena_1, &cadena[inicioMIENTRAS], longitudPTS[0]);
        subCadena_1[longitudPTS[0]] = '\0';

        //printf("%s : %i\n", subCadena_1, strlen(subCadena_1));
        //printf("%s : %i\n", TablaSimbolos[0], strlen(TablaSimbolos[0]));
        //printf("%i\n", (strcmp(subCadena_1, TablaSimbolos[0])==0));

        if(strcmp(subCadena_1, TablaSimbolos[0]) == 0) // Iguales
        {
            Estado = q1;

            int inicioCondicion, finCondicion = 0;
            for(int i=8; i<longitud; i++)
            {
                if(cadena[i] == '(')
                {
                    inicioCondicion = i;
                }

                if(cadena[i] == ')')
                {
                    finCondicion = i;
                    break;
                }
            }

            if(finCondicion > 0)
            {
                char condicion[(finCondicion-inicioCondicion-1)+1];
                strncpy(condicion, &cadena[inicioCondicion+1], (finCondicion-inicioCondicion));
                condicion[finCondicion-inicioCondicion-1] = '\0';
                //printf("%s\n", condicion);

                if(expresion(condicion))
                {
                    Estado = q2;

                    char subCadena_2[(longitud-finCondicion-1)+1];
                    strncpy(subCadena_2, &cadena[finCondicion+1], longitud);
                    subCadena_2[longitud-finCondicion-1] = '\0';
                    //printf("%s\n", subCadena_2);

                    for(int i=finCondicion+1; i < longitud; i++)
                    {
                        if(cadena[i] == ' ')
                        {
                            continue;
                        }

                        if(cadena[i] == TablaSimbolos[1][0])
                        {
                            char PR_HACER[longitudPTS[1]+1];
                            strncpy(PR_HACER, &cadena[i], longitudPTS[1]);
                            PR_HACER[longitudPTS[1]] = '\0';

                            //printf("%s : %i\n", PR_HACER, strlen(PR_HACER));
                            //printf("%s : %i\n", TablaSimbolos[1], strlen(TablaSimbolos[1]));
                            //printf("%i\n", (strcmp(PR_HACER, TablaSimbolos[1])==0));

                            if(strcmp(PR_HACER, TablaSimbolos[1]) == 0)
                            {
                                Estado = q3;
                            }
                            else
                            {
                                Estado = qe;
                                printf("Error q3: ");
                            }

                            break;///////////////////////////////////////////////
                        }
                        else
                        {
                            Estado = qe;
                            printf("Error q2: ");
                            break;
                        }
                    }
                }
                else
                {
                    Estado = qe;
                    printf("Error q1: ");
                }
            }
            else
            {
                Estado = qe;
                printf("Error q1: ");
            }
        }
        else
        {
            Estado = qe;
            printf("Error q0: ");
        }
    }
    else
    {
        Estado = qe;
        printf("Error q0: ");
    }

    if(Estado == q3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
