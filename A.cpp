#include <iostream>

using namespace std;

int n1, n2, n3, n4;

// A continuacion la funciones correspondientes para detectar cada caso

bool fibonacci() {
	bool cond1 = (n1+n2)==n3;
	bool cond2 = (n2+n3)==n4;
	return (cond2 && cond1);
}

bool add_constant() {
	int val1 = n2-n1;
	int val2 = n3-n2;
	int val3 = n4-n3;

	return ((val1==val2) && (val2==val3));
}

bool add_more() {
	int val1 = n2-n1;
	int val2 = n3-n2;
	int val3 = n4-n3;

	return (((val1+1)==val2) && ((val2+1)==val3));
}

bool multiply_constant() {
	double val1 = (double)n2/n1;
	double val3 = (double)n3/n2;
	double val2 = (double)n4/n3;

	return ((val1==val2) && (val2==val3));
}

int main() {
	int n_casos;
	cin >> n_casos;
	for (int i = 0; i < n_casos; ++i) {
		cin >> n1 >> n2 >> n3 >> n4;

		if (add_constant())
			cout << (n4 + (n4-n3)) << endl;
		else if (add_more())
			cout << (n4 + (n4-n3+1)) << endl;
		else if (fibonacci())
			cout << (n3+n4) << endl;
		else if ((n2==0) && (n2==n3) && (n3==n4))	// Si la constante multiplicativa es 0 => no podemos usar la funcion 'multiply_constant()'
			cout << 0 << endl;						// Lo comprobamos 'a mano'
		else if (multiply_constant()) {
			double div = (double)n4/n3;
			cout << (int)n4*div << endl;
		} else
			cout << 42 << endl;
	}

	return 0;
}