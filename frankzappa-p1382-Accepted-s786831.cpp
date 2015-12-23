#include <cstdio>
#include <cmath>

typedef unsigned long long ull;

int sum(ull n) {
  ull a = (n * (n + 1) / 2) % 1000007; 
  ull b = (n * (n + 1) / 2) % 1000007;
  return (a * b) % 1000007;
}

int nearest_cube(ull n) {
  double a = pow(n, 1 / 3.0);
  if (pow(ceil(a), 3) <= n)
    return ceil(a);
  else 
    return floor(a);
}

int modulo(int n, int m) {
  return n >= 0 ? n % m : modulo(n + m, m);
}


int main() {
  int t;
  scanf("%d", &t);
  ull a, b;
  while (t--) {
	scanf("%llu %llu", &a, &b);
	if (pow(nearest_cube(a), 3) == a)
      printf("%d\n", modulo(sum(nearest_cube(b)) - sum(nearest_cube(a - 1)), 1000007));
    else
      printf("%d\n", modulo(sum(nearest_cube(b)) - sum(nearest_cube(a)), 1000007));
  }
  return 0;
}

