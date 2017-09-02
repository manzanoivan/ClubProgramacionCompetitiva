#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Criba de Eratostenes de 1 a n.
vector<int> Criba(int n) {
	int raiz = sqrt(n);
	vector<int> criba(n + 1);
	for (int i = 4; i <= n; i += 2)
		criba[i] = 2;
	for (int i = 3; i <= raiz; i += 2)
		if (!criba[i])
			for (int j = i * i; j <= n; j += i)
				if (!criba[j]) criba[j] = i;
	return criba;
}

int main(){
	vector<int> criba = Criba(100);
	vector<int> primos;
	for( int i = 0; i < 100; i++ ){
		if( criba[i] == 0 ) primos.push_back( i );
	}

	for( int i = 2; i < primos.size(); i++ )
		cout << primos[i] << endl;
	return 0;
}