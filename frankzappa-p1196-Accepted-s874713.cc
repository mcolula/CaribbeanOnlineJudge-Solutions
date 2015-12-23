#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define bits(n)         __builtin_popcount( n)
#define contains(c, v)  (c.find(v) != c.end())

set<int>  primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
vector<int> nums;
int length;


void ring(int mask, int last) {
  if (bits(mask) == length) {
    if (contains(primes, last + 1)) {
      for (auto i: nums)
        cout << i << " ";
      cout << "\n";
    }
  }
  else
    for (int i = 0; i < length; i++)
      if (!(mask & (1 << i)) && contains(primes, last + i + 1)) {
        nums.push_back(i + 1);
        ring(mask | (1 << i), i + 1);
      }
  nums.pop_back();
}   

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin  >>  m;
    length = m;
    cout << "Case " << i + 1 << ":\n";
    nums.push_back(1);
    ring(1, 1); 
  }
  return 0;
}
