#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

// Estructura que almacenara para un caracter 'c' un array en el cual estan sus posiciones en las que aparece en la cadena
// El orden de aparicion del array se corresponde con el de la cadena
struct item {
	char elem;
	vector< short int > posiciones;
};

vector< item > info;	// vector que estara indexado segun el orden de los caracteres ASCII desde el 32(' ') hasta el 126('~')
						// Por esto, info[0] contendra la informacion asociada al caracter <espacio> y info[93] al de '~'

set< char > registrado;


/**
 * Cuando leemos el caracter i-esimo hay dos posibilidades:
 * 1- Es la primera vez que leemos este caracter y debemos insertar su informacion en nuestra estructura de datos
 *    y seguimos avanzando en la cadena
 *
 * 2- Comprobamos que registrado.find(elem_actual) != registrado.end() y entonces tenemos que comprobar para todas
 * 	  las posiciones en la que aparece ese caracter cuantos caracteres seguidos se repiten. Por ultimo, anadimos en
 *	  la lista de posiciones en las que aparece este caracter el de la posicion actual
**/

char cadena[1001];	// array de caracteres que contiene la cadena a analizar
char elem_actual;	// elemento actual que estamos tratando
int indice;			// variable que nos indica el indice del array 'info' donde esta almacenada la informacion de este caracter

struct pareja {
	int max;	// La longitud de la cadena mas larga
	int pos;	// La posicion de donde comienza la cadena (la primera de las dos)
};
pareja comprobar_repeticion(int p) {
	pareja sol;
	sol.max = 1;	// Como minimo va a haber un caracter igual
	int posicion;
	int pos_comprobar;
	int cont;

	for (int i = 0; i < info[indice].posiciones.size(); ++i) {
		posicion = p;
		pos_comprobar = info[indice].posiciones[i];
		cont = 1;	// El contador empieza en uno ya que el elemento actual obviamente es igual
		while ((cadena[posicion+1]) && (cadena[posicion+1] == cadena[pos_comprobar+1])){
			posicion++;
			pos_comprobar++;
			cont++;
		}
		if (cont > sol.max){
			sol.max = cont;
			sol.pos = info[indice].posiciones[i];
		}

	}
	return sol;
}


int main() {

	int num_casos;
	int maximo;
	int posicion;

	cin >> num_casos;
	cin.ignore(); // para ignorar el '\n' despues del numero de casos

	for (int i = 0; i < num_casos; ++i) {
		cin.getline(cadena, 1001, '\n');	// Leemos toda la cadena de la entrada

		registrado.clear();
		info.clear();
		info.resize(94);	// Inicializamos las 94 posiciones del array

		maximo = 0;
		posicion = 0;

		int pos;
		for (pos = 0; cadena[pos]; ++pos) {
			elem_actual = cadena[pos];
			indice = (int)elem_actual - 32;	// Indice del array al que corresponde el caracter actual
			
			if (registrado.find(elem_actual) == registrado.end()) {
				// No hemos registrado aun este caracter
				//cout << "registar:" << elem_actual << endl;
				registrado.insert(elem_actual);
				item nuevo;
				nuevo.elem = elem_actual;
				nuevo.posiciones.push_back(pos);
				info[indice] = nuevo;	// Insertamos en 'info' el item

			} else {
				//cout << "buscar maximo de:" << elem_actual;
				pareja aux = comprobar_repeticion(pos);
				//cout << " longitud cadena maxima repetida:" << aux << endl;
				if (aux.max > maximo) {
					maximo = aux.max;
					posicion = aux.pos;
				} else if((aux.max == maximo) && (aux.pos < posicion))
					posicion = aux.pos;
				info[indice].posiciones.push_back(pos);	// Insertamos la nueva posicion en la que aparece el caracter actual
			}
		}

		//cout << "pos:" << posicion << " max:" << maximo << endl;
		for (int k = posicion; k < (posicion+maximo); ++k)
			cout << cadena[k];
		cout << endl;
	}

	return 0;
}