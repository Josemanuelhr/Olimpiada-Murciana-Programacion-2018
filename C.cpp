#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector< vector< char > > pared;

struct post_it {
	char e;
	int inicio;
	int fila_inicial;
};

vector< post_it > info;
set< char > registrados;

struct borrar {
	int inicio, final;
	int fila_inicial, profundidad;
	int pos;
};

vector< borrar > post_it_borrar;

vector< string > solucion;

int H,W;
char elem_actual;

int inicio, final = 0;	// Posiciones en las que se inicia y acaba una linea correspondiente a un post-it
int fila_inicial, profundidad = 0;	// Numero de fila inicial donde comienza el post-it

/**
 * Automata para buscar el final de la cadena:
 *	- Estado0: (char == char_actual) ? estado0 : estado1;
 *	- Estado1: (char != char_actual) ? estado1 : estado2;
 *	- Estado2: return -1;
 *
**/
int estado = 0;
int buscar_final(post_it p, int pos) {
	bool correcto = true;
	estado = 0;
	int j = p.inicio;
	int cont = p.inicio;
	while ((j<W) && (correcto)) {
		switch (estado) {
			case 0:
				if (pared[pos][j] == p.e)
					cont++;
				else
					estado = 1;
				break;
			case 1:
				if (pared[pos][j] == p.e)
					estado = 2;
				break;
			case 2:
				correcto = false;
				break;
		}
		j++;
	}
	if (correcto)
		return cont-1;	// ya que se empieza por la posicion inicial entonces hay que restarle 1
	else
		return -1;
}

int buscar_profundidad(post_it p, int pos) {
	bool correcto = true;
	estado = 0;
	int i = p.fila_inicial;
	int cont = p.fila_inicial;
	while ((i<H) && (correcto)) {
		switch (estado) {
			case 0:
				if (pared[i][pos] == p.e)
					cont++;
				else
					estado = 1;
				break;
			case 1:
				if (pared[i][pos] == p.e)
					estado = 2;
				break;
			case 2:
				correcto = false;
				break;
		}
		i++;
	}
	if (correcto)
		return cont-1;	// ya que se empieza por la posicion inicial entonces hay que restarle 1
	else
		return -1;
}

int recalcular_inicio(post_it p) {
	int limi = p.inicio;
	int min = p.inicio;
	for (int i = p.fila_inicial; i < H ; ++i) {
		while ((limi > 0) && (pared[i][limi-1] == p.e))
			limi--;
		if (limi < min)
			min = limi;
	}
	return limi;
}

bool comprobar_entero() {
	bool entero = true;	// suponemos que esta entero
	bool punto;	// para detectar la aparicion del caracter '.'
	bool punto_todos;	// para detectar si la linea entera esta formada por puntos
	int i = fila_inicial;	// si estamos comprobando que esta entero es porque hemos encontrado que en la primera linea que aparece no hay problemas
	int j;
	if (i == H)
		return true;
	else {
		do {
			if(((inicio == 0) || (pared[i][inicio-1] != elem_actual)) && ((final == W-1) || (pared[i][final+1] != elem_actual))) {
				j = inicio;
				punto = false;
				punto_todos = false;
				do {
					if (!((pared[i][j] == elem_actual) || (pared[i][j] == '.')))
						entero = false;
					j++;
				} while (entero && (j<=final));
			} else {
				entero = false;
			}
			i++;
		} while(entero && (i<=profundidad) && (!punto_todos));

		return entero;
	}
}

int main() {

	int num_casos;
	cin >> num_casos;

	char elem;
	for (int k = 0; k < num_casos; ++k) {
		cin >> H >> W;
		pared.clear();
		pared.resize(H);
		info.clear();
		registrados.clear();
		solucion.clear();
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j){
				cin >> elem;
				pared[i].push_back(elem);
				if ((elem != '.') && (registrados.find(elem) == registrados.end())) {
					post_it a;
					a.fila_inicial = i;
					a.inicio = j;
					a.e = elem;
					info.push_back(a);
					registrados.insert(elem);
				}
			}

		//cout << endl << "Pared leida:" << endl << endl;

		/*for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j)
				cout << pared[i][j];
			cout << endl;
		}*/

		//cout << endl << "Informacion de 'info'" << endl << endl;

		/*for (int i = 0; i < info.size(); ++i)
			cout << "e:" << info[i].e << " inicio:" << info[i].inicio << " fila_inicial:" << info[i].fila_inicial << endl;

		cout << endl << "Busquedas" << endl << endl;*/

		bool sin_solucion = false;
		bool fin = false;
		do {

			/*for (int i = 0; i < H; ++i) {
				for (int j = 0; j < W; ++j)
					cout << pared[i][j];
				cout << endl;
			}*/

			// Buscamos de entre todos los post_its los que pertenezcan al nivel X
			post_it_borrar.clear();
			int i;
			string sol = "";
			for (i = 0; i < info.size(); ++i) {
				int max = -1;
				for (int val = 0; val < (H-info[i].fila_inicial) ; ++val){
					final = buscar_final(info[i], info[i].fila_inicial+val);
					if (final > max)
						max = final;
				}
				final = max;

				max = -1;
				for (int val = 0; val <= (final-info[i].inicio) ; ++val){
					profundidad = buscar_profundidad(info[i], info[i].inicio+val);
					if (profundidad > max)
						max = profundidad;
				}
				profundidad = max;
				if ((final != -1) && (profundidad != -1)) {
					inicio = info[i].inicio;
					fila_inicial = info[i].fila_inicial;
					elem_actual = info[i].e;
					//cout << "elemento actual:" << elem_actual << " inicio:" << inicio << " final:" << final << " fila:" << fila_inicial << " profundidad:" << profundidad << endl;
					if (comprobar_entero()){
						sol += elem_actual;
						borrar nuevo;
						nuevo.inicio = inicio;
						nuevo.final = final;
						nuevo.fila_inicial = fila_inicial;
						nuevo.profundidad = profundidad;
						nuevo.pos = i;
						post_it_borrar.push_back(nuevo);
						//cout << info[i].e << " es un post-it de nivel 1" << endl;
					}
				}
			}
			//cout << "sol:" << sol << endl;
			sort(sol.begin(), sol.end());
			solucion.push_back(sol);

			if (post_it_borrar.size() == 0)
				sin_solucion = true;

			// Rellenamos con '.' los post_its que ya hemos analizado
			for (int val = 0; val < post_it_borrar.size(); ++val) {
				for (int posi = post_it_borrar[val].fila_inicial; posi <= post_it_borrar[val].profundidad; ++posi)
					for (int posj = post_it_borrar[val].inicio; posj <= post_it_borrar[val].final; ++posj){
						pared[posi][posj] = '.';
					}
				info.erase(info.begin() + post_it_borrar[val].pos - val);	// -val porque son los elementos que ya han sido eliminados
			}
			

			if (info.size() == 0)
				fin = true;

			for (int val = 0; val < info.size(); ++val){
				info[val].inicio = recalcular_inicio(info[val]);
			}

		} while (!(fin) && !(sin_solucion));

		cout << "Case " << k+1 << endl;
		if (sin_solucion)
			cout << "No solution" << endl;
		else
			for (int i = 0; i < solucion.size(); ++i) {
				cout << solucion[i][0];
				for(int pos = 1; pos < solucion[i].length(); ++pos)
					cout << " " << solucion[i][pos];
				cout << endl;
			}
	}
 
	return 0;
}
