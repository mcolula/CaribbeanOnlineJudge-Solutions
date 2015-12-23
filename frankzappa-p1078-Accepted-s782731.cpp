#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int t;
  int k, a, n, c;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &k);
    n = k;
    c = 0;
    while (k--) {
      scanf("%d", &a);
        c += a;
    }
    if (c % n == 0)
      printf("YES\n");
    else 
      printf("NO\n");
  }
  return 0;
}

