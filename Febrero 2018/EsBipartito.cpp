// Determina si un grafo bidireccional
// es bipartito (o bien, es bicoloreable).
bool EsBipartito() {
  vector<char> color(NODOS, -1);
  for (int u = 0; u < NODOS; ++u) {
    if (color[u] >= 0) continue;
    color[u] = 0;
    queue<int> q; q.push(u);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : grafo[u]) {
        if (color[v] < 0) q.push(v), 
             color[v] = 1 - color[u];
        if (color[u] == color[v])
          return false;
      }
    }
  }
  return true;
}