#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prime;

void create(int n) {
  bool * a = new bool[n]();
  for (int i = 2; i <= sqrt(n); i++)
    if (!a[i]) 
      for (int j = 2 * i; j < n; j += i)
        a[j] = true;
  for (int i = 2; i < n; i++)
    if (!a[i])
      prime.push_back(i);
}

int count(int a, int b) {
  int upper = distance(prime.begin(), upper_bound(prime.begin(), prime.end(), b));
  int lower = distance(prime.begin(), lower_bound(prime.begin(), prime.end(), a));
  return upper - lower; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  create(1000000);
  while (cin >> a >> b) {
    if (a == 0 && b == 0) return 0;
    cout << count(a, b) << "\n";
  }
  return 0;
}
