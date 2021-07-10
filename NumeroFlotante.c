
#include <stdio.h>
int main( )
{
    //Tipos de dato Estados
    enum T_Estado {q0,q1,q2,q3,q4};

    //variable de estado
    T_Estado Estado;

    //variables
    string Cadena; // es donde se almacenara la cadena
    int Simbolo;    //puede tomar el valor de un caracter de la tablas ASCII
    bool EsNumero;

    int i; //iterador
    int longitud; // tomara el valor de longitud de la cadena

    //Definiciendo los valores iniciales
    i = longitud = 0;
    Estado = q0;

    printf("Ingrese una cadena de numeros: ");
        scanf("%s", &cadena);




    return 0;
}
