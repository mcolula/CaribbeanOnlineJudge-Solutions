#include <iostream>

using namespace std;

bool solvable(int a, int b, int c) {
  return b * b >= 4 * a * c;
}

int main() {
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (solvable(a, b, c))
      cout << "SI" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
