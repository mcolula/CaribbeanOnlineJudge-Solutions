#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char swap (char c) {
  if (c == 'L')
    return 'R';
  else
    return 'L';
}

string rotate(string s) {
  for (int i = 0; i < s.size(); i++)
    s[i] = (char)swap(s[i]);
  return s; 
}

string dragon(int n) {
  if (n == 0)
    return "";
  if (n == 1) 
    return "L";
  string s, r; 
  s = dragon(n - 1);
  r = s;
  reverse(r.begin(), r.end());
  s = s  + "L" + rotate(r);
  return s;
}


int main() {
  int n;
  while (true) {
    cin >> n;
    if (n == -1) break;
    cout << dragon(n) << endl;
  }
  return 0;
}

