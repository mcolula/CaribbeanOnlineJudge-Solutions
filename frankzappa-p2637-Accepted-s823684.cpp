#include <iostream>

using namespace std;

typedef unsigned long long ull;

void init(ull * nums, ull * range, int n, int lo, int hi) {
  if (lo == hi) {
    range[n] = nums[lo];
    return;
  }
  int mid = (lo + hi) / 2;
  init(nums, range, 2 * n + 0, lo, mid + 0);
  init(nums, range, 2 * n + 1, mid + 1, hi);
  range[n] = range[2 * n + 0] + range[2 * n + 1];
}

ull query(ull * range, int n, int lo, int hi, int i, int j) {
  if (j < lo || i > hi)
    return 0;
  if (i <= lo && j >= hi)
    return range[n];
  int mid = (lo + hi) / 2;
  return query(range, 2 * n + 0, lo, mid + 0, i, j) + query(range, 2 * n + 1, mid + 1, hi, i, j);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, n, q, a, b;
  ull * num;
  ull * rng;
  cin >>  t;
  while (t--) {
    cin >> n >> q;
    num = new ull[n];
    rng = new ull[4 * n];
    for (int i = 0; i < n; i++)
      cin >> num[i];
    init(num, rng, 1, 0, n - 1);
    while (q--) {
      cin >> a >> b;
      cout << query(rng, 1, 0, n - 1, a, b) << "\n";
    }
    if (t != 0)
      cout  << "\n";
    delete[] num;
    delete[] rng;
  }
  return 0;
}
