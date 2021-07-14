#include<stdlib.h>
#include<stdbool.h>

bool variable();
bool expresion();
bool mientras();

int main()
{

    return 0;
}


bool variable()
{

}


bool expresion()
{
    bo

}



bool mientras()
{
	contador++;
	//Analisamos si el caracter despues del si, sea un parentesis abierto
	if (Temporal[contador] == "(")
    {
		contador++;
		//Revisamos que luego del parentesis lo que se ingresa sea un caracter o cadena
		if (palabra(Temporal[contador]))
        {
			contador++;
			//Analisamos que luego del caracter o cadena, sea un signo matematico valido
			if (Temporal[contador]=="==" || Temporal[contador] == "!=" || Temporal[contador] == "<" || Temporal[contador] == ">")
			{
				contador++;
				//revisamos que lo siguiente sea un numero
				if (numero(Temporal[contador]))
				{
					contador++;
					//Ahora revisamos si el siguiente caracter sea un parentesis, para cerrar el mientras
					if (Temporal[contador]==")")
					{
						contador++;
						//confirmamos que se abran los corchetes de la instruccion si
						if (Temporal[contador]=="{")
						{
							contador++;
							//confirmamos que se cierren los corchetes para darle fin a la instruccion
							if (Temporal[contador]=="}")
							{
								cout<<"--Instruccion mientras, aceptada como valida\n";
								contador++;
								//hacemos la recursividad para que se analizen las siguientes instrucciones
								if (Temporal[contador] == "si" || Temporal[contador] == "sino" || Temporal[contador] == "mientras" || Temporal[contador] == "definir" || Temporal[contador] == "encender" || Temporal[contador] == "apagar")
								{
									EncontrarComandos();
									return true;
								}
                                else
                                {
									return false;
								}
							//todos los else, imprimen un mensaje de que las instrucciones no escribieron de la manera correcta
							}
							else
                            {
								cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
								contador++;
								return false;
							}
						}
						else
                        {
							cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
							contador++;
							return false;
						}
					}
				}
				else
                {
					cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
					contador++;
					return false;
				}
			}
			else
            {
				cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
				contador++;
				return false;
			}
		}
		//Usamos el else if, para aceptar numeros tambien, luego del parentesis
		else if(numero(Temporal[contador]))
        {
			contador++;
			if (Temporal[contador]=="==" || Temporal[contador] == "!=" || Temporal[contador] == "<" || Temporal[contador] == ">")
			{
				contador++;
				//revisamos que lo siguiente es una palabra
				if (palabra(Temporal[contador]))
				{
					contador++;
					//Ahora revisamos si el siguiente caracter sea un parentesis, para cerrar el si
					if (Temporal[contador]==")")
					{
						contador++;
						//confirmamos que se abran los corchetes de la instruccion si
						if (Temporal[contador]=="{")
						{
							contador++;
							//confirmamos que se cierren los corchetes para darle fin a la instruccion
							if (Temporal[contador]=="}")
							{
								cout<<"--Instruccion mientras, aceptada como valida\";
								contador++;
								//hacemos la recursividad para que se analizen las siguientes instrucciones
								if (Temporal[contador] == "si" || Temporal[contador] == "sino" || Temporal[contador] == "mientras" || Temporal[contador] == "definir" || Temporal[contador] == "encender" || Temporal[contador] == "apagar")
								{
									EncontrarComandos();
									return true;
								}
                                else
                                {
									return false;
								}
							//todos los else, imprimen un mensaje de que las instrucciones no escribieron de la manera correcta
							}
							else
                            {
								cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
								contador++;
								return false;
							}
						}
						else
                        {
							cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
							contador++;
							return false;
						}
					}
				}
				else
				{
					cout<<"--Error de sintaxis en la instruccion mientas, no se reconocio como valido\n";
					contador++;
					return false;
				}
			}
			else
			{
				cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
				contador++;
				return false;
			}
		}
		else
        {
			cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
			contador++;
			return false;
		}
	}
	else
	{
		cout<<"--Error de sintaxis en la instruccion mientras, no se reconocio como valido\n";
		contador++;
		return false;
	}
}
