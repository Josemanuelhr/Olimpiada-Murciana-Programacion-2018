#include <iostream>

using namespace std;

/**
 *		+-----------+-----------+-----------+-----------+
 *		|   Estado	|	  /  	|	  _  	|	  \  	|
 *		+-----------+-----------+-----------+-----------+
 *		|	  q0  	|	  q1  	|	  q0  	|	  q0  	|
 *		+-----------+-----------+-----------+-----------+
 *		|	  q1  	|	  q2  	|	  q0  	|	  q0  	|
 *		+-----------+-----------+-----------+-----------+
 *		|	  q2  	|	  q3  	|	  q0  	|	  q0  	|
 *		+-----------+-----------+-----------+-----------+
 *		|	  q3  	|	  q3  	|	  q4  	|	  q0  	|
 *		+-----------+-----------+-----------+-----------+
 *		|	  q4  	|	  q1  	|	  q4  	|	  q5  	|
 *		+-----------+-----------+-----------+-----------+
 *		|	  q5  	|	  q1  	|	  q0  	|	  q6  	|
 *		+-----------+-----------+-----------+-----------+
 *		|	  q6  	|	  q1  	|	  q0  	|	  q7  	|
 *		+-----------+-----------+-----------+-----------+
 *		|	  q7  	|	  q1  	|	  q0  	|	  q7  	|
 *		+-----------+-----------+-----------+-----------+
 *
 *		Si llegas a q7, le sumas 1 al contador de colina
 *		Significado de cada estado:
 *			- q0: Estado inicial, no se ha leido ningun caracter que comience una secuencia correcta para formar una colina
 *			- q1: Se ha leido una subida "/"
 *			- q2: Se han leido dos subidas "/"
 *			- q3: Se han leido tres o mas subidas "/"
 *			- q4: Se han leido una o mas planicies "_"
 *			- q5: Se ha leido una bajada "\"
 *			- q6: Se han leido dos bajadas "\"
 *			- q7: Se han leido tres o mas bajadas "\"
 *
**/

string cadena;
int estado;		// Variable que almacena el estado actual del automata

// Funcion que devuelve el numero de colinas que hay en una cierta cadena
int analizar_cadena() {
	int cont = 0;
	estado = 0;	// estado inicial del automata
	char elem;	// elemento actual
	for (int i = 0; cadena[i]; ++i) {
		elem = cadena[i];
		switch(estado) {
    		case 0:
    			if (elem=='/')
    				estado = 1;
    			else
    				estado = 0;
    			break;
    		case 1:
    			if (elem=='/')
    				estado = 2;
    			else
    				estado = 0;
    			break;
		    case 2:
		    	if (elem=='/')
    				estado = 3;
    			else
    				estado = 0;
    			break;
    		case 3:
    			if (elem=='_')
    				estado = 4;
    			else
    				(elem=='/') ? estado = 3 : estado = 0;
    			break;
    		case 4:
    			if (elem=='\\')
    				estado = 5;
    			else
    				(elem=='/') ? estado = 1 : estado = 4;
    			break;
		    case 5:
		    	if (elem=='\\')
    				estado = 6;
    			else
    				(elem=='/') ? estado = 1 : estado = 0;
    			break;
    		case 6:
    			if(elem=='\\'){
    				cont++;
    				estado = 7;
    			} else
    				(elem=='/') ? estado = 1 : estado = 0;
    			break;
    		case 7:
    			if (elem=='\\')
    				estado = 7;
    			else
    				(elem=='/') ? estado = 1 : estado = 0;

		}
	}

	return cont;
}

int main() {
	int num_casos;
	cin >> num_casos;

	for (int i = 0; i < num_casos; ++i) {
		cin >> cadena;
		cout << analizar_cadena() << endl;
	}

	return 0;
}