#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> marble;

int binaria( int val ){
	int ini = 0, fin = marble.size()-1, mid, res = -1;
	while( ini <= fin ){
		mid = ( ini + fin )/2;
		if( marble[mid] == val ){
			res = mid;
			fin = mid-1;
		}
		if( marble[mid] < val )
			ini = mid+1;
		if( marble[mid] > val )
			fin = mid-1;
	}
	return res;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int casos = 1, N, Q, querie, res;
	while( 1 ){
		cin >> N >> Q;
		if( !N && !Q ) break;

		cout << "CASE# "<< casos++ <<":\n";
		marble = vector<int>(N);

		for( int i = 0; i < N; i++ ){
			cin >> marble[i];
		}

		sort( marble.begin(), marble.end() );

		for( int i = 0; i < Q; i++ ){
			cin >> querie;
			res = binaria( querie );
			if( res == -1 ){
				cout << querie << " not found\n";
			}
			else{
				cout << querie << " found at " << res+1 << '\n';
			}
		}
	}
	return 0;
}