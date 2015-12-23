#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool * marked;

typedef struct {
  int ecount;
  int vcount;
  vector< set<int> >vertice;
} graph;

graph create(int n) {
  graph g;
  g.ecount = 0;
  g.vcount = n;
  g.vertice = vector< set<int> >(n);
  for (int i = 0; i < n; i++)
    g.vertice[i] = set<int>();
  return g;
}

void add_edge(graph * g, int v, int w) {
  g->vertice[v].insert(w);
  g->ecount++;
}

int bfs(graph * g, int s) {
  priority_queue<int> pq;
  marked[s] = true;
  int knock = 1;
  pq.push(s);
  int v;
  while (!pq.empty()) {
    v = pq.top();
    pq.pop();
    for (auto &w: g->vertice[v])
      if (!marked[w]) {
	    marked[w] = true;
	    pq.push(w);
	    knock++;
	  }
  }
  return knock;
}

int main() {
  int t, n, m, l, u, v, total;
  scanf("%d", &t);
  graph g;
  while (t--) {
    scanf("%d %d %d", &n, &m, &l);
    g = create(n);
    marked = new bool[n]();
    while (m--) {
	  scanf("%d %d", &u, &v);
	  add_edge(&g, u - 1, v - 1);
	}
	total = 0;
	while (l--) {
	  scanf("%d", &u);
	  if (!marked[u - 1])
	    total += bfs(&g, u - 1);
	}
	printf("%d\n", total);
    g.vertice.clear();
    delete[] marked;
  }
}
