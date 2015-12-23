#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n, n != 0) {
    int total =  12 * (n - 2);
    if (total <= 0)
      cout << 0 << "\n";
    else
      cout << total << "\n";
  }
}
