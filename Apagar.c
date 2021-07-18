
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


char TablaSimbolos[7] = {'mientras','si','sino','para','definir','encender','apagar'};
char Temporal[200];
char cadena[200];
char variable[200];

//Contador
int contador;

bool si();
bool palabra( char cad[100]);
bool sino();
bool cadena();


int main()
{

    int centinela = 0;
    int i= 0;
    contador ++;

    if(cadena(Temporal[contador])){
        char variable = Temporal[contador];
        int arrayTamanio = sizeof variable/sizeof variable[0];
        for(i = 0; i;< arrayTamanio; i++){

            if (variable.compare(Variables[i])==0){
				if (cadenas(Temporal[contador])){
					centinela = 1;
            printf("Instruccion valida, apagando...%s", Temporal[contador]);
            contador ++;
            /*if(Temporal[contador] =="si" || Temporal[contador] == "sino" || Temporal[contador] == "mientras"
                    || Temporal[contador] == "definir" || Temporal[contador] == "encender" || Temporal[contador] == "apagar")
                    EncontrarComandos();
						return true;
					}else{
						return false;
					}
                */
        }
    }else {


    printf("Error, instruccion no valido" );
    contador ++;
    //return false;
    return 0;
    }
    }else{
				printf("");
			}
		}
		if (centinela == 0){
			printf("Comando  no valido, no existe intrucciion %s",Temporal[contador], " en memoria");
		}
		contador++;
	}else{
		printf("Error de sintaxis, instruccion si, no se reconocio como valido");
		contador++;
		//return false;
	}

    return 0;

}


