#include <iostream>
#include <cstdio>

using namespace std;

int attacks(int a, int b, int p) {
  int q = p % (a + b);
  if (q == 0)
    return 0;
  if (q <= a)
    return 1;
  return 0;
}

int output(int a) {
  if (a == 0)
    printf("none\n");
  if (a == 1)
    printf("one\n");
  if (a == 2)
    printf("both\n");
}

int main() {
  int a, b, c, d;
  int p, m, g;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  scanf("%d %d %d", &p, &m, &g);
  output(attacks(a, b, p) + attacks(c, d, p));
  output(attacks(a, b, m) + attacks(c, d, m));
  output(attacks(a, b, g) + attacks(c, d, g));
  return 0;
}
