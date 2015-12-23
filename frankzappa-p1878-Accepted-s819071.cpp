#include <iostream>
#include <utility>
#include <queue>
using namespace std;

bool ** marked; 

bool ** create(int n, int m) {
  bool ** a = new bool*[n];
  for (int i = 0; i < n; i++)
    a[i] = new bool[m]();
  return a;
}

bool valid(int i, int j, int n, int m) {
  return (i >= 0) && (i < n) && (j >= 0) && (j < m);
}

int mark(int i, int j, int n, int m) {
  queue<pair<int, int> > q;
  q.push(make_pair(i, j));
  marked[i][j] = true;
  int x, y;
  int count = 0;
  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    count++;
    if (valid(x + 1, y, n, m) && !marked[x + 1][y]) {marked[x + 1][y] = true; q.push(make_pair(x + 1, y));}
    if (valid(x - 1, y, n, m) && !marked[x - 1][y]) {marked[x - 1][y] = true; q.push(make_pair(x - 1, y));}
    if (valid(x, y + 1, n, m) && !marked[x][y + 1]) {marked[x][y + 1] = true; q.push(make_pair(x, y + 1));}
    if (valid(x, y - 1, n, m) && !marked[x][y - 1]) {marked[x][y - 1] = true; q.push(make_pair(x, y - 1));}
  }
  return count;
}

int count(int n, int m, int c) {
  int left = 0;
  int bug  = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
	  if (!marked[i][j]) {
	    left += mark(i, j, n, m);
	    bug++;
	    if (left == c)
	      return bug;
	  }
  return bug;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string  s;
  int n,  m;
  cin >>  m;
  cin >>  n;
  int c = 0;
  marked = create(n, m);
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++)
      if (s[j] == '1')
        marked[i][j] = true;
      else 
        c++;
  }
  cout << count(n, m, c) << endl;
  return 0;
}
