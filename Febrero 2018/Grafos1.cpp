#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Arista;

const int MAXN = 100020; //Número máximo de nodos
int NODOS = 0; //Lleva el número de nodos del grafo actual
const bool bi = true; //Variable que indica si el grafo es bidireccional o dirigido

vector<int> grafo[MAXN]; //Lista de adyacencia que representa el grafo
int degree[MAXN]; //Conteo del degree para grafos bidireccionales

//Función para agregar una arista de u a v. Si bi es true, se agrega la arista opuesta.
void AgregarArista(int u, int v){
	if( bi ) grafo[v].push_back(u), degree[v]++;
	grafo[u].push_back(v); degree[u]++;
}

//Arreglo para saber si un nodo ha sido visitado.
int vis[MAXN];

//Función que reinicia el grafo. Se debe mandar a llamar antes de hacer un nuevo caso.
void Limpia(){
	for( int i = 0; i < MAXN; i++ ){
		grafo[i].clear();
		degree[i] = 0;
	}
}


//Búsqueda en profundidad, se debe limpiar el arreglo vis antes de mandar a llamarla
void DFS( int s ){
	vis[s] = 1;
	for( auto u : grafo[s] )
		if( vis[u] == -1 )
			DFS(u);
}

//Búsqueda en amplitud, se debe limpiar el arreglo vis antes de mandar a llamarla, en vis se guarda la distancia mínima desde el nodo s.
void BFS( int s ){
	queue<int> q;
	q.push(s); vis[s] = 0;
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		for( int v : grafo[u] )
			if( vis[v] == -1 ) 
				vis[v] = vis[u]+1, q.push(v);
	}
}

int main(){
	int N, M, x, y;
    cin >> N >> M;
    NODOS = N;

    for( int i = 0; i < N; i++ ) vis[i] = -1;

    for(  int i = 0; i < M; i++){
    	cin >> x >> y;
    	AgregarArista(--x, --y);

    }

    cin >> x;

    BFS( --x );

    int suma = 0;
    for( int i = 0; i < N; i++ ){
        if( vis[i] == -1 ) suma++;
    }

    cout << suma << '\n';
    return 0;
}