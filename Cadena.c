#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool cadena(char palb[]);
bool ID(char palb[]);
bool OperadorBinario(char palb);
bool OperadorLogico(char palb[]);

//metodo main solamente para prueba de la funcion
int main(){
    while(true){
        char cadena_de_caracteres[100];
        scanf("%s", cadena_de_caracteres);
        if(OperadorLogico(cadena_de_caracteres)){
            printf("Es una cadena valida\n");
        }else{
            printf("NO es una cadena valida\n");
        }
    }
    return 0;
}


//funcion ID devuelve un true si la cadena es valida y un false en caso contrario
bool ID(char palb[]){
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

bool cadena(char palb[]){
	int conta =0;
	while(conta< strlen(palb)){
        //Comprobamos que la palabra tenga los caracteres o números validos correspondientes
        if(!(palb[conta]>='A' && palb[conta] <= 'Z' || palb[conta]>='a' && palb[conta] <= 'z' || palb[conta]>= '0' && palb[conta] <= '9'|| palb[conta]>='!' && palb[conta] <= '$' || palb[conta]>='&' && palb[conta] <= ')' || palb[conta]>='[' && palb[conta] <= '_' ||
           palb[conta]>='{' && palb[conta] <= 126 || palb[conta]==',' || palb[conta] == ';' || palb[conta]==':' || palb[conta] == '.' || palb[conta] == '?' || palb[conta] == '¡' || palb[conta] == '¿'|| OperadorBinario(palb[conta]) || OperadorLogico(palb[conta]))){
            return false;
        }
        conta++;
    }
    return true;
}

bool OperadorBinario(char palb){

    //Comprobamos que la caracter sea un caracter valido
    if(!(palb == '+' || palb == '/' || palb == '-' || palb == '*' || palb == '%' )){
        return false;
    }
    return true;
}

bool OperadorLogico(char palb[]){
	int conta =0;
	while(conta< strlen(palb)){
        //Comprobamos que la palabra tenga los caracteres validos correspondientes
        if(!(palb[conta]=='=' || palb[conta] == '>' || palb[conta]=='<' || palb[conta] == '!' || palb[conta]== 'Y' || palb[conta]== 'O' )){
            return false;
        }
        conta++;
    }
    return true;
}
