#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int * table;

void count(int l, int s, int t) {
  table = new int[l + 1]();
  table[0] = 1;
  for (int i = 0; i <= l; i++) {
    if (s <= i)
      table[i] = (table[i] + table[i - s]) % 1000000007;
    if (t <= i)
      table[i] = (table[i] + table[i - t]) % 1000000007;
  }
}

int main() {
  count(1000000, 1, 2);
  int n, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", table[n]);
  }
  return 0;
}
