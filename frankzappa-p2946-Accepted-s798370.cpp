#include <cstdio>

int even(int n) {
  int res = n;
  while(!(res  & 1)) {
    res = res >> 1;
  }
  return res;
}

int odd(int n) {
  return n << 1;
}

int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n % 2 == 0)
      printf("%d\n", even(n));
    else 
      printf("%d\n", odd(n));  
  }
  return 0;
}

