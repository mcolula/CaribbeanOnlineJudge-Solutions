#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

int * create(int n) {
  return new int[4 * n + 1];
}

void init_max(int * num, int * rng, int n, int lo, int hi) {
  if (lo >= hi) {
    rng[n] = num[lo];
    return;
  }
  int mid = (lo + hi) / 2;
  init_max(num, rng, 2 * n + 0, lo, mid + 0);
  init_max(num, rng, 2 * n + 1, mid + 1, hi);
  rng[n] = max(rng[2 * n + 0], rng[2 * n + 1]);
}

void init_min(int * num, int * rng, int n, int lo, int hi) {
  if (lo >= hi) {
    rng[n] = num[lo];
    return;
  }
  int mid = (lo + hi) / 2;
  init_min(num, rng, 2 * n + 0, lo, mid + 0);
  init_min(num, rng, 2 * n + 1, mid + 1, hi);
  rng[n] = min(rng[2 * n + 0], rng[2 * n + 1]);
}

int qmax(int * rng, int n, int lo, int hi, int i, int j) {
  if (i > hi || j < lo)
    return numeric_limits<int>::min();
  if (i <= lo && j >= hi)
    return rng[n];
  int mid = (lo + hi) / 2;
  return max(qmax(rng, 2 * n + 0, lo, mid + 0, i, j), qmax(rng, 2 * n + 1, mid + 1, hi, i, j));   
}

int qmin(int * rng, int n, int lo, int hi, int i, int j) {
  if (i > hi || j < lo) 
    return numeric_limits<int>::max();
  if (i <= lo && j >= hi)
    return rng[n];
  int mid = (lo + hi) / 2;
  return min(qmin(rng, 2 * n + 0, lo, mid + 0, i, j), qmin(rng, 2 * n + 1, mid + 1, hi, i, j)); 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  int a, b;
  cin >> n >> q;
  int * num = new int[n];
  int * mxrng = create(n);
  int * mnrng = create(n);
  for (int i = 0; i < n; i++)
    cin >> num[i];
  init_max(num, mxrng, 1, 0, n);
  init_min(num, mnrng, 1, 0, n);
  while (q--) {
    cin >> a >> b;
    cout << qmax(mxrng, 1, 0, n, a - 1, b - 1) - qmin(mnrng, 1, 0, n, a - 1, b - 1) << "\n";
  }
  return 0;
}

