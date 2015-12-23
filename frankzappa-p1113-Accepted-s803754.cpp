#include <iostream>

using namespace std;

#define MAX 31

int f[MAX];
int g[MAX];

int countg(int n);

int countf(int n) { 
  if (n % 2 != 0) 
    return 0;
  if (f[n] >= 0)
    return f[n];
  f[n] = countf(n - 2) + 2 * countg(n - 1);
  return f[n];
}

int countg(int n) {
  if (g[n] >= 0)
    return g[n];
  g[n] = countf(n - 1) + countg(n - 2);
  return g[n]; 
}

int main() {
  int n;
  fill_n(f, MAX, -1); 
  fill_n(g, MAX, -1); 
  f[0] = 1;
  f[1] = 0;
  g[0] = 0; 
  g[1] = 1;
  while (cin >> n) 
    if (n >= 0)
      cout << countf(n) << endl;
    else
      break;
  return 0;
}
