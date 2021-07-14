#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool SI();
bool flotante(char a[]);
bool entero(char a[]);
bool variable(char a[]);
bool color(char a[]);
char *Temporal[]={"SI","(","VARIABLE","==","7",")","{","}","SINO","{","}"};
int contador=0;

//metodo main solamente para prueba de la funcion
int main(){

        if(SI()){
            printf("Es una cadena valida\n");
        }else{
            printf("    \n hecho");
        }

    return 1;
}

bool variable(char a[]){
    return true;
}

bool color(char a[]){
    return true;
}
bool entero(char a[]){
    return true;
}
bool flotante(char a[]){
    return true;
}
//funcion si, para verificar que la instruccion fue ingresada de forma correcta
bool SI(){
	contador++;
	//Analisamos si el caracter despues del si, sea un parentesis abierto
	if (Temporal[contador] == "("){
		contador++;
		//Se revisa que se ingrese una variable reconosida, un flotante, un entero o un color
		if (variable(Temporal[contador]) || flotante(Temporal[contador]) || entero(Temporal[contador])|| color(Temporal[contador])){
			contador++;
			//Se revisa que luego del caracter o cadena, sea un signo matematico valido
			if (Temporal[contador]=="==" || Temporal[contador] == "!=" || Temporal[contador] == "<" || Temporal[contador] == ">"){
				contador++;
				//Se revisa que se ingrese una variable reconosida, un flotante, un entero o un color
				if (variable(Temporal[contador]) || flotante(Temporal[contador]) || entero(Temporal[contador])|| color(Temporal[contador])){
					contador++;
					//Ahora revisamos si el siguiente caracter sea un parentesis, para cerrar el si
					if (Temporal[contador]==")"){
						contador++;
						//confirmamos que se abran los corchetes de la instruccion si
						if (Temporal[contador]=="{"){
							contador++;
							//confirmamos que se cierren los corchetes para darle fin a la instruccion
                            if (Temporal[contador]=="}"){
								contador++;
								//Revisamos que la siguiente palabra corresponda a SINO
								if (Temporal[contador]=="SINO"){
                                    contador++;
                                    //confirmamos que se abran los corchetes de la instruccion si
                                    if (Temporal[contador]=="{"){
                                        contador++;
                                        //confirmamos que se cierren los corchetes para darle fin a la instruccion
                                        if (Temporal[contador]=="}"){
                                            printf("--Instruccion SI con SINO, aceptada como valida");
                                            contador++;
                                            //hacemos la recursividad para que se analizen las siguientes instrucciones
                                            if (Temporal[contador] == "SI" || Temporal[contador] == "MIENTRAS" || Temporal[contador] == "VAR"){
                                                //EncontrarComandos();
                                                return true;
                                            }else{
                                                return false;
                                            }
                                        }else{
                                            printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un '}'");
                                            contador++;
                                            return false;
                                        }
                                    }else{
                                        printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un '{'");
                                        contador++;
                                        return false;
                                    }
                                }else{
                                    printf("--Instruccion SI, aceptada como valida");
                                    //hacemos la recursividad para que se analizen las siguientes instrucciones
                                    if (Temporal[contador] == "SI" || Temporal[contador] == "MIENTRAS"){
                                        //EncontrarComandos();
                                        return true;
                                    }else{
                                        return false;
                                    }
								}


							//todos los else, imprimen un mensaje de que las instrucciones no escribieron de la manera correcta
                            }else{
                                printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un '}'");
                                contador++;
                                return false;
                            }
						}else{
							printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un '{'");
							contador++;
							return false;
						}
					}else{
                        printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un ')'");
                        contador++;
                        return false;
					}
                }else{
                    printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava una variable o un numero)");
                    contador++;
                    return false;
				}
			}else{
				printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un (<,><,<=,>=,==)");
				contador++;
				return false;
			}
		}
		//usamos el if para aceptar un true o false
		else if(Temporal[contador]=="true" || Temporal[contador]=="false"){
			contador++;
                //Se da la confirmacion de que se cierre el parentesis
                if (Temporal[contador]==")"){
                    contador++;
                    //se confirma que se abran los corchetes
                    if (Temporal[contador]=="{"){
                        contador++;
                        //se confirma que los corhetes tengan un cierre para la finalizacion de la instruccion SI
                        if (Temporal[contador]=="}"){
                            printf("--Instruccion    SI, aceptada como valida");
                            contador++;
                            //hacemos la recursividad para que se analizen las siguientes instrucciones
                            if (Temporal[contador] == "si" || Temporal[contador] == "sino" || Temporal[contador] == "mientras" || Temporal[contador] == "definir" || Temporal[contador] == "encender" || Temporal[contador] == "apagar"){
                                //EncontrarComandos();
                                return true;
                            }else{
                                return false;
                            }
                        //todos los else, imprimen un mensaje de que las instrucciones no escribieron de la manera correcta
                        }else{
                            printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un '}'");
                            contador++;
                            return false;
                        }
                    }else{
                        printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un '{'");
                        contador++;
                        return false;
                    }
                }
		}else{
			printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un (Variable, valor numerico, true o false)");
			contador++;
			return false;
		}
	}else{
		printf("--Error de sintaxis en la instruccion SI, no se reconocio como valido, se esperava un '('");
		contador++;
		return false;
	}
}

