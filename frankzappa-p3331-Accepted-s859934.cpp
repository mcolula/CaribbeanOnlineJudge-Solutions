#include <iostream>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, m;
  while (cin >> n >> m, n + m != 0) {
    long long int total = (n * m) * (n * m - 1);
    if (n <= 2 && m <= 2)
      total = 0;
    else if (n == 1 || m == 1)
      total -= 2 + 2 * (n * m - 2);
    else {
      total -= 12; 
      total -= 10 * (m + n - 4);
      total -=  8 * (m - 2) * (n - 2);
    } 
    cout << total << "\n";
  }
  return 0;
}
