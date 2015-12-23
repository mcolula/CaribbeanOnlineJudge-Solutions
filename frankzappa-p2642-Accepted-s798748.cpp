#include <iostream>
#include <string>

using namespace std;

bool div3(string s) {
  int o_count = 0;
  int e_count = 0;
  int i = 0;
  while (true) {
    if (s[i] == '1')
      o_count++;
    i++;
    if (i >= s.size())
      break;
    if (s[i] == '1')
      e_count++;
    i++;
    if (i >= s.size())
      break;
  }
  return (o_count - e_count) % 3 == 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    s.erase(0, s.find_first_not_of('0'));
    if (div3(s))
      cout << "YES\n";
    else 
      cout << "NO\n";
  }
  return 0;
}

