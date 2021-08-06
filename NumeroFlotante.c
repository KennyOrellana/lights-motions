
#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>

int main( )
{
    //Tipos de dato Estados
    // enum TEstado{q0,q1,q2,q3,q4};
    typedef enum {q0,q1,q2,q3,q4} TEstado;
    //variable de estado
    TEstado Estado;

    //variables
    char secundari[100]; // es donde se almacenara la cadena
    int Simbolo;    //puede tomar el valor de un caracter de la tablas ASCII


    int i; //iterador
    int longitud; // tomara el valor de longitud de la cadena

    //Definiciendo los valores iniciales
    i = 0;
    longitud = 0;
    Estado = q0;
    printf("estado %d: ", q0);


    printf("Ingrese una cadena de numeros: ");
    scanf("%s", &secundari);
    printf("letra: %s\n\n",secundari);
    longitud = strlen(secundari);
    printf("tamanio cadena ingresada: %d", longitud);



    while(secundari[i] !='\0')
    {


        //Simbolo = secundari[i];
        //   Es Numero = (simbolo >='0'&& simbolo <= '9');
        printf("impreme : %s", &secundari[i]);
        switch ( Estado)
        {
        case q0:
            //Si es un simbolo valido cambia de estado en este caso menos(-) o mas(+)
            if(secundari[i] == '-' || secundari[i] == '+' )
            {
                Estado = q1;
            }else{
                Estado = q1;
            }
            break;
        case q1:
            //Si secundari[i] es un digito entre cero y nueve cambia de estado
            if(secundari[i] >= '0' && secundari[i] <= '9')
            {
                Estado = q2;
            }
            break;
        case q2:
            //Si el simbolo es de nuevo un digito  entre cero y nueve no cambia de estado
            if(secundari[i] >= '0' && secundari[i] <= '9')
            {
                Estado = q2;
            }
            else
            {
                //Caso contrario si secundari[i] es un punto cambia de estado
                if(secundari[i] == '.')
                {
                    Estado = q3;
                }
            }
            break;
        case q3:
            //Si secundari[i] es un digito entre cero y nueve cambia de estado
            if(secundari[i] >= '0' && secundari[i] <= '9')
            {
                Estado = q4;
            }
            break;
        case q4:
            //Si secundari[i] es un digito entre cero y nueve no cambia de estado
            if(secundari[i] >= '0' && secundari[i] <= '9')
            {
                Estado = q4;
            }
            break;
        }
       //si se leyo algun caracter no valido

        if(!(secundari[i] >= '0' && secundari[i] <= '9') ||

                !(secundari[i] == '.'))
        {

            break;
        }
        //iterador aunmeta y avanza al siguiente caracter de la cadena
        i++;

    }

    if(Estado == q4)
        printf("Cadena acepatada");
    else
        printf("Cadena No acepatada");

    return 0;
}
