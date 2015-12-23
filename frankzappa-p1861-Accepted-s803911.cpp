#include <algorithm>
#include <cstdio>

using namespace std;

typedef unsigned long long llu;

llu ** table;

llu ** create(int n, int m) {
  llu ** a = new llu*[n];
  for (int i = 0; i < n; i++)
    a[i] = new llu[m]();
  return a;
}

void read(int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      scanf("%llu", &table[i][j]);
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
      scanf("%llu", &table[n + i][j]);
}

llu revenue(int n) {
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= i; j++)
      if (j < 1)
        table[i][j] = table[i][j] + table[i - 1][j];
      else
        table[i][j] = table[i][j] + max(table[i - 1][j], table[i - 1][j - 1]);
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
      table[n + i][j] = table[n + i][j] + max(table[n + i - 1][j], table[n + i - 1][j + 1]);
  return table[2 * n - 2][0];
}

int main() {
  int n, t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    table = create(2 * n - 1, n);
    read(n);
	printf("Case %d: %llu\n", i + 1, revenue(n));
  }
  return 0;
}






