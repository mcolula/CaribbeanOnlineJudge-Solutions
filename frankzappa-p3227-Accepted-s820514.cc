#include <iostream>
#include <utility>
#include <map>

using namespace std;

typedef unsigned long long llu;

map<llu, llu> nums;

pair<llu, llu> divide(llu a, llu b) {
  if (a % 2 == 0)
    return divide(a / 2, b * 2);
  return make_pair(a, b);
}

llu combine(llu a, llu b) {
  if (b >= 2)
    return combine(a * 2, b / 2);
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pair<llu, llu> p;
  int n, m, t;
  llu r, a, b;
  cin >> t;
  while (t--) {
	r = 0;
    cin >> m;
    while (m--) { 
	  cin >> a;
	  b = 1;
	  p = divide(a, b);
	  
	  nums[p.first] += p.second;  
	}
	for (auto &i: nums)
	  r = max(r, combine(i.first, i.second));
    cout << r << "\n";
    nums.clear();
  }
  return 0;
}

