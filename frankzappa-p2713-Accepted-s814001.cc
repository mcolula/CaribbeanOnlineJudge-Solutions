#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool * marked;
int  * distTo;

typedef struct {
  int vcount;
  int ecount;
  vector< set<int> > vertice;
} graph;

void init(int n) {
  marked = new bool[n]();
  distTo = new  int[n]();
  fill_n(distTo, n, -1);
}

graph create(int n) {
  graph g;
  g.vcount = n;
  g.ecount = 0;
  g.vertice = vector< set<int> >(n);
  for (int i = 0; i < n; i++)
    g.vertice[i] = set<int>();
  return g;
}

void add_edge(graph * g, int u, int v) {
  g->vertice[u].insert(v);
  g->ecount++;
}

void bfs(graph * g, int s) {
  marked[s] = true;
  distTo[s] = 1;
  queue<int> q;
  q.push(s);
  int v;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (auto &w: g->vertice[v])
      if (!marked[w]) {
	    distTo[w] = distTo[v] + 1;
	    marked[w] = true;
	    q.push(w);
	  }
  }
}

int main() {
  int n, t, u, v, q, e;
  graph  g;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &e, &q);
    init(n);
    g = create(n);
    while (e--) {
	  scanf("%d %d", &u, &v);
	  add_edge(&g, u - 1, v - 1);
	}
	bfs(&g, 0);
	while (q--) {
	  scanf("%d", &u);
	  printf("%d\n", distTo[u - 1]); 
	}
    delete[] marked;
    delete[] distTo;
    g.vertice.clear();
  }
}
