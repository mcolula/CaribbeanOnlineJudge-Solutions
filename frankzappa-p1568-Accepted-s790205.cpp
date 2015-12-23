#include <cstdio>

typedef struct {
  int r;
  int c;
} coord;

typedef unsigned long long ull;

int revcol(coord * c, int n) {
  c->c = n - c->c - 1;
  return 0;
}

int revrow(coord * c, int n) {
  c->r = n - c->r - 1;
}

int transp(coord * c, int n) {
  c->c ^= c->r;
  c->r ^= c->c;
  c->c ^= c->r;
  return 0;
}

int rotatecw(coord * c, int n) {
  revcol(c, n);
  transp(c, n);
  return 0;
}

int rotateccw(coord * c, int n) {
  revrow(c, n);
  transp(c, n);
  return 0;
}

ull val(coord c, int n) {
  ull col = c.c;
  ull row = c.r;
  return row * n + col + 1;
}

int main() {
  int n, k, r, c;
  scanf("%d %d %d %d", &n, &k, &r, &c);
  coord a;
  a.c = c - 1;
  a.r = r - 1;
  k = k % 4;
  if (k > 0) {
    for (int i = 0; i < k; i++)
      rotatecw(&a, n);	
    printf("%llu\n", val(a, n));
  }
  else if (k < 0) {
    for (int i = 0; i < -k; i++)
      rotateccw(&a, n);
    printf("%llu\n", val(a, n));
  }
  else {
    printf("%llu\n", val(a, n));
  }
    
}
