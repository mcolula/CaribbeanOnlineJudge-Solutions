#include <iostream>
#include <string>

using namespace std;

bool subsecuence(string s, string t) {
  for (int i = 0, j = 0; i < t.size(); i++) {
    if (t[i] == s[j])
      j++;
    if (j >= s.size())
      return true;
  }
  return false;
}


int main() {
  string s, t;
  while (cin >> s >> t) {
    if(subsecuence(s, t))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}

