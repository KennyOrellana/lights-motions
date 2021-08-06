#include "AL, Mientras.c"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char TablaSimbolosTipos[][16] = {"ENTERO", "FLOTANTE", "BYTE", "NUMERO", "BOOL", "LETRA", "STRING", "COLOR"};
//int longitudPTST[8] = {6, 8, 4, 6, 4, 5, 6, 5};

bool declaracion();
bool declaracionFuncion();

/*
int main()
{
    printf("%i\n", declaracion("BYTE AA = 0 + 1 + 2 + 3"));
    printf("%i\n", declaracion("BYTE AA, BB, CC,"));

    declaracionFuncion("ENTERO A, BYTE B, BOOL C");
    //printf("%i", strlen(TablaSimbolosTipos[1]));
    return 0;
}
*/

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

                strncpy(scTipo, &cadena[i], strlen(TablaSimbolosTipos[j])+1);
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
    tipoEncontrado = false;

    //printf("%s", scTipo);
    if(strcmp(scTipo, TablaSimbolosTipos[tipo]) == 0)
    {
        tipoEncontrado = true;
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
    typedef enum {q0,q1,q2,q3,qe} TEstado;

    TEstado Estado = q0;

    int longitud = strlen(cadena);

        char cadenaTemporal[longitud + 1];
        strcpy(cadenaTemporal, cadena);
        cadenaTemporal[longitud] = '\0';
        //printf("%s : %i\n", subCadena_1, strlen(subCadena_1));

        char *token;
        token = strtok(cadenaTemporal, ",");

        while(token != NULL)
        {
            printf("\n TOKEN: %s\n", token);
            char partes[strlen(token)];
            //memcpy (partes, token, strlen(token));
            //partes[strlen(token)] = '\0';
            strcpy(partes, token);

            char *declaraciones;
            declaraciones = strtok(partes," ");

            int porciones = 0;

            while(declaraciones != NULL)
            {
                printf("\n%s\n", declaraciones);

                switch(Estado)
                {
                    case q0:
                    {
                        char scTipo[16];
                        bool tipoEncontrado = false;
                        int inicioTipo = 0;
                        int tipo = 0;
                        for(int i=0; i<longitud; i++)
                        {
                            for(int j=0; j<strlen(TablaSimbolosTipos); j++)
                            {
                                if(declaraciones[i] == TablaSimbolosTipos[j][0])
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

                        if(strcmp(scTipo, TablaSimbolosTipos[tipo]) == 0)
                        {
                            Estado = q1;
                        }
                        else
                        {
                            Estado = qe;
                            printf("Error q0: \n");
                        }

                        break;
                    }
                    case q1:
                    {
                        if(variable(declaraciones))
                        {
                            Estado = q2;
                        }
                        else
                        {
                            Estado = qe;
                            printf("Error q1: ");
                        }

                        break;
                    }
                    case q2:
                    {
                        if(porciones > 2)
                        {
                            printf("Error");
                        }

                        break;
                    }
                }

                porciones++;
                declaraciones = strtok(NULL, " ");
            }

            token = strtok(NULL, ",");
        }
}
