

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool numero(char p[100]);
int main()
{


    return 0;
}



bool numero(char cadena[100])
{
    typedef enum {q0,q1} TEstado;

    TEstado Estado;

    char Caden[100];
    int sinbolo;
    bool EsNumero;

    int i;
    int longitud;

    i=longitud = 0;
    Estado = q0;
    EsNumero = false;

    longitud = strlen(cadena);

    while(longitud>i)
    {

        simbolo = Caden[i];
        EsNumero = (simbolo >='0'&& simbolo <= '9');

        if(Estado ==q0)
        {
            id(EsNumero)
            {
                Estado =q1;
            }
        }
        if (!EsNumero)
        {
            Estado = q0;
            break;
        }
        i++;
    }
    if (Estado==q1)
        return true;
    else
        return false;




}
