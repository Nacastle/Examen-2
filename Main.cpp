#include <iostream>
#include <cstring>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void encriptacion(int n, string & palabra);
void desencriptar(int n, string & palabra);
void validador(string& tarjeta);

int main(int argc, char const *argv[])
{
	int opcion;
	while(opcion != 4){
		cout << "Ingrese donde desea ir\n1. Encriptacion Cesar\n2. Desencriptador.\n3. Verificador de tarjeta\nCualquier otro para salir." << endl;
		cin >> opcion;
		if (opcion == 1)
		{
			string palabra;
			int n = 3;
			cout << "Bienvenido a la encriptacion." << endl;
			cout << "Introduzca la palabra a Encriptar, porfavor ingrese la palabra sin espacios: " << endl;
			cin >> palabra;
			encriptacion(n,palabra);
			cout << "Su frase es: " << palabra << endl;
		}
		else if (opcion == 2)
		{
			string palabra;
			int n = 3;
			cout << "Bienvenido al desencriptador." << endl;
			cout << "Introduzca la palabra a desencriptar, porfavor ingrese la palabra sin espacios: " << endl;
			cin >> palabra;
			desencriptar(n,palabra);
			cout << "Su frase es: " << palabra << endl;

		}else if (opcion == 3)
		{
			string tarjeta;
			cout << "Bienvenido al verificador de tarjetas" << endl;
			cout << "Porfavor ingrese el numero de la tarjeta (16 digitos del 0-9)" << endl;
			cout << "Sin espacios ni guiones, ejemplo: 8273123273510569" << endl;
			cin >> tarjeta;
			validador(tarjeta);
			cout << tarjeta << endl;
		}
		else{
			cout << "Gracias por utilizar este programa" << endl;
			opcion = 4;
		}
	}
	return 0;
}

void encriptacion(int n, string& palabra){

	for (int i = 0; i < palabra.length(); ++i)
	{
		if (palabra[i] >= 'a' && palabra[i] <= 'z')
		{
			if (palabra[i] + n >'z')
			{
				palabra[i] = 'a' - 'z' + palabra[i] +  n - 1;
			}else if (palabra[i] + n < 'a')
			{
				palabra[i] = 'z' - 'a' + palabra[i] +  n + 1;
			}else{
				palabra[i] += n;
			}
		}else if (palabra[i] >= 'A' && palabra[i] <= 'Z')
		{
			if (palabra[i] + n >'Z')
			{
				palabra[i] = 'A' - 'Z' + palabra[i] +  n - 1;
			}else if (palabra[i] + n < 'A')
			{
				palabra[i] = 'Z' - 'A' + palabra[i] +  n + 1;
			}else{
				palabra[i] += n;
			}
		}
		
	}
}

void desencriptar(int n, string& palabra){
	encriptacion(-n,palabra);
}

void validador(string& tarjeta){
	int pares=0,sumapares=0,impares=0,sumaimpares=0,total=0;
	for (int posicion = tarjeta.length(); posicion > 0; posicion--)
	{
		if (posicion%2 == 0)
		{
			pares = (int) tarjeta[posicion - 1] - '0';
			sumapares = sumapares + pares;
		}else{
			impares = ((int) tarjeta[posicion - 1] - '0')*2;
			impares = impares%10 + impares/10;
			sumaimpares = sumaimpares + impares;
		}
	}
	total = sumaimpares + sumapares;
	if (total%10 == 0)
	{
		cout << "Tarjeta valida." << endl;
	}else{
		cout << "Tarjeta invalida." << endl;
	}
}