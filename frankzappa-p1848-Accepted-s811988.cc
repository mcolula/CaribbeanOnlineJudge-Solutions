#include <cstdio>

typedef unsigned long long llu;

llu * mat = new llu[4]{1, 1, 1, 0};
llu * i   = new llu[4]{1, 0, 0, 1};

llu * mult(llu * a, llu * b) {
  llu * r = new llu[4];
  r[0] = (a[0] * b[0] + a[1] * b[2]) % 10000;
  r[1] = (a[0] * b[1] + a[1] * b[3]) % 10000;
  r[2] = (a[2] * b[0] + a[3] * b[2]) % 10000;
  r[3] = (a[2] * b[1] + a[3] * b[3]) % 10000;
  return r;
}

llu * power(llu * b, int e) {
  if (e == 0)
    return i;
  if (e == 1)
    return b;
  if (e % 2 == 0) {
    llu * t = power(b, e / 2);
    return mult(t, t);
  }
  if (e % 2 != 0) {
    llu * t = power(b, (e - 1) / 2);
    return mult(mult(t, t), b);
  } 
}

llu * fibonacci(int n) {
   llu * r = power(mat, n - 1);
   return r;
}

int main() {
  int t, n;
  llu * r;
  scanf("%d", &t);
  while (t--) {
	scanf("%d", &n);
    r = fibonacci(n);
    printf("%llu %llu %llu\n", r[3], r[1], r[0]);
  }
  return 0;
}

