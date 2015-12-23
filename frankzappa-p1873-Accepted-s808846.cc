#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int  * distTo;
bool * marked;

void init(int n) {
  distTo = new int[n]();
  marked = new bool[n]();
  fill_n(distTo, n, -1);
}

typedef struct {
  int vcount;
  int ecount;
  vector< set<int> > vertices;
} graph;

graph create(int n) {
  graph g;
  g.vcount = n;
  g.ecount = 0;
  g.vertices = vector< set<int> >(n);
  for (int i = 0; i < n; i++)
    g.vertices[i] = set<int>();
  return g;
}

void add_edge(graph * g, int u, int v) {
  g->ecount++;
  g->vertices[u].insert(v);
}

set<int> adjacent(graph * g, int v) {
  return g->vertices[v];
}

void bfs(graph * g, int s) {
  queue<int>  q;
  distTo[s] = 1;
  marked[s] = true;
  q.push(s);
  int v = 0;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (auto &u: adjacent(g, v)) {
      if (!marked[u]) {
        marked[u] = true;
        distTo[u] = distTo[v] + 1;
        q.push(u);
      }
    }
  }
}


int main() {
  int t, n, l, q, u, v;
  scanf("%d", &t);  
  graph site;
  while (t--) {
    scanf("%d %d %d", &n, &l, &q);
    site = create(n);
    init(n);
    while (l--) {
      scanf("%d %d", &u, &v);
      add_edge(&site, u - 1, v - 1);
    }
    bfs(&site, 0);
    while (q--) {
      scanf("%d", &u);
      printf("%d\n", distTo[u - 1]);
    }
    site.vertices.clear();
    delete[] marked;
    delete[] distTo;
  }
  return 0;
}
