#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/// Falta idear la manera de que detecte el FIN de cierre
// Posible: contador de cuantas cosas se Abren, y que al finalizar de revisar el archivo verifique si la cantidad de Cierres es equivalente

char TablaSimbolos[][16] = {"FUNCION", "FIN"};
int longitudPTS[2] = {7, 3};
char *TablaSimbolosTipos[][16] = {"ENTERO", "FLOTANTE", "BYTE", "NUMERO", "BOOL", "LETRA", "STRING", "COLOR"};

bool funcion(char cadena[]);
bool declaracionFuncion(char cadena[]);
bool variable(char cadena[]);


int main()
{
    //printf("%s", TablaSimbolos[0]);
    //printf("%i", strlen(TablaSimbolos[0]));
    printf("%i\n", funcion("FUNCION (BOOL oscar,LETRA romeo,COLOR estado)"));
    printf("%i\n", funcion("     FUNCION (BOOL oscar,LETRA romeo1234,COLOR estado)"));
    //printf("%i\n", mientras("MIENTRAS (YHWH ## 26) HACER"));
    //printf("%i\n", mientras("MAENTRAS (YHWH == 26) HACAR"));
    return 0;
}



bool variable(char cadena[])
{
    //printf("%s: ", cadena);
	typedef enum {q0,q1,q2,qe} TEstado;

	TEstado Estado = q0;
	int Simbolo;
	int longitud = 0;
	int i = 0;

	longitud = strlen(cadena);

	while (longitud > i && Estado != qe)
    {
		Simbolo = cadena[i];

		switch (Estado)
		{
			case q0:
            {
				if ((Simbolo >= 'a' && Simbolo <= 'z') || (Simbolo >= 'A' && Simbolo <= 'Z'))
                {
					Estado = q1;
				}
				else
				{


					Estado = qe;
					//printf("Error Variable q0: ");
				}
				break;
            }
			case q1:
            {
				if ((Simbolo >= 'a' && Simbolo <= 'z') || (Simbolo >= 'A' && Simbolo <= 'Z'))
                {
					Estado = q1;
				}
				else if (Simbolo >= '0' && Simbolo <= '9')
                {
					Estado = q2;
				}
				else
				{
					Estado = qe;
					//printf("Error Variable q1: ");
				}
				break;
            }
            case q2:
            {

				if (Simbolo >= '0' && Simbolo <= '9')
                {
					Estado = q2;
				}
				else
				{
					Estado = qe;
					//printf("Error Variable q2: ");
				}
                break;
            }
		}

		// Si llega al estado de error, se detiene el analisis
		if (Estado == qe)
        {
            break;
        }

        i++;
	}

	if (Estado==q2 || Estado==q1)
    {
		return true;
	}
	else
	{
		return false;
	}
}

bool declaracionFuncion(char cadena[]){
    typedef enum {q0,q1,q2,q3,qe} TEstado;
    //printf("%s: ",cadena);
    TEstado Estado = q0;

    int longitud = strlen(cadena);


    bool tipoEncontrado = false;
    int inicioTipo = 0;
    int tipo = 0;
    int cont=0,i=0;
    int vista=0;

    while(cont==0)
    {
        for(i; i<longitud; i++)
        {
            if(cadena[i]==" ")
            {
                continue;
            }
            for(int j=0; j<strlen(TablaSimbolosTipos); j++)
            {
                for(int y=0; y<strlen(TablaSimbolosTipos[j]); y++)
                {
                    tipoEncontrado = true;
                    //char simbolo=cadena[i];
                    //printf("pre: %s \n", simbolo);
                    if( cadena[i] == TablaSimbolosTipos[j][y])
                    {
                        tipo = j;
                        //printf("%s : \n", scTipo);
                    }else{
                        tipoEncontrado = false;
                        break;
                    }
                }
                if(tipoEncontrado)
                {
                    break;
                }
            }

            if(tipoEncontrado)
            {
                vista=i+1;
                break;
            }
        }

        if(tipoEncontrado==true)
        {
            Estado = q1;


            //printf("%i\n", tipo);

            //printf("%i\n", longitud-strlen(TablaSimbolosTipos[tipo]));
            while(cont==0)
            {
               if(cadena[vista]==' ')
                {
                    vista++;
                }else
                {
                    break;
                }
            }
            int pep=vista+1;
            while(pep<longitud)
            {
               if(cadena[pep]==' ' || cadena[pep]==',' || cadena[pep]=='\0')
                {
                    break;
                }
                pep++;
            }

            char subCadena_1[pep-vista + 1];
            strncpy(subCadena_1, &cadena[vista], pep-vista);
            subCadena_1[pep-vista] = '\0';
            //printf("%s : %i\n", subCadena_1, strlen(subCadena_1));

            printf("hola %s:\n",subCadena_1);

            if(subCadena_1 != NULL)
            {
                switch(Estado)
                {
                    case q1:
                    {
                        if(variable(subCadena_1))
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
                        if(variable(subCadena_1))
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
            }
        }
        else
        {
            Estado = qe;
            printf("Error q0: ");
        }
        if(Estado != q2)
        {
            break;
        }


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

bool funcion(char cadena[])
{
    typedef enum {q0,q1,q2,qe} TEstado;

    TEstado Estado = q0;

    int longitud = strlen(cadena);

    if(longitud >= strlen(TablaSimbolos[0]))
    {
        int inicioFUNCION;
        for(int i=0; i<longitud; i++)
        {
            if(cadena[i] == TablaSimbolos[0][0])
            {
                inicioFUNCION = i;
                break;
            }
        }
        char subCadena_1[longitudPTS[0]+1];
        strncpy(subCadena_1, &cadena[inicioFUNCION], longitudPTS[0]);
        subCadena_1[longitudPTS[0]] = '\0';

        //printf("%s : %i\n", subCadena_1, strlen(subCadena_1));
        //printf("%s : %i\n", TablaSimbolos[0], strlen(TablaSimbolos[0]));
        //printf("%i\n", (strcmp(subCadena_1, TablaSimbolos[0])==0));

        if(strcmp(subCadena_1, TablaSimbolos[0]) == 0) // Iguales
        {
            Estado = q1;

            int inicioDeclaracion, finDeclaracion = 0;
            for(int i=8; i<longitud; i++)
            {
                if(cadena[i] == '(')
                {
                    inicioDeclaracion = i;
                }

                if(cadena[i] == ')')
                {
                    finDeclaracion = i;
                    break;
                }
            }

            if(finDeclaracion > 0)
            {
                char condicion[(finDeclaracion-inicioDeclaracion-1)+1];
                strncpy(condicion, &cadena[inicioDeclaracion+1], (finDeclaracion-inicioDeclaracion));
                condicion[finDeclaracion-inicioDeclaracion-1] = '\0';
                printf("%s\n", condicion[5]);

                if(declaracionFuncion(condicion))
                {
                    Estado = q2;
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

    if(Estado == q2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
