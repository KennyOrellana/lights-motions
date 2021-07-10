#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool cadena(char palb[]);

//metodo main solamente para prueba de la funcion
int main(){
    while(true){
        char cadena_de_caracteres[100];
        scanf("%s", cadena_de_caracteres);
        if(cadena(cadena_de_caracteres)){
            printf("Es una cadena valida\n");
        }else{
            printf("NO es una cadena valida\n");
        }
    }
    return 0;
}


//funcion cadena devuelve un 1 si la cadena es valida y un 0 en caso contrario
bool cadena(char palb[]){
	int conta =0;
	while(conta< strlen(palb)){
        //Comprobamos que la palabra tenga los caracteres o números validos correspondientes
        if(!(palb[conta]>='A' && palb[conta] <= 'Z' || palb[conta]>='a' && palb[conta] <= 'z' || palb[conta]>= '0' && palb[conta] <= '9')){
            return false;
        }
        conta++;
    }
    return true;
}
