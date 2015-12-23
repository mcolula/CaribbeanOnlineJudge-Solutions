#include <cstdio>
#include <cmath>

double equilateral_area(double s) {
  return pow(s, 2) * sqrt(3) / 4;
}

double area(double side, int n) {
  if (n == 0)
    return equilateral_area(side);
  return equilateral_area(side) + 4 * area(side / 3.0, n - 1);
}

int main() {
  int t, s, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &s, &n);
    printf("%.2lf\n", area(s, n));
  }
}
