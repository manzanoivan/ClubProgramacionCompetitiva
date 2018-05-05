#define MAXV 105
#define LOGV 10
#define mp make_pair
using namespace std;
int level[ MAXV ], parent[ MAXV ], N;
int P[ MAXV ][ LOGV ], maximo[ MAXV ][ LOGV ], peso[ MAXV ]; 

void PRE(){
	for(int u = 0; u < N; u++){
		P[u][0] = parent[u];
		maximo[u][0] = peso[u];
	}
	for(int i = 1; (1 << i) <= N; i++){
		for(int u = 0; u < N; u++){
			P[u][i] = P[P[u][i-1]][i-1];
			maximo[u][i] = max( maximo[u][i - 1],
						maximo[P[u][i - 1]][i - 1] );
		}
	}
}
int LCA(int p , int q){
	if(level[p] < level[q]) swap(p,q);
	int lg;
	for( lg = 1 ; (1 << lg) <= level[p] ; ++lg );
		lg--;
	int maxi = 0;
	for( int i = lg ; i >= 0 ; i--){
		if( level[p] - (1 << i) >= level[q] ){
			maxi = max( maxi, maximo[p][i] );
			p = P[p][i];
		}
	}
	if( p == q ) return maxi;
 
	for( int i = lg ; i >= 0 ; i-- ){
		if( P[p][i] != -1 && P[p][i] != P[q][i]){
			maxi = max( maxi, max( maximo[q][i], maximo[p][i] ));
			p = P[p][i];
			q = P[q][i];
		}
	}
	maxi = max(max( maximo[p][0], maxi ) , maximo[q][0]);
	return maxi;
}