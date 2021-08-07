

#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>

int main( )
{

}


bool EsColor(Char color[]){


 //Tipos de dato Estados
    // enum TEstado{q0,q1,q2,q3,q4};
    typedef enum {q0,q1,q2,q3,q4,q5,q6,q7,q8,q9} TEstado;
    //variable de estado
    TEstado Estado;

    //variables
    int Simbolo;    //puede tomar el valor de un caracter de la tablas ASCII


    int i; //iterador
    int longitud; // tomara el valor de longitud de la cadena

    //Definiciendo los valores iniciales
    i = 0;
    longitud = 0;
    Estado = q0;
    printf("estado %d: ", q0);



    longitud = strlen(color);
    printf("tamanio cadena ingresada: %d", longitud);



    while(color[i] !='\0')
    {



      //  printf("impreme : %s", &color[i]);
        switch ( Estado)
        {
        case q0:
            //Si es un simbolo valido cambia de estado
            if(color[i] == 'R')
            {
                Estado = q1;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;
        case q1:
            //Si color[i] es un simbolo valido G cambia de estado
            if(color[i] == 'G')
            {
                Estado = q2;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;
        case q2:
            //Si secundari[i] es un simbolo valido B cambia de estado
            if(color[i] == 'B' )
            {
                Estado = q3;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;
        case q3:
            //Si secundari[i] es un simbolo (  cambia de estado
           if(color[i] == '(' )
            {
                Estado = q4;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;
        case q4:
              //Si secundari[i] es un digito entre cero y 255 cambia de estado
            if(secundari[i] >= '0' && secundari[i] <= '255')
            {
                Estado = q5;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;
            case q5:
            //Si secundari[i] es un simbolo (  cambia de estado
           if(color[i] == ',' )
            {
                Estado = q4;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;
        case q6:
              //Si color[i] es un digito entre cero y 255 cambia de estado
            if(color[i] >= '0' && color[i] <= '255')
            {
                Estado = q7;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;
        case q7:
            //Si secundari[i] es un simbolo (  cambia de estado
           if(color[i] == ',' )
            {
                Estado = q8;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;
        case q8:
              //Si color[i] es un digito entre cero y 255 cambia de estado
            if(color[i] >= '0' && color[i] <= '255')
            {
                Estado = q9;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;
        case q9:
               //Si color[i] es un simbolo )  cambia de estado
           if(color[i] == ')' )
            {
                Estado = q9;
            }else{

                printf("Caracter no valido");
                break;
            }
            break;


         }



        //iterador aunmeta y avanza al siguiente caracter de la cadena
        i++;

    }

    if(Estado == q7)
        printf("Cadena acepatada");
    else
        printf("Cadena No acepatada");

    return false;
}
