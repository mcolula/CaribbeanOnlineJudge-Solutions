#include <cstdio>

typedef struct {
  int * id;
  int * sz;
  int count;
} UnionFind;

UnionFind create(int n) {
  UnionFind u;
  u.count = n;
  u.id = new int[n]();
  u.sz = new int[n]();
  for (int i = 0; i < n; i++) {
    u.id[i] = i;
    u.sz[i] = 0;
  }
  return u;
}

int find(UnionFind * u, int p) {
  int q = p;
  while (q != u->id[q]) {
    u->id[q] = u->id[u->id[q]];
    q = u->id[q];
  }
  return q;
}

void  connect(UnionFind * u, int p, int q) {
  int rootP = find(u, p);
  int rootQ = find(u, q);
  if (rootP == rootQ) return;
  if (u->sz[rootP] > u->sz[rootQ]){
    u->id[rootQ]  = rootP;
    u->sz[rootP] += u->sz[rootQ];
  }
  else {
    u->id[rootP]  = rootQ;
    u->sz[rootQ] += u->sz[rootP];
  }
  u->count--;
}
    
int choose2(int n) {
  return n * (n - 1) / 2;
}

int main() {
  int t, n, m, p, q;
  UnionFind u;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    u = create(n);
    while(m--) {
	  scanf("%d %d", &p, &q);
	  connect(&u, p - 1, q - 1);
	}
	printf("%d\n", choose2(u.count));	
  }
  return 0;
}
