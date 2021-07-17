#include "AL, Numero.c"
#include "AL, Variable.c"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

int esOperadorUnario(char c1, char c2);
int esOperadorBinario(char c1, char c2);
int esOperadorMatematico(char c1, char c2);

bool expresion(char cadena[]);
bool operacion(char cadena[]);
bool asignacion(char cadena[]);

bool mientras(char cadena[]);

/*
int main()
{

    // Prueba Asignaciones
    printf("%i\n", asignacion("A = 1"));
    printf("%i\n", asignacion("AB2 = 22"));
    printf("%i\n", asignacion("ABC = CDA"));

    // Prueba Operaciones
    printf("%i\n", operacion("1 + 1"));
    printf("%i\n", operacion("1 + 1 + 1"));
    printf("%i\n", operacion("A + b + 2"));
    printf("%i\n", operacion("A3 + + U"));

    // Prueba Expresiones
    printf("%i\n", expresion("YHWH == 26"));
    printf("%i\n", expresion("86 > 45"));
    printf("%i\n", expresion("! YH"));

    // Matematicos
    printf("%i\n", esOperadorMatematico('+', ' '));
    printf("%i\n", esOperadorMatematico('%', ' '));
    printf("%i\n", esOperadorMatematico('i', ' '));

    //Prueba Logicos
    printf("%i\n", esOperadorUnario('!', 'B'));
    printf("%i\n", esOperadorUnario('!', '1'));
    printf("%i\n", esOperadorUnario('a', 'A'));

    // Prueba Comparativos
    printf("%i\n", esOperadorBinario('=', '='));
    printf("%i\n", esOperadorBinario('!', '='));
    printf("%i\n", esOperadorBinario('<', '='));
    printf("%i\n", esOperadorBinario('>', '='));
    printf("%i\n", esOperadorBinario('<', '1'));
    printf("%i\n", esOperadorBinario('>', 'A'));
    printf("%i\n", esOperadorBinario('Y', 'B'));
    printf("%i\n", esOperadorBinario('O', '2'));
    printf("%i\n", esOperadorBinario('O', '='));
    printf("%i\n", esOperadorBinario('A', '='));

    return 0;
}
*/

int esOperadorUnario(char c1, char c2)
{
    int respuesta;

    if ((c1=='!') && ((c2>='a' && c2<='z') || (c2>='A' && c2<='Z') || (c2==' ')))
    {
        respuesta = 1;
    }
    else
    {
        respuesta = 0;
    }

    return respuesta;
}

int esOperadorBinario(char c1, char c2)
{
    int respuesta;

    if((c1=='=' && c2=='=') || (c1=='!' && c2=='=') || (c1=='<' && c2=='=') || (c1=='>' && c2=='='))
    {
        respuesta = 2;
    }
    else if ((c1=='<' || c1=='>') && ((c2>='0' && c2<='9') || (c2>='a' && c2<='z') || (c2>='A' && c2<='Z') || (c2==' ')))
    {
        respuesta = 1;
    }
    else if ((c1=='Y' || c1=='O') && ((c2>='0' && c2<='9') || (c2>='a' && c2<='z') || (c2>='A' && c2<='Z') || (c2==' ')))
    {
        respuesta = 1;
    }
    else
    {
        respuesta = 0;
    }

    return respuesta;
}

int esOperadorMatematico(char c1, char c2)
{
    int respuesta;

    if ((c1=='+' || c1=='-' || c1=='*' || c1=='/' || c1=='%') && ((c2>='0' && c2<='9') || (c2>='a' && c2<='z') || (c2>='A' && c2<='Z') || (c2==' ')))
    {
        respuesta = 1;
    }
    else
    {
        respuesta = 0;
    }

    return respuesta;
}

