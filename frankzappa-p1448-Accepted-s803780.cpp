#include <algorithm>
#include <cstdio>
#include <limits>

using namespace std;

#define MAX numeric_limits<int>::max()
#define ROW 100000
#define LEN 3 

int ** create() {
  int ** a = new int*[ROW];
  for (int i = 0; i < ROW; i++)
    a[i] = new int[LEN];
  return a;
}
  
int ** g = create();

int min3(int a, int b, int c) {
  return min(a, min(b, c));
}

int min4(int a, int b, int c, int d) {
  return min(a, min(b, min(c, d)));
}

void read(int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < LEN; j++)
      scanf("%d", &g[i][j]); 
  g[0][0] = MAX;
  g[0][2] = g[0][2] + g[0][1];
}

int cost(int ** g, int n) {
  for (int i = 1; i < n; i++)
    for (int j = 0; j < LEN; j++) {
      if (j == 0)
        g[i][j] = g[i][j] + min(g[i - 1][j], g[i - 1][j + 1]);
      if (j == 1)
        g[i][j] = g[i][j] + min4(g[i][j - 1], g[i - 1][j - 1], g[i - 1][j], g[i - 1][j + 1]);
      if (j == 2)
        g[i][j] = g[i][j] + min3(g[i][j - 1], g[i - 1][j - 1], g[i - 1][j]);
    }
  return g[n - 1][1];
}


int main() {
  int n, t = 0;
  while (scanf("%d", &n) != EOF) {
    if (n != 0) {
      read(n);
      printf("%d. %d\n", ++t,cost(g, n));
    }
    else
      break;
  }
  return 0;
}

