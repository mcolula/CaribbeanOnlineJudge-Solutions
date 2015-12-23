#include <cstdio>

typedef unsigned long long int llu;

llu faces(llu n) {
  return n * (n * n * n - 6 * n * n + 23 * n - 18) / 24 + 1;
}


int main() {
  int t;
  llu n;
  scanf("%d", &t);
  while (t--) {
	scanf("%llu", &n);
    printf("%llu\n", faces(n));
  }
  return 0;
}

