#include <iostream>
#include <cmath>

using namespace std;

int page(int n) {
  return ceil((sqrt(8 * (n + 1) + 1) - 1) / 2.0);
}

int total(int n) {
  return n * (n + 1) / 2;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  while (cin >> n) {
	if (n == 0) return 0;
	k = page(n);
    cout << total(k) - n << " " << k << "\n";
  }
  return 0;
}
