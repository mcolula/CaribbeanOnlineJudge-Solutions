#include <iostream>

using namespace std;

typedef unsigned long long llu;

llu sum(llu n, llu m) {
  return ((n % m) * (n % m)) % m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  llu n, m;
  cin >> t;
  cin >> m;
  while (t--) {
    cin >> n;
    cout << sum(n, m) << "\n";
  }
}
