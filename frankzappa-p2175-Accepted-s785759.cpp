#include <algorithm>
#include <utility>
#include <cstdio>
#include <cmath>

using namespace std;

bool * primes(int n) {
  bool * p = new bool[n];
  fill_n(p, n, true);
  for (int i = 2; i <= sqrt(n); i++) {
    if (p[i]) {
	  for (int j = 2 * i; j < n; j += i)
	    p[j] = false;
	}
  }
  return p;
}

bool * prime = primes(100010);

int a_length = 100010;

pair<int, int> interval(int n) {
  int i, j;
  for (i = n; i >= 0; i--)
    if (prime[i])
      break;  
  for (j = n; i < a_length; j++)
    if (prime[j])
      break;
  return make_pair(i, j);
}


int main() {
  int n, t;
  pair<int, int> in;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    in = interval(n);
    printf("%d %d\n", in.first, in.second);
  }
  return 0;
}

