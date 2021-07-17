#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool esByte(char cadena[]);
bool entero(char cadena[]);
bool flotante(char cadena[]);
bool numero(char cadena[]);

/*
int main()
{
    printf("%d\n", esByte("-1"));
    printf("%d\n", esByte("0"));
    printf("%d\n", esByte("26"));
    printf("%d\n", esByte("255"));
    printf("%d\n", esByte("256"));

    printf("%d\n", numero("-0123456789"));
    printf("%d\n", numero("0123456789"));
    printf("%d\n", numero("+0123456789"));
    printf("%d\n", numero("-w0123456789"));
    printf("%d\n", numero("w0123456789w"));
    printf("%d\n", numero("+w"));

    printf("%d\n", numero("-0.1"));
    printf("%d\n", numero("22.24"));
    printf("%d\n", numero("+1.23"));
    printf("%d\n", numero("-2.w"));
    printf("%d\n", numero("12.2w4"));
    printf("%d\n", numero("+w.2"));


    printf("%d\n", entero("0123456789"));
    printf("%d\n", entero("w0123456789"));
    printf("%d\n", entero("w0123456789w"));
    printf("%d\n", entero("w"));


    printf("%d\n", flotante("0.1"));
    printf("%d\n", flotante("22.24"));
    printf("%d\n", flotante("1.23"));
    printf("%d\n", flotante("2"));
    printf("%d\n", flotante("2.w"));
    printf("%d\n", flotante("w.2"));

}
*/

bool esByte(char cadena[])
{
    if(numero(cadena))
    {
        int N = atoi(cadena);
        if(N>=0 && N<=255)
        {
            return true;
        }
        else
        {
            printf("Error Byte: ");
            return false;
        }
    }
    else
    {
        printf("Error Entero: ");
        return false;
    }
}

bool entero(char cadena[])
{
    //printf("%s: ", cadena);

    typedef enum {q0,q1,qe} TEstado;

	TEstado Estado = q0;
	int Simbolo;
	int i = 0;
	int longitud = 0;
	bool EsNumero = false;

	longitud = strlen(cadena);

	while (longitud > i)
    {
		Simbolo  = cadena[i];
		EsNumero = (Simbolo >= '0' && Simbolo <= '9');

		switch(Estado)
		{
            case q0:
            {
                if(EsNumero)
                {
                    Estado = q1;
                }
                else
                {
                    Estado = qe;
                    //printf("Error Entero q0: ");
                }
                break;
            }
            case q1:
            {
                if(EsNumero)
                {
                    Estado = q1;
                }
                else
                {
                    Estado = qe;
                    //printf("Error Entero q1: ");
                }
            }
            break;
		}

		if (Estado == qe)
		{
			break;
		}

		i++;
	}

	if (Estado == q1)
	{
	    return true;
	}
	else
    {
        return false;
    }
}


bool flotante(char cadena[])
{
    //printf("%s: ", cadena);

    typedef enum {q0,q1,q2,q3,qe} TEstado;

	TEstado Estado = q0;
	int Simbolo;
	int i = 0;
	int longitud = 0;
	bool EsNumero = false;

	longitud = strlen(cadena);

	while (longitud > i)
    {
		Simbolo  = cadena[i];
		EsNumero = (Simbolo >= '0' && Simbolo <= '9');

		switch(Estado)
		{
            case q0:
            {
                if(EsNumero)
                {
                    Estado = q1;
                }
                else
                {
                    Estado = qe;
                    //printf("Error Flotante q0: ");
                }
                break;
            }
            case q1:
            {
                if(EsNumero)
                {
                    Estado = q1;
                }
                else if(Simbolo == '.')
                {
                    Estado = q2;
                }
                else
                {
                    Estado = qe;
                    //printf("Error Flotante q1: ");
                }
                break;
            }
            case q2:
            {
                if(EsNumero)
                {
                    Estado = q3;
                }
                else
                {
                    Estado = qe;
                    //printf("Error Flotante q2: ");
                }
                break;
            }
            case q3:
            {
                if(EsNumero)
                {
                    Estado = q3;
                }
                else
                {
                    Estado = qe;
                    //printf("Error Flotante q3: ");
                }
                break;
            }
		}

		if (Estado == qe)
		{
			break;
		}

		i++;
	}

	if (Estado == q3)
	{
	    return true;
	}
	else
    {
        return false;
    }
}

bool numero(char cadena[])
{
    //printf("%s: ", cadena);

    typedef enum {q0,q1,q2,qe} TEstado;

	TEstado Estado = q0;
	int Simbolo;
	int i = 0;
	int longitud = 0;
	bool EsNumero = false;

	longitud = strlen(cadena);

	while (longitud > i)
    {
		Simbolo  = cadena[i];
		EsNumero = (Simbolo >= '0' && Simbolo <= '9');

		switch(Estado)
		{
            case q0:
            {
                if(Simbolo=='-' || Simbolo=='+')
                {
                    Estado = q1;
                }
                else if(EsNumero)
                {
                    Estado = q1;

                    if(entero(cadena)==true || flotante(cadena)==true)
                    {
                        Estado = q2;
                    }
                }
                else
                {
                    Estado = qe;
                    //printf("Error Numero q0: ");
                }
                break;
            }
            case q1:
            {
                char subCadena[longitud];
                strncpy(subCadena, &cadena[1], longitud-1);
                subCadena[longitud-1] = '\0';

                if(entero(subCadena)==true || flotante(subCadena)==true)
                {
                    Estado = q2;
                }
                else
                {
                    Estado = qe;
                    //printf("Error Numero q1: ");
                }
            }
            break;
		}

		if (Estado == qe)
		{
			break;
		}

		i++;
	}

	if (Estado == q2)
	{
	    return true;
	}
	else
    {
        return false;
    }
}
