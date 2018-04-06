// Deteccion de puentes y puntos de articulacion
// en 1 grafo o multigrafo bidireccional.Los puentes
// quedan guardados en un vector de aristas. Los puntos
// de articulacion son marcados como true o false
// respectivamente en un vector de booleanos.
int tiempo;
vector<int> label, low;
vector<Arista> puentes; // <- Resultado
vector<bool> articulacion; // <- Resultado
int PuentesArticulacion(int u, int p) {
  label[u] = low[u] = ++tiempo;
  int hijos = 0, retorno = 0;
  for (int v : grafo[u]) {
    if (v == p && !retorno++) continue;
    if (!label[v]) {
      ++hijos; PuentesArticulacion(v, u);
      if (label[u] <= low[v])
        articulacion[u] = true;
      if (label[u] <  low[v])
        puentes.push_back(Arista(u, v));
      low[u] = min(low[u], low[v]);
    }
    low[u] = min(low[u], label[v]);
  }
  return hijos;
}

void PuentesArticulacion() {
  low = vector<int>(NODOS);
  label = vector<int>(NODOS);
  tiempo = 0, puentes.clear();
  articulacion = vector<bool>(NODOS);
  for (int u = 0; u < NODOS; ++u)
    if (!label[u])
      articulacion[u] = PuentesArticulacion(u, NODOS) > 1;
}