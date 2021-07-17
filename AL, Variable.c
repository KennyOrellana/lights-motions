#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool variable(char cadena[]);

/*
int main()
{
    printf("%d\n", variable("YHWH"));

    printf("%d\n", variable("YHWH26"));

    printf("%d\n", variable("26YHWH"));
}
*/


//funcion para reconocer si es una palabra o cadena lo ingresado
bool variable(char cadena[])
{
    //printf("%s: ", cadena);

	typedef enum {q0,q1,q2,qe} TEstado;

	TEstado Estado = q0;
	int Simbolo;
	int longitud = 0;
	int i = 0;

	longitud = strlen(cadena);

	while (longitud > i && Estado != qe)
    {
		Simbolo = cadena[i];

		switch (Estado)
		{
			case q0:
            {
				if ((Simbolo >= 'a' && Simbolo <= 'z') || (Simbolo >= 'A' && Simbolo <= 'Z'))
                {
					Estado = q1;
				}
				else
				{
					Estado = qe;
					//printf("Error Variable q0: ");
				}
				break;
            }
			case q1:
            {
				if ((Simbolo >= 'a' && Simbolo <= 'z') || (Simbolo >= 'A' && Simbolo <= 'Z'))
                {
					Estado = q1;
				}
				else if (Simbolo >= '0' && Simbolo <= '9')
                {
					Estado = q2;
				}
				else
				{
					Estado = qe;
					//printf("Error Variable q1: ");
				}
				break;
            }
            case q2:
            {

				if (Simbolo >= '0' && Simbolo <= '9')
                {
					Estado = q2;
				}
				else
				{
					Estado = qe;
					//printf("Error Variable q2: ");
				}
                break;
            }
		}

		// Si llega al estado de error, se detiene el analisis
		if (Estado == qe)
        {
            break;
        }

        i++;
	}

	if (Estado==q2 || Estado==q1)
    {
		return true;
	}
	else
	{
		return false;
	}
}
