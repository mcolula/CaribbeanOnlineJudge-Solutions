#include <cstdio>

int zeros(int n) {
  int count = 0;
  for (int i = 5; n >= i; i *= 5)
    count += n / i;
  return count;
}

int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
  	scanf("%d", &n);
  	printf("%d\n", zeros(n));
  }
  return 0;
}