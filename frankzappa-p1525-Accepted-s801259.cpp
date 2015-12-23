#include <cstdio>


int cows(int n, int m) {
  if (n % 2 != 0 && m % 2 != 0) {
    return 1 + 4 * cows(n / 2, m / 2);
  }
  return 0;
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d\n", cows(n, m));
  return 0;
}
