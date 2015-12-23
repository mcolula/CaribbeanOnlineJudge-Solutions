#include <algorithm>
#include <cstdio>

#define MAX 4

using namespace std;

int coins[MAX] = {1, 3, 5, 6};

int ** create(int n) {
  int ** a = new int*[MAX]();
  for (int i = 0; i < MAX; i++)
    a[i] = new int[n]();
  for (int i = 0; i < n; i++) {
    a[0][i] = i;
  }
  return a;
}

int * change(int n) {
  int ** a = create(n + 1);
  for (int i = 1; i < MAX; i++)
    for (int j = 1; j < n + 1; j++)
      if (j < coins[i])
        a[i][j] = a[i - 1][j];
      else
        a[i][j] = min(a[i - 1][j], a[i][j - coins[i]] + 1);
  return a[MAX - 1];
}

int * ans = change(100000);

int main() { 
  int t, n;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    printf("Case %d: %d\n", i + 1, ans[n]);
  }
  return 0; 
}

