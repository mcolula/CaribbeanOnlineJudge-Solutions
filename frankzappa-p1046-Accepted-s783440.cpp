#include <iostream>
#include <cstdio>

using namespace std;

int operation(int n) {
  return (n) * (n + 1) * (n + 2); 
}

int sum(int a, int b) {
  int r = 0;
  for (int i = a; i <= b; i++)
    r = (r + (operation(i)  % 100)) % 100;
  return r;
}

int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    printf("%d\n", sum(n, m));
  }
  return 0;
}

