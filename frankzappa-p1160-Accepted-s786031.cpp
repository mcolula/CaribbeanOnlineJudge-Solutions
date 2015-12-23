#include <cstdio>


int number(int x, int y) {
  if (x == y)
    if (x % 2 == 0)
      return x + y;
    else
      return x + y - 1;
  if (x == (y + 2))
    if (x % 2 == 0)
      return x + y;
    else
      return x + y - 1;
  return -1;
}

int main() {
  int t, x, y, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &x, &y);
    n = number(x, y);
    if (n == -1)
      printf("No Number\n");
    else
      printf("%d\n", n);
  }
  return 0;
}

