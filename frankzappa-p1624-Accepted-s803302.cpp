#include <iostream>
#include <limits>

using namespace std;

#define MAX numeric_limits<int>::max();

int ** table;

int ** create(int n) {
  int ** a = new int*[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[n]();
  return a;
}

bool palindrome(string s, int i, int j) {
  if (i == j) return true;
  int n = (j - i) / 2;
  for (int k = 0; k <= n; k++)
    if (s[i + k] != s[j - k])
      return false;
  return true;
}

int count(string s) {
  for (int i = 1, j = 0; i < s.size(); i++) {
    j = 0;
    while (j + i < s.size()) {
	  if (palindrome(s, j, j + i))
	    table[j][j + i] = 0;
	  else{
	    int mn = MAX; 
	    for (int k = j; k < j + i; k++) {
	      mn = min(mn, 1 + table[j][k] + table[k + 1][j + i]);
	    }
	    table[j][j + i] = mn;
	  }
      j++;
	} 
  }
  return table[0][s.size() - 1];
}

int main() {
  string s;
  cin >> s;
  table = create(s.size());
  cout << count(s) + 1 << endl;
}
