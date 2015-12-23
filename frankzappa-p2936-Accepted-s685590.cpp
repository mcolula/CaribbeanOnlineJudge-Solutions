#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ull;

ull choose(ull n, ull k) {
  if (k > n)
    return 0;
  ull r = 1;
  for (ull d = 1; d <= k; ++d) {
    r *= n--;
    r /= d;
  }
  return r;
}

int main() {
  int n;
  int k;
  ull r;
  while(scanf("%d %d", &n, &k) != EOF) {
    r = choose(n + k, 3) - choose(n, 3) - choose(k, 3);
    printf("Triangles: %llu\n", r);
    r = choose(n, 2) * choose(k, 2);
    printf("Quadrilaterals: %llu\n\n", r);
  }
  return 0;
}
