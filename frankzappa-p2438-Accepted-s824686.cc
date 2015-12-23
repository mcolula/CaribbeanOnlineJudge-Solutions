#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

map<int, string> person;
map<string, int> pnames;
int * marked;
int * values;
int mx;

typedef struct {
  int e;
  int v;
  vector< set<int> >vs;
} graph;

graph create(int n) {
  graph g;
  g.e = 0;
  g.v = n;
  g.vs = vector< set<int> >(n);
  for (int i = 0; i < n; i++)
    g.vs[i] = set<int>();
  return g;
}

void add_edge(graph * g, int u, int v) {
  g->vs[u].insert(v);
  g->vs[v].insert(u);
  g->e++;
}

int dfs(graph * g, int s) {
  marked[s] = true;
  for (auto &w: g->vs[s]) 
    if(!marked[w]) {
	  if (values[w] > values[mx])
	    mx = w;
	  dfs(g, w);
    }  
}

set<string> names(graph * g, int n) {
  set<string> names;
  for (int i = 0; i < n; i++) {
    if (!marked[i]) {
	  mx = i;
	  dfs(g, i);
	  names.insert(person[mx]);
	}
  }
  return names;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  string x;
  string y;
  int    a;
  while ((cin >> n >> q) && n != 0) {
    marked = new int[n]();
    values = new int[n]();
    graph g = create(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> a;
      person[i] = x;
      pnames[x] = i;
      values[i] = a;
    }
    while (q--) {
	  cin >> x >> y;
	  add_edge(&g, pnames[x], pnames[y]);
	}
	for (auto &name: names(&g, n))
	  cout << name << "\n";
    delete[] marked;
    delete[] values;
    pnames.clear();
    person.clear();
  }
  return 0;
}
