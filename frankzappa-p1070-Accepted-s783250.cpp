#include <iostream>
#include <cstdio>

using namespace std;

int squares(int n) {
  int r = 0;
  int i = n;
  int j = 0;
  while (i--) { 
    r += (n - j) * (n - j);
    j += 1;
  }
  return r;
}

int rectangles(int n) {
  int r = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      r += (n - i + 1) * (n - j + 1);
  return r;
}

int main() {
  int n;
  while (cin >> n)
    printf("%d %d\n", squares(n), rectangles(n));
  return 0;
}
