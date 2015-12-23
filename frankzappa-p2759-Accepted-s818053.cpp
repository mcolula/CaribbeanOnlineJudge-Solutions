#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

typedef struct {
  int *  id;
  int *  sz;
  int count;
} UnionFind;

UnionFind createUF(int n) {
  UnionFind u;
  u.count = n;
  u.sz = new int[n]();
  u.id = new int[n]();
  for (int i = 0; i < n; i++) {
    u.sz[i] = 1;
    u.id[i] = i;
  }
  return u;
}

int find(UnionFind * u, int p) {
  int n = p;
  while (n != u->id[n]) {
    u->id[n] = u->id[u->id[n]];
    n = u->id[n];
  }
  return n;
}

bool connected(UnionFind * u, int p, int q) {
  return find(u, p) == find(u, q);
}

void connect(UnionFind * u, int p, int q) {
  int rootP = find(u, p);
  int rootQ = find(u, q);
  if (rootP == rootQ) return;
  if (u->sz[rootP]  > u->sz[rootQ]) {
    u->id[rootQ]  = rootP;
    u->sz[rootP] += u->sz[rootQ];
  } 
  else {
    u->id[rootP]  = rootQ;
    u->sz[rootQ] += u->sz[rootP];
  }  
  u->count--;
}

typedef struct {
  int u;
  int v;
  int w;
} edge;

edge create(int u, int v, int w) {
  edge  e;
  e.u = u;
  e.v = v;
  e.w = w;
  return e;
}

bool operator<(const edge &e1, const edge &e2) {
  return e1.w > e2.w;
}

int cost(int x, int y) {
  return pow(x, 2) + pow(y, 2);
}

vector< pair<int, int> > point;
priority_queue<edge> pipe;

void add_edge(int u, int v, int mincost) {
  int w;
  for (int i = 0; i < point.size(); i++) {
    w = cost(u - point[i].first, v - point[i].second);
    if (w >= mincost) {
	  pipe.push(create(i, point.size(), w));
    }
  }
  point.push_back(make_pair<int, int>(u, v));
}

int minimum(priority_queue<edge> pq, int n) {
  UnionFind u = createUF(n);
  int mst = 0;
  int cst = 0;
  edge e;
  while(!pq.empty() && mst < n - 1) {
    e = pq.top();
    pq.pop();
    if(!connected(&u, e.u, e.v)) {
      mst += 1;
      cst += e.w;
      connect(&u, e.u, e.v);
    }
  }
  return u.count == 1 ? cst : - 1;
}

int main () {
  int n, c, u, v;
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &u, &v);
    add_edge(u, v, c);
  }
  printf("%d\n", minimum(pipe, n));
  return 0;
}













	
