#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int mdist = 0; // Max distance from source
int  * distTo;
bool * marked;
 
void init(int n) {
  distTo = new int[n]();
  marked = new bool[n]();
}

typedef struct {
  int vcount;
  int ecount;
  vector < set<int> > vertice;
} graph;

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
  g->vertice[v].insert(u);
}

void bfs(graph * g, int s) {
  marked[s] = true;
  distTo[s] = 0;
  queue<int>  q;
  q.push(s);
  int v = 0;
  while (!q.empty()) {
	v = q.front();
	q.pop();
    for (auto &w : g->vertice[v])
	  if (!marked[w]) {
	    q.push(w);
	    marked[w] = true;
	    distTo[w] = distTo[v] + 1;
	    mdist = max(mdist, distTo[w]);
	  }
  }
}

pair<int, int> find(int n) {
  int f = 0;
  int count = 0;
  bool first = true;
  for (int i = 0; i < n; i++)
    if (distTo[i] == mdist) {
	  if(first) {
	    f = i;
	    first = false;
	  }
	  count++;
	}
  return make_pair(f, count);
}


int main() {
  int t, n, k, a, b;
  pair <int, int> z;
  cin >> t;
  graph  g;
  while (t--) {
    cin >> n >> k;
    g = create(n);
    while (k--) {
	  cin >> a >> b;
	  add_edge(&g, a - 1, b - 1);
	}
	init(n);
	bfs(&g,  0);
	z = find(n);
	cout << z.first + 1 << " " << mdist << " " << z.second << endl; 
    mdist = 0;
    delete[] distTo;
    delete[] marked;
    g.vertice.clear();
  }
  return 0;
}
