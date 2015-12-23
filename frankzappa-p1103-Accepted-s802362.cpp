#include <algorithm>
#include <cstdio>

using namespace std;

int coins[5] = {1, 5, 10, 25, 50};

int * create(int m, int n) {
  int * table = new int[n + 1];
  table[0] = 1;
  for (int i = 0; i < m; i++)
    for (int j = coins[i]; j <= n; j++)
      table[j] += table[j - coins[i]];
  return table;
}

int * table = create(5, 7489);



int main() {	
  int n;
  while (scanf("%d", &n) != EOF)
    printf("%d\n", table[n]);
  return 0;
}
