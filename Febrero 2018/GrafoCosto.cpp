const int MAXN = 200020;
int NODOS = 0;
typedef int Costo;
const Costo INF = 1 << 30;
typedef pair<Costo, int> CostoNodo;
vector<CostoNodo> grafoCosto[MAXN];
const bool bi = true;
// Grafos con ponderacion.
// Nodos indexados de 0 a n - 1.
// bi = true -> Bidireccional.
// bi = false -> Dirigido.

struct Ponderada{
  int x, y;
  Costo c;
  Ponderada(){}
  Ponderada(int x_, int y_, Costo c_) : x(x_), y(y_), c(c_) {}
  bool operator<(const Ponderada& q) const {
    return c < q.c;
  }
};

void AgregarArista(int u, int v, Costo c) {
  if (bi) grafoCosto[v].push_back(CostoNodo(c, u));
  grafoCosto[u].push_back(CostoNodo(c, v));
}

void limpia(){
  for( int i = 0; i < NODOS; i++ )
    grafoCosto[i].clear();
}