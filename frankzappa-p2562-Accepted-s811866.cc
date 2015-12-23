#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<int> sieve(int n) {
  bool * nums = new bool[n]();
  for (int i = 2; i <= sqrt(n); i++)
    if (!nums[i])
      for (int j = 2 * i; j < n; j += i)
        nums[j] = true;
  vector<int> ps;
  for (int i = 2; i < n; i++)
    if(!nums[i])
      ps.push_back(i);
  return ps;
}

vector<int> primes = sieve(1000001);

map<int, int> factor(int n) {
  map<int, int> fs;
  for (int i = 0; i < primes.size() && primes[i] <= n; i++)
    if (n % primes[i] == 0) {
	  n /= primes[i];
	  fs[primes[i]] += 1;
	  i = -1;  
    }
  return fs;
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (auto &i: factor(n))
      printf("(%d(%d))", i.first, i.second);
    printf("\n");
  }
  return 0;
}
