// Algoritmo de dijkstra desde el nodo s.
// Devuelve el vector de distancias a todos
// los nodos desde s. Un valor INF indica que
// no es posible ir de s al respectivo nodo.
Costo dist[MAXN];
void Dijkstra(int s) {
  for( int i = 0; i < NODOS; i++ ) dist[i] = INF;
  priority_queue<CostoNodo> pq;
  pq.push(CostoNodo(0, s)), dist[s] = 0;
  while (!pq.empty()) {
    Costo p = -pq.top().first;
    int u = pq.top().second; pq.pop();
    if (dist[u] < p) continue;
    for (CostoNodo arista : grafoCosto[u]) {
      int v = arista.second;
      p = dist[u] + arista.first;
      if (p < dist[v]) dist[v] = p, 
        pq.push(CostoNodo(-p, v));
    }
  }
}