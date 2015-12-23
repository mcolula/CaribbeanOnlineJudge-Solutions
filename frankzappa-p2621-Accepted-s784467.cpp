#include <iostream>
#include <cstdio>
#include <cmath>

int main() {
  int n;
  int r;
  scanf("%d", &n);
  r = log(n) / log(2) + 1;
  printf("%d\n", r);
  return 0;
}

