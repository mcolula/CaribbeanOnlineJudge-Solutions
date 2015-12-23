#include <iostream>
#include <cstring>
#include <utility>
#include <cstdio>
#include <map>

using namespace std;

typedef struct { 
  int * id;
  int * sz;
} UnionFind;

int create(UnionFind * u, int n) {
  u->id = new int[n];
  u->sz = new int[n];
  for(int i = 0; i < n; i++) {
    u->sz[i] = 1;
    u->id[i] = i;
  }
}

int find(UnionFind * u, int p) {
  int n = p;
  while(n != u->id[n])
    n = u->id[n];
  return n;
}

int connect(UnionFind * u, int p, int q) {
  int rootQ = find(u, q);
  int rootP = find(u, p);
  if (rootP == rootQ) return u->sz[rootP];
  if (u->sz[rootP] < u->sz[rootQ]) {
    u->id[rootP] = rootQ;
    u->sz[rootQ] += u->sz[rootP];
    return u->sz[rootQ];
  }
  else {
    u->id[rootQ] = rootP;
    u->sz[rootP] += u->sz[rootQ];
    return u->sz[rootP];
  } 
}


int main() {
  int t, n;
  int x, y;
  char a[40];
  char b[40];
  UnionFind net;	
  map <string, int> people;
  scanf("%d", &t);
  while (t--) {
	scanf("%d", &n);
    create(&net, 2 * n);
    while (n--) {
	  scanf("%s %s", a, b);
	  if (people.count(a) == 0) 
	    people[a] = people.size() - 1;  
	  if (people.count(b) == 0)
	    people[b] = people.size() - 1;
      x = people[a];
      y = people[b];
      printf("%d\n", connect(&net, x, y));	
	}
    people.clear();
  }
  return 0;
}
