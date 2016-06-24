#include <iostream>
#include <cstring>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void encriptacion(int n, string & palabra);
void desencriptar(int n, string & palabra);

int main(int argc, char const *argv[])
{
	int opcion;
	while(opcion != 4){
		cout << "Ingrese donde desea ir\n1. Encriptacion Cesar\n2. Desencriptador.\n3. Verificador de tarjeta\nCualquier otro para salir." << endl;
		cin >> opcion;
		if (opcion == 1)
		{
			string palabra;
			int n = 4;
			cout << "Bienvenido a la encriptacion." << endl;
			cout << "Introduzca la palabra a Encriptar, porfavor ingrese la palabra sin espacios: " << endl;
			cin >> palabra;
			encriptacion(n,palabra);
			cout << "Su frase es: " << palabra << endl;
		}
		else if (opcion == 2)
		{
			string palabra;
			int n = 4;
			cout << "Bienvenido al desencriptador." << endl;
			cout << "Introduzca la palabra a desencriptar, porfavor ingrese la palabra sin espacios: " << endl;
			cin >> palabra;
			desencriptar(n,palabra);
			cout << "Su frase es: " << palabra << endl;

		}else if (opcion == 3)
		{
			
		}
		else{
			cout << "Gracias por utilizar este programa" << endl;
			opcion = 3;
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

void desencriptar(int n, string & palabra){
	encriptacion(-n,palabra);
}