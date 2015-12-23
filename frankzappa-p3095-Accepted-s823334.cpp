#include <iostream>

using namespace std;

typedef unsigned long long ull;

int * a = new int[4]{1, 1, 1, 0};
int * i = new int[4]{1, 0, 0, 1};

int * mult(int * a, int * b) {
  int * r = new int[4];
  r[0] = (a[0] * b[0] + a[1] * b[2]) % 10;
  r[1] = (a[0] * b[1] + a[1] * b[3]) % 10;
  r[2] = (a[2] * b[0] + a[3] * b[2]) % 10;
  r[3] = (a[2] * b[1] + a[3] * b[3]) % 10;
  return r;
}

int * power(int * b, ull e) {
  if (e == 0)
    return i;
  if (e == 1)
    return b;
  if (e % 2 == 0) {
    int * t = power(b, e / 2);
    return mult(t, t);
  }
  if (e % 2 != 0) {
    int * t = power(b, (e - 1) / 2);
    return mult(mult(t, t), b);
  } 
}

int last_digit(ull n) {
  return power(a, n)[1];
}

int main() {
  ull n;
  while (cin >>  n)
    cout << last_digit(n) << "\n";
  return 0;
}

