#include <iostream>
#include <math.h>	// Function trunc()

using namespace std;

/**
 * Linea de entrada de la forma: c k x
 *	- c: Longitud de la circunferencia
 *	- k: Longitud del cilindro
 *	- x: Vueltas que la cuerda da al cilindro
**/

/**
 *       ____________	           _____________
 * 3D: ()__)__)__)__() 	=>  2D: ()|\_\_\_\_\_\_\|()
 *
 * Viendo la figura en dos dimensiones:
 *  	   ︵	 _____________________    ︵
 * 		 (    ) |\  \  \  \  \  \  \  | (    )
 * 	    (      )| \	 \  \  \  \  \  \ |(      )
 * 		 (    ) |__\__\__\__\__\__\__\| (    )
 *		   ︶		    		          ︶
 *	Vemos que para la primera o para la ultima linea podemos aplicar el teorema de Pitagoras consiguiendo asi su hipotenusa
 *		- Una vez que tenemos esa longitud, simplemente debemos multiplicarla por el numero de vueltas que da la cuerda para tener
 *		  la longitud total
 *		- Para aplicar el T.Pit: necesitamos calcular la longitud de sus dos catetos:
 *		
 *				  ᴧ |\
 *				  | | \			h1: Es el diametro de la circunferencia
 *			   h1 | |  \		
 *				  | |   \		h2: Se calcula dividiendo la longitud del cilindro entre el numero de vueltas de la cuerda
 *				  v |____\
 *					<---->
 *					  h2
 *	
**/	

int main() {
	int num_casos;
	cin >> num_casos;

	int c,k,x;
	double hipotenusa;
	for (int i = 0; i < num_casos; ++i) {
		cin >> c >> k >> x;
		hipotenusa = sqrt(pow(c, 2) + pow(double(k/x), 2));
		cout << trunc(x*hipotenusa) << endl;
	}

	return 0;
}