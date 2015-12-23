#include <iostream>
#include <cmath>

using namespace std;

int sum(int n) {
  return n * (n + 1) / 2;
}


int main() {
  int t;
  cin >> t;
  if (t >= 0)
    cout << sum(t) << endl;
  else
    cout << sum(abs(t)) * - 1 + 1<< endl;
  return 0;
}

