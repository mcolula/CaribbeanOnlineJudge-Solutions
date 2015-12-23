#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define qii    queue< pair<int, int> > 
#define ctr    front().second
#define idx    front().first
#define vi     vector<int>

vi positions(string q, string s) {
  vi ans = vi(q.size());
  qii ps;
  int k  = 0; // next  person
  int p  = 0; // person count
  int i  = 0;
  while (i < s.size()){
    if (!ps.empty() && q[ps.idx] == s[i]) {
      ans[ps.idx] = p - ps.ctr;
      ps.pop(); i++;
      continue;
    }
    if (q[k] == s[i]) {
      ans[k++] = 0; 
      p++; i++;
      continue;
    }
    while (q[k] != s[i] && k < s.size())
      ps.push({k++, p});
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  string q;
  cin >> n >> q >> s;
  for (auto i: positions(q, s))
    cout << i << "\n";
  return 0;
}
