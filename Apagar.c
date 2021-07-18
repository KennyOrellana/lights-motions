
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


char TablaSimbolos[7] = {'mientras','si','sino','para','definir','encender','apagar'};
char* Temporal[200];

char* variable[200];

//Contador
int contador;



bool cadena(char palb[]);
bool apagar();

int main()
{




    return 0;
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




bool cadena(char palb[]){
	int conta =0;
	while(conta< strlen(palb)){
        //Comprobamos que la palabra tenga los caracteres o números validos correspondientes
        if(!(palb[conta]>='A' && palb[conta] <= 'Z' || palb[conta]>='a' && palb[conta] <= 'z'
                        || palb[conta]>= '0' && palb[conta] <= '9'|| palb[conta]>='[' && palb[conta] <= '_' )){
            return false;
        }
        conta++;
    }
    return true;
}



