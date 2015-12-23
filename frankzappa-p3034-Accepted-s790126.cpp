#include <cstdio>

using namespace std;

int sup(int n) {
  int r = 0;
  int m = n / 4;
  int x = n - 4 * m;
  if (x == 0) return n;
  for (int i = 0; i <= x; i++)
    r ^= n - i;
  return r;
}

int inf(int n) {
  int r = 0;
  int m = n / 4;
  int x = 4 * (m + 1) - n;
  if (x == 0) return n;
  for (int i = 0; i < x; i++)
    r ^= n + i;	
  return r;
}



int main() { 
  int t, a, b;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &b);
    printf("%d\n", inf(a) ^ sup(b));
  }
  return 0;
}

