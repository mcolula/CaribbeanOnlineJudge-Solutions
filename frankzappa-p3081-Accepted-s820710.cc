#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool * marked;
bool * colour;

typedef struct {
  int ecount;
  int vcount;
  vector< set<int> > vertice;
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

void add_edge(graph * g, int u, int v) {
  g->vertice[u].insert(v);
  g->vertice[v].insert(u);
  g->ecount++;
}

void init(int n) {
  marked = new bool[n]();
  colour = new bool[n]();
}

bool dfs(graph * g, int s) {
  marked[s] = true;
  colour[s] = true;
  queue<int>  q;
  q.push(s);
  int v;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (auto &w: g->vertice[v]) {
	  if (!marked[w]) {
	    marked[w] = true;
	    colour[w] = !colour[v];
	    q.push(w);
	  } 
	  else if(colour[v] == colour[w])
	    return false;
	}
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, e;
  int u, v;
  graph  g;
  while ((cin >> n >> e) && n != 0){
    init(n);
    g = create(n);
    while (e--) {
      cin >> u >> v;
      add_edge(&g, u, v);
    }
    if (dfs(&g, 0))
      cout << "BICOLORABLE.\n";
    else
      cout <<"NOT BICOLORABLE.\n";
    delete[] marked;
    delete[] colour;
  }
  return 0;
}

