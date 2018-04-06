// Obtiene el orden topologico de los nodos
// de un grafo dirigido. Orden ascendente
// respecto al numero de dependencias.
vector<bool> vis;
vector<int> ordenados;
void OrdenTopologico(int u) {
  vis[u] = true;
  for (int v : grafo[u])
    if (!vis[v]) OrdenTopologico(v);
  ordenados.push_back(u);
}

void OrdenTopologico() {
  ordenados.clear();
  vis = vector<bool>(NODOS);
  for (int u = 0; u < NODOS; ++u)
    if (!vis[u]) OrdenTopologico(u);
}