#include <cstdio>
#include <cmath>

int dishes(int n) {
  int b = log(n) / log(2) + 1;
  for (int i = 0; i < b; i++)
    if (((n >> i) & 1) == 1)
      printf("%d ", i);
  printf("\n");
  return 0;
}

int main(int argc, char **argv) {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    dishes(n);
  }
  return 0;
}

