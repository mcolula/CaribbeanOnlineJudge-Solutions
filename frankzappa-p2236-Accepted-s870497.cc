#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int    n;
  cin >> n;
  int * a = new int[n]();
  for (int i = 0; i < n; i++)
    cin >> a[i]; 
  sort(a, a + n);
  int total = accumulate(a, a + n, 0);
  int stole = 0;
  for (int i = n - 1; i >= 0 && total >= stole; i--) {
    total -= a[i];
    stole += a[i];
    if (total < stole)
      cout << n - i << "\n";
  }
  return 0;
}
