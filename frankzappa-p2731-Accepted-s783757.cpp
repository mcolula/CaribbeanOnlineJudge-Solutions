#include <iostream>
#include <cstdio>
#include <cmath>

double surface(double n) {
  return pow(n, 2) - pow(n / 2, 2) * M_PI;
}

int main() {
  int t;
  double n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lf", &n);
    printf("%.2lf\n", surface(n));
  }
  return 0;
}

