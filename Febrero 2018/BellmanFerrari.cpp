// Algoritmo de Bellman-Ford optimizado, desde
// el nodo s. Devuelve un booleano indicando si
// existe un ciclo negativo en un digrafo.
// Obtiene el vector de distancias a todos.
Costo dst[MAXN]; // <- Resultado
bool BellmanFerrari(int s) {
  queue<int> q;
  vector<bool> en_cola(NODOS);
  vector<int> procesado(NODOS);
  for( int i = 0; i < NODOS; i++ ) dst[i] = INF;
  q.push(s), dst[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), en_cola[u] = false;
    if (++procesado[u] == NODOS) return true;
    for (CostoNodo arista : grafoCosto[u]) {
      int v = arista.second;
      Costo p = arista.first;
      if (dst[u] + p < dst[v]) {
        if (!en_cola[v]) q.push(v);
        dst[v] = dst[u] + p;
        en_cola[v] = true;
      }
    }
  }
  return false;
}