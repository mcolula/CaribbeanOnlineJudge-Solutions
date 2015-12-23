#include <cstdio>
#include <cmath>

#define SZ 3000

typedef unsigned long long llu;

int ** create(int n) {
  int ** a = new int*[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[n]();
  return a;
}

int ** choose = create(SZ);

void fill(int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      if (j == 0 || j == i)
        choose[i][j] = 1;
      else
        choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % 1000000007;
}

int modulo(int n, int m) {
  return n < 0 ? modulo(n + m, m) : n % m;
}

int level(int n) {
  return log(n) / log(2);
}

int count(int n, int m) {
  int i = pow(2, n);
  int j = m - i + 1;
  return modulo(choose[i][j], 1000000007);	
}

int main() {
  fill(SZ);
  int t, n;
  scanf("%d", &t);
  while (t--) {
	scanf("%d", &n);
    printf("%d\n", count(level(n), n) - 1);
  }
  return 0;
}
