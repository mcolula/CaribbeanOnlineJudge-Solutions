#include <iostream>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s, t;
  cin >> n;
  while (n--) {
    cin >> s >> t;
    int total = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] != t[i])
        total++;
    cout << total << "\n";
  }
  return 0;
}
