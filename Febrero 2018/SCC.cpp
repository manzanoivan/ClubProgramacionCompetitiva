// Deteccion de componentes fuertemente conexas
// en un grafo dirigido. Las componentes quedan
// guardadas en un vector de vectores, donde
// cada vector interno contiene los nodos
// de una componente fuertemente conexa.
vector<vector<int>> scc; // <- Resultado
int top; vector<int> pila;
void FuertementeConexo(int u) {
  label[u] = low[u] = ++tiempo;
  pila[++top] = u;
  for (int v : grafo[u]) {
    if (!label[v]) FuertementeConexo(v);
    low[u] = min(low[u], low[v]);
  }
  if (label[u] == low[u]) {
    vector<int> componente;
    while (pila[top] != u) {
      componente.push_back(pila[top]);
      low[pila[top--]] = NODOS + 1;
    }
    componente.push_back(pila[top--]);
    scc.push_back(componente);
    low[u] = NODOS + 1;
  }
}
 
void FuertementeConexo() {
  low = vector<int>(NODOS);
  label = vector<int>(NODOS);
  tiempo = 0, scc.clear();
  top = -1, pila = vector<int>(NODOS);
  for (int u = 0; u < NODOS; ++u)
    if (!label[u]) FuertementeConexo(u);
}
