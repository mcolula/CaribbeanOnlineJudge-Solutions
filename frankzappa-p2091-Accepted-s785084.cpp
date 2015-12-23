#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int count(string s, int n) {
  set<int> chars;
  char temp;
  for(int i = 0; i < n; i++) {
    temp = s[i];
    if (chars.find(temp) == chars.end())
      chars.insert(temp); 
  }
  return chars.size();
}

int main() {
  int t;
  string s;
  scanf("%d", &t);
  while (t--) {
    cin >> s;
    printf("%d\n", count(s, s.size()));
  }
  return 0;
}