bool expresion(char cadena[])
{
    typedef enum {q0,q1,q2,q3,qe} TEstado;

    TEstado Estado = q0;

    //printf("%s: ", cadena);
    int longitud = strlen(cadena);
    char cadenaTemporal[longitud];
    char *token;


	strcpy(cadenaTemporal, cadena);
    token = strtok(cadenaTemporal," ");
    int porciones = 0;

    while(token != NULL)
    {
        porciones++;
        token = strtok(NULL, " ");
    }
    //printf("Porciones: %i", porciones);



    strcpy(cadenaTemporal, cadena);
    //printf("\nCadena: %s\n", cadenaTemporal);
    token = strtok(cadenaTemporal," ");

    if(porciones == 2)
    {
        Estado = q1;
        for(int i=0; i<porciones; i++)
        {
            switch (Estado)
            {
                case q1:
                {
                    char c1, c2;
                    int longitudCaracteres = strlen(token);
                    if(longitudCaracteres == 1)
                    {
                        c1 = token[0];
                        c2 = ' ';
                    }
                    else if(longitudCaracteres == 2)
                    {
                        c1 = token[0];
                        c2 = token[1];
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q1: ");
                    }

                    if (esOperadorUnario(c1, c2) > 0)
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

                    if (variable(token))
                    {
                        Estado = q3;
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q0: ");
                    }
                    break;
                }
            }

            // Si llega al estado de error, se detiene el analisis
            if (Estado == qe)
            {
                break;
            }

            token = strtok(NULL, " ");
        }
    }
    else if(porciones == 3)
    {
        for(int i=0; i<porciones; i++)
        {
            switch (Estado)
            {
                case q0:
                {
                    if (variable(token) || numero(token))
                    {
                        Estado = q1;
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q0: ");
                    }
                    break;
                }
                case q1:
                {
                    char c1, c2;
                    int longitudCaracteres = strlen(token);
                    if(longitudCaracteres == 1)
                    {
                        c1 = token[0];
                        c2 = ' ';
                    }
                    else if(longitudCaracteres == 2)
                    {
                        c1 = token[0];
                        c2 = token[1];
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q1: ");
                    }

                    if (esOperadorBinario(c1, c2) > 0)
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

                    if (variable(token) || numero(token))
                    {
                        Estado = q3;
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q0: ");
                    }
                    break;
                }
            }

            // Si llega al estado de error, se detiene el analisis
            if (Estado == qe)
            {
                break;
            }

            token = strtok(NULL, " ");
        }
    }

    if (Estado == q3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operacion(char cadena[])
{
    //printf("%s: ", cadena);

	typedef enum {q0,q1,q2,qe} TEstado;
	TEstado Estado = q0;

    //printf("%s: ", cadena);
    int longitud = strlen(cadena);
    char cadenaTemporal[longitud];
    char *token;


	strcpy(cadenaTemporal, cadena);
    token = strtok(cadenaTemporal," ");
    int porciones = 0;

    while(token != NULL)
    {
        porciones++;
        token = strtok(NULL, " ");
    }
    //printf("Porciones: %i", porciones);



    strcpy(cadenaTemporal, cadena);
    //printf("\nCadena: %s\n", cadenaTemporal);
    token = strtok(cadenaTemporal," ");



    for(int i=0; i<porciones; i++)
    {
            switch (Estado)
            {
                case q0:
                {
                    if (variable(token) || numero(token))
                    {
                        Estado = q1;
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q0: ");
                    }
                    break;
                }
                case q1:
                {
                    char c1, c2;
                    int longitudCaracteres = strlen(token);
                    if(longitudCaracteres == 1)
                    {
                        c1 = token[0];
                        c2 = ' ';
                    }
                    else if(longitudCaracteres == 2)
                    {
                        c1 = token[0];
                        c2 = token[1];
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q1: ");
                    }

                    if (esOperadorMatematico(c1, c2) > 0)
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

                    if (variable(token) || numero(token))
                    {
                        Estado = q1;
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error: ");
                    }
                    break;
                }
            }

        // Si llega al estado de error, se detiene el analisis
        if (Estado == qe)
        {
            break;
        }

        token = strtok(NULL, " ");
    }

    if (Estado == q1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool asignacion(char cadena[])
{
    //printf("%s: ", cadena);

	typedef enum {q0,q1,q2,q3,qe} TEstado;
	TEstado Estado = q0;

    //printf("%s: ", cadena);
    int longitud = strlen(cadena);
    char cadenaTemporal[longitud];
    char *token;


	strcpy(cadenaTemporal, cadena);
    token = strtok(cadenaTemporal," ");
    int porciones = 0;

    while(token != NULL)
    {
        porciones++;
        token = strtok(NULL, " ");
    }
    //printf("Porciones: %i", porciones);



    strcpy(cadenaTemporal, cadena);
    //printf("\nCadena: %s\n", cadenaTemporal);
    token = strtok(cadenaTemporal," ");

    for(int i=0; i<porciones; i++)
    {
            switch (Estado)
            {
                case q0:
                {
                    if (variable(token))
                    {
                        Estado = q1;
                        token = strtok(NULL, " ");
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q0: ");
                    }
                    break;
                }
                case q1:
                {
                    if (token[0] == '=')
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
                    int posicion = 0;
                    for(int i=0; longitud; i++)
                    {
                        if(cadena[i] == '=')
                        {
                            posicion = i+1;
                            break;
                        }
                    }

                    char subCadena[longitud-posicion+1];
                    strncpy(subCadena, &cadena[posicion], longitud-posicion);
                    subCadena[longitud-posicion] = '\0';

                    if (numero(subCadena) || variable(subCadena) || expresion(subCadena) || operacion(subCadena))
                    {
                        Estado = q3;
                    }
                    else
                    {
                        Estado = qe;
                        printf("Error q2: ");
                    }
                    break;
                }
            }

        // Si llega al estado de error, se detiene el analisis
        if (Estado == qe)
        {
            break;
        }
    }

    if (Estado == q3)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*
bool mientras()
{
	contador++;
	//Analisamos si el caracter despues del si, sea un parentesis abierto
	if (Temporal[contador] == "(")
    {
		contador++;
		//Revisamos que luego del parentesis lo que se ingresa sea un caracter o cadena
		if (palabra(Temporal[contador]))
        {
			contador++;
			//Analisamos que luego del caracter o cadena, sea un signo matematico valido
			if (Temporal[contador]=="==" || Temporal[contador] == "!=" || Temporal[contador] == "<" || Temporal[contador] == ">")
			{
				contador++;
				//revisamos que lo siguiente sea un numero
				if (numero(Temporal[contador]))
				{
					contador++;
					//Ahora revisamos si el siguiente caracter sea un parentesis, para cerrar el mientras
					if (Temporal[contador]==")")
					{
						contador++;
						//confirmamos que se abran los corchetes de la instruccion si
						if (Temporal[contador]=="{")
						{
							contador++;
							//confirmamos que se cierren los corchetes para darle fin a la instruccion
							if (Temporal[contador]=="}")
							{
								cout<<"--Instruccion mientras, aceptada como valida\n";
								contador++;
								//hacemos la recursividad para que se analizen las siguientes instrucciones
								if (Temporal[contador] == "si" || Temporal[contador] == "sino" || Temporal[contador] == "mientras" || Temporal[contador] == "definir" || Temporal[contador] == "encender" || Temporal[contador] == "apagar")
								{
									EncontrarComandos();
									return true;
								}
                                else
                                {
									return false;
								}
							//todos los else, imprimen un mensaje de que las instrucciones no escribieron de la manera correcta
							}
							else
                            {
								cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
								contador++;
								return false;
							}
						}
						else
                        {
							cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
							contador++;
							return false;
						}
					}
				}
				else
                {
					cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
					contador++;
					return false;
				}
			}
			else
            {
				cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
				contador++;
				return false;
			}
		}
		//Usamos el else if, para aceptar numeros tambien, luego del parentesis
		else if(numero(Temporal[contador]))
        {
			contador++;
			if (Temporal[contador]=="==" || Temporal[contador] == "!=" || Temporal[contador] == "<" || Temporal[contador] == ">")
			{
				contador++;
				//revisamos que lo siguiente es una palabra
				if (palabra(Temporal[contador]))
				{
					contador++;
					//Ahora revisamos si el siguiente caracter sea un parentesis, para cerrar el si
					if (Temporal[contador]==")")
					{
						contador++;
						//confirmamos que se abran los corchetes de la instruccion si
						if (Temporal[contador]=="{")
						{
							contador++;
							//confirmamos que se cierren los corchetes para darle fin a la instruccion
							if (Temporal[contador]=="}")
							{
								cout<<"--Instruccion mientras, aceptada como valida\";
								contador++;
								//hacemos la recursividad para que se analizen las siguientes instrucciones
								if (Temporal[contador] == "si" || Temporal[contador] == "sino" || Temporal[contador] == "mientras" || Temporal[contador] == "definir" || Temporal[contador] == "encender" || Temporal[contador] == "apagar")
								{
									EncontrarComandos();
									return true;
								}
                                else
                                {
									return false;
								}
							//todos los else, imprimen un mensaje de que las instrucciones no escribieron de la manera correcta
							}
							else
                            {
								cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
								contador++;
								return false;
							}
						}
						else
                        {
							cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
							contador++;
							return false;
						}
					}
				}
				else
				{
					cout<<"--Error de sintaxis en la instruccion mientas, no se reconocio como valido\n";
					contador++;
					return false;
				}
			}
			else
			{
				cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
				contador++;
				return false;
			}
		}
		else
        {
			cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
			contador++;
			return false;
		}
	}
	else
	{
		cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
		contador++;
		return false;
	}
}

*/
