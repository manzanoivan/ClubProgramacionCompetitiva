// Detecta ciclos en un grafo o multigrafo.
// Llamar a DetectarCiclos() devuelve un
// vector de vectores; cada vector interno es
// una lista que representa un ciclo del grafo.
// NOTA: Solo detecta un ciclo por componente.
vector<int> ciclo;
char color[MAXN];
void DetectarCiclo(int u, int p) {
  int retorno = bi? 0: 1;
  color[u] = ciclo.empty()? 'G': 'N';
  for (int v : grafo[u]) {
    if (v == p && !retorno++) continue;
    if (ciclo.empty() && color[v] == 'G') {
      color[v] = 'A', ciclo.push_back(v);
      if (u != v) color[u] = 'R', ciclo.push_back(u);
    }
    if (color[v] != 'B') continue; DetectarCiclo(v, u);
    if (color[u] == 'G' && color[v] == 'R')
      color[u] = 'R', ciclo.push_back(u);
  }
  if (color[u] == 'G') color[u] = 'N';
}
vector<vector<int>> DetectarCiclos() {
  vector<vector<int>> ciclos;
  for( int i = 0; i < MAXN; i++ ) color[i] = 'B';
  for (int u = 0; u < NODOS; ++u) {
    if (color[u] != 'B') continue;
    ciclo.clear(); DetectarCiclo(u, NODOS);
    reverse(ciclo.begin(), ciclo.end());
    if (!ciclo.empty())
      ciclos.push_back(ciclo);
  }
  return ciclos;
}