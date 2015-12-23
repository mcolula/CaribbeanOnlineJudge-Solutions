#include <cstdio>

bool valid(int a, int b, int c) {
  if (b == 0)
    return (a + b == c) || (a - b == c) || (a * b == c);
  else
    return (a + b == c) || (a - b == c) || (a * b == c) || (a / b == c) || (a % b == c);
}

int main() {
  int t, a, b, c;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &a, &b, &c);
    if (valid(a, b, c))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
