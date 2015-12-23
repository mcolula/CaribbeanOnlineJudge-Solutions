#include <iostream>
#include <utility>
#include <vector>
#include <limits>
#include <stack>

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull>     pll;
typedef vector<int>        vi;

int area(vi spectrum) {
  stack<pll> s;
  s.push({spectrum[0], 1});
  ull mx = numeric_limits<ull>::min();
  for (int i = 1; i < spectrum.size(); i++) {
    if (s.top().first > spectrum[i]) {
      ull width = 0;
      while (!s.empty() && s.top().first >= spectrum[i]) {
        width += s.top().second;
        mx = max(mx, s.top().first * width);
        s.pop();
      }
      s.push({spectrum[i], width});
    }
    s.push({spectrum[i], 1});
  }
  return mx;
}

int main() {
  int n, m;
  cin >> n;
  vi spectrum = vi(n + 1);
  for (int i = 0; i < n; i++)
    cin >> spectrum[i];
  cout << area(spectrum) << "\n";
  return 0;
}
