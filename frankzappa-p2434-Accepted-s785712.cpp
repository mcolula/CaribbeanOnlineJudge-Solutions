#include <cstdio>

int primes[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

typedef unsigned long long ull;

ull primorial(int n) { 
  ull res = 1;
  int i = 0;
  while(primes[i] <= n) {
    res *= primes[i];
    i++;
  }
  return res;
}


int main() {
  int n = 1;
  while (true) {
    scanf("%d", &n);
    if(n < 1) return 0;
    printf("%llu\n", primorial(n));
  }
  return 0;
}

