#include <cstdio>
#include <cmath>

using namespace std;

int eulerions(int n) {
  return log(n) / log(2.7182818284590452354) + 1;
}

int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", eulerions(n));
  }
  return 0;
}

