
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


char TablaSimbolos[7] = {'mientras','si','sino','para','definir','encender','apagar'};
char Temporal[200];
char variable[200];

//Contador
int contador;

bool cadena(char palb[]);
bool apagar();

int main()
{

    char cadenaPalabra[] = "Palabra";
    if (cadena(cadenaPalabra)){

        printf("verifica que la palabra que se metio es una cadena");
    }else{
         printf("la palabra que se metio no es una cadena");
    }



    return 0;
}

//generar tokens de las cadenas del archivo de texto, para analizar las palabras
void tokens(){
	char *token;
	int n = 0;
	int TamanioTemporal;
	//Sacamos la primer palabra de la cadena leida del archivo de texto
	token = strtok(cadena, " ,;");

	//Sacamos el tama?o de nuestra tabla de simbolos para recorrer y comparar las palabras
	int TamanioArreglo = sizeof TablaSimbolos/sizeof TablaSimbolos[0];


	while(token){
       char *comando = token;

		for (TamanioTemporal = 0; TamanioTemporal<TamanioArreglo; TamanioTemporal++){
			//comparamos si el comando existe en  nuestra tabla de simbolos
			if (strcmp(&comando,TablaSimbolos[TamanioTemporal])==0){
				printf("Comando reconocido: %s", &comando);

				break;
			}
		}
		//Pasamos a la siguiente palabra, para analizar
		token = strtok(NULL," ,;");
		//Almacenamos las palabras encontradas en un arreglo, para luego trabajar con el arreglo en los comandos y sus fuciones
		Temporal[n] = &comando;
		n++;
	}
	TamanioTemporal = n;
}




bool cadena(char palb[]){
	int conta =0;
	while(conta< strlen(palb)){
        //Comprobamos que la palabra tenga los caracteres o n?meros validos correspondientes
        if(!(palb[conta]>='A' && palb[conta] <= 'Z' || palb[conta]>='a' && palb[conta] <= 'z'
                        || palb[conta]>= '0' && palb[conta] <= '9')){
            return false;
        }
        conta++;
    }
    return true;
}



bool apagar(){
    int centinela = 0;
    int i= 0;
    contador ++;

    if(cadena(Temporal[contador]))
    {
        char var = Temporal[contador];
        int arrayTamanio = sizeof variable/sizeof variable[0];
        for(i = 0; i < arrayTamanio; i++)
        {

            if (strcmp(var,variable[i])==0)
            {
                if (cadena(Temporal[contador]))
                {
                    centinela = 1;
                    printf("Instruccion valida, apagando...%s", Temporal[contador]);
                    contador ++;
                 /*   if(Temporal[contador] =="si" || Temporal[contador] == "sino" || Temporal[contador] == "mientras"
                            || Temporal[contador] == "definir" || Temporal[contador] == "encender" || Temporal[contador] == "apagar")
                    {
                        EncontrarComandos();
                        return true;
                    }
                    else
                    {
                        return false;
                    }*/

                }
                else
                {
                    printf("Error, instruccion no valida" );
                    contador ++;
                    return false;

                }
            }
            else
            {
                printf("");
            }
        }
        if (centinela == 0)
        {
            printf("Comando  no valido, no existe intrucciion %s",Temporal[contador], " en memoria");
        }
        contador++;
    }
    else
    {
        printf("Error de sintaxis, instruccion si, no se reconocio como valido");
        contador++;
        return false;
    }
    }



