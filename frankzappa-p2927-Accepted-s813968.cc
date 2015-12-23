#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool bip = true;
bool * marked;
bool * color;

typedef struct {
  int ecount;
  int vcount;
  vector< set<int> > vertice;
} graph;


graph create(int n) {
  graph g;
  g.vcount = n;
  g.ecount = 0;
  g.vertice = vector< set<int> >(n);
  for (int i = 0; i < n; i++)
    g.vertice[i] = set<int>();
  marked = new bool[n]();
  color = new bool[n]();
  return g;
}

void add_edge(graph * g, int u, int v) {
  g->vertice[u].insert(v);
  g->vertice[v].insert(u);
  g->ecount++;
}

void dfs(graph * g, int v) {
  marked[v] = true;
  if (!bip) return;
  for (auto &w: g->vertice[v])
    if (!marked[w]) {
	  color[w] = !color[v];
	  dfs(g, w);
	}
	else if (color[w] == color[v])
	  bip = false;
}

bool bipartite(graph * g) {
  for (int v = 0; v < g->vcount; v++)
    if (!marked[v])
      dfs(g, v);
  return bip;
}

int main() {
  int n, t;
  int u, v;
  cin >> n;
  cin >> t;
  graph g = create(n);
  while (t--) {
    cin >> u >> v;
    add_edge(&g, u - 1, v - 1);
  }
  if (bipartite(&g))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
} 


