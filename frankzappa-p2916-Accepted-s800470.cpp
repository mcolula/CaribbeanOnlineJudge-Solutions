#include <cstdio>

typedef unsigned int uin; 

uin gcd(uin a, uin b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  uin a, b;
  while(scanf("%d %d", &a, &b) != EOF) {
  if (gcd(a, b) == 1)
    printf("YES\n");
  else
    printf("NO\n");
  }
  return 0;
}
