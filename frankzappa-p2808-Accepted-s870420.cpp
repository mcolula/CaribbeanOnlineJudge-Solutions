#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int    n;
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    int length = 1;
    for (int i = 1; i < s.size(); i++)
      if (s[i] != s[i % length])
        length = i + 1;
    if (s.size() % length != 0)
      cout << s.size() << "\n";
    else
      cout << length   << "\n"; 
  }
  return 0;
}
