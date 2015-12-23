#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
  int  * sz;
  int  * id;
  int count;
} UnionFind;


UnionFind create(int n) {
  UnionFind u;
  u.sz = new int[n];
  u.id = new int[n];
  for (int i = 0; i < n; i++) {
    u.id[i] = i;
    u.sz[i] = 1;
  }
  u.count = n;
  return u; 
}

int find(UnionFind * u, int p) {
  int q = p;
  while (q != u->id[q])
    q = u->id[q];
  return q;
}

bool connected(UnionFind * u, int p, int q) {
  return find(u, p) == find(u, q);
}

void connect(UnionFind * u, int p, int q) {
  int rootP = find(u, p);
  int rootQ = find(u, q);
  if (rootQ == rootP) return;
  if (u->sz[rootP] < u->sz[rootQ]) {
    u->id[rootP] = rootQ;
    u->sz[rootQ] += u->sz[rootP];
    u->count--;
  }
  else {
    u->id[rootQ] = rootP;
    u->sz[rootP] += u->sz[rootQ];
    u->count--;
  }
}

typedef struct {
  int u;
  int v;
  int w;
} edge;

edge init(int u, int v, int w) {
  edge e;
  e.u = u;
  e.v = v;
  e.w = w;
  return e;
}

bool operator <(const edge & e, const edge & f) { return e.w < f.w; }

int cost(priority_queue<edge> pq, int n) {
  UnionFind u = create(n);
  int mst = 0;
  int cst = 0;
  edge e;
  while(!pq.empty() && mst < n - 1) {
    e = pq.top();
    pq.pop();
    if(!connected(&u, e.u - 1, e.v - 1)) {
      mst += 1;
      cst += e.w;
      connect(&u, e.u - 1, e.v - 1);
    }
  }
  return u.count == 1 ? cst : - 1;
}

int main() {
  int n, t;
  int u, v, w;
  cin >> n >> t;
  priority_queue<edge> pq;
  while (t--) {
    cin >> u >> v >> w;
    pq.push(init(u, v, w));
  }
  cout << cost(pq, n) << endl;  
  return 0;
}
