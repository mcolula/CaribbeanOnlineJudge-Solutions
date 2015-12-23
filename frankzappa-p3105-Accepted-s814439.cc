#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int count(int l, int s, int t) {
  int * table = new int[l + 1]();
  table[0] = 1;
  for (int i = 0; i <= l; i++) {
    if (s <= i)
      table[i] = (table[i] + table[i - s]) % 1000000007;
    if (t <= i)
      table[i] = (table[i] + table[i - t]) % 1000000007;
  }
  return table[l];
}

int main() {
  int l, s, t;
  cin >> l >> s >> t;
  cout << count(l, s, t) << endl;
  return 0;
}
