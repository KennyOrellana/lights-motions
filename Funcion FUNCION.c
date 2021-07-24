#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/// Falta idear la manera de que detecte el FIN de cierre
// Posible: contador de cuantas cosas se Abren, y que al finalizar de revisar el archivo verifique si la cantidad de Cierres es equivalente

char TablaSimbolos[][16] = {"FUNCION", "FIN"};
int longitudPTS[2] = {7, 3};
char *TablaSimbolosTipos[] = {"ENTERO", "FLOTANTE", "BYTE", "NUMERO", "BOOL", "LETRA", "STRING", "COLOR"};

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
bool declaraF(char cadena[]){

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

    //printf("%s:\n",cadena);
    bool tipoEncontrado = false;
    int tipo = 0;
    int i=0;
    int tam= sizeof(TablaSimbolosTipos) / sizeof(char *);
    char *token, *token2;
    token = strtok(cadena, ",");
    //printf("%s:\n",token);

    while(token != NULL)
    {
        token2 = strtok(token, " ");
        //printf("%s:\n",token2);
        if(token2 != NULL){
            for(i; i<longitud; i++)
            {
                //printf("siguiente");
                for(int j=0; j<tam; j++)
                {
                    tipoEncontrado = true;
                    //printf("%s \n",TablaSimbolosTipos[j]);

                    if(strcmp(token2,TablaSimbolosTipos[j]) == 0)
                    {
                        tipo = j;
                        //printf("%s : \n", scTipo);
                    }else{
                        tipoEncontrado = false;
                    }

                    if(tipoEncontrado)
                    {
                        break;
                    }
                }

                if(tipoEncontrado)
                {
                    break;
                }
            }
        }


        if(tipoEncontrado==true)
        {
            Estado = q1;


            //printf("%i\n", tipo);

            //printf("%i\n", longitud-strlen(TablaSimbolosTipos[tipo]));
            printf("entre %s\n",token2);
            token2 = strtok(NULL, " ");
            printf("entre %s\n",token2);
            if(token2 != NULL)
            {
                switch(Estado)
                {
                    case q1:
                    {
                        if(variable(token2))
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
                        if(variable(token2))
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
        /*if(Estado != q2)
        {
            break;
        }*/
        token = strtok(cadena, ",");
        token = strtok(NULL, " ");
        printf("\n%s :",token);
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
                //printf("%s\n", condicion);
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
