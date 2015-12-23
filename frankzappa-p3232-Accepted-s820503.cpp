#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int p = numeric_limits<int>::max();

bool smaller(int i) { return i < p; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a;
  int m, t;
  string s;
  cin >> t;
  while (t--) {
    cin >> m >> s;
    if (s.compare("AC") == 0) {
	  p = min(p, m);
    }
	a.push_back(m);
  }
  if (p == numeric_limits<int>::max())
    cout << 0 << "\n";
  else
    cout << 20 * count_if(a.begin(), a.end(), smaller) + p << "\n";
  return 0;
}
