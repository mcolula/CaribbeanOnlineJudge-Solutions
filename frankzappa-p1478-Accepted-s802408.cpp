#include <iostream>

using namespace std;

int ** table;

int ** create(int n, int m) {
  int ** table = new int*[n];
  for (int i = 0; i < n; i++) {
    table[i] = new int[m];
    fill_n(table[i], m, 0);
  }
  for (int i = 0; i < n; i++)
    table[i][0] = i;
  for (int i = 0; i < m; i++)
    table[0][i] = i;
  return table;
}


int edit_distance(string s, string t) {
  int n = s.size() + 1;
  int m = t.size() + 1;
  table = create(n, m);
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      if (s[i - 1] == t[j - 1]) 
        table[i][j] = table[i - 1][j - 1];
      else 
        table[i][j] = 1 + min(min(table[i - 1][j], table[i][j - 1]), table[i - 1][j - 1]);
  return table[n - 1][m - 1];
}

int main() {
  string s, t;
  cin >> s >> t;
  cout << edit_distance(s, t) << endl;
  return 0;
}
