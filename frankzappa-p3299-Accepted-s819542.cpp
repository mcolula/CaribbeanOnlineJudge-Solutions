#include <cstdio>
#include <cmath>

typedef unsigned long long ull;

ull tri_nums(ull n) {
  return floor((sqrt(8 * n + 1) - 1) / 2.0);
}

int main() {
  ull a, b;
  while (scanf("%llu %llu", &a, &b) != EOF) {
    if (a == 0 && b == 0)
      break;
    printf("%llu\n", tri_nums(b) - tri_nums(a - 1));
  }
  return 0;
}
