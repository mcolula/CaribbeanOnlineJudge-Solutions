#include <iostream>
#include <utility>
#include <limits>
#include <queue>

using namespace std;

bool ** marked;

bool ** create(int n, int m) {
  bool ** a = new bool*[n]();
  for (int i = 0; i < n; i++)
    a[i] = new bool[m]();
  return a;
}

bool valid(int i, int j, int n, int m) {
  return (i >= 0) && (i < n) && (j >= 0) && (j < m) && !marked[i][j];
}

int mark(int i, int j, int n, int m) {
  queue< pair<int, int> > q;
  q.push(make_pair(i, j));
  marked[i][j] = true;
  int x, y;
  int count = 0;
  while (!q.empty()) {
	count++;
    x = q.front().first;
    y = q.front().second; q.pop();
    if (valid(x + 1, y, n, m)) { marked[x + 1][y] = true; q.push(make_pair(x + 1, y)); }
    if (valid(x - 1, y, n, m)) { marked[x - 1][y] = true; q.push(make_pair(x - 1, y)); }
    if (valid(x, y + 1, n, m)) { marked[x][y + 1] = true; q.push(make_pair(x, y + 1)); }
    if (valid(x, y - 1, n, m)) { marked[x][y - 1] = true; q.push(make_pair(x, y - 1)); }
  }
  return count;
}

pair<int, int> count(int n, int m, int k) {
  int blots = 0;
  int total = 0;
  int count = 0;
  int mx = numeric_limits<int>::min();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!marked[i][j]) {
	    blots = mark(i, j, n, m);
	    mx = max(mx, blots);
	    total += blots;
	    count++;
	    if (total == k) 
	      return make_pair(count, mx);
	  }
  return make_pair(count, mx);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k = 0;
  string s;
  cin >> n;
  cin >> m;
  marked = create(n, m);
  for (int i = 0; i < n; i++) {
	cin >> s;
    for (int j = 0; j < m; j++)
      if (s[j] == '1') {
        marked[i][j] = false;
	    k++;
	  }
	  else
	    marked[i][j] = true;
  }
  pair<int, int> ans = count(n, m, k); 
  cout << ans.first << " " << ans.second << "\n";
  return 0;
}
