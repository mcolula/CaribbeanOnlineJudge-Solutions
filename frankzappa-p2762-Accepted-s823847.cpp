#include <iostream>
#include <utility>
#include <queue>

using namespace std;

bool ** marked;
int  ** h;
int  ** c;

int ** create(int n, int m) {
  int ** a = new int*[n]();
  for (int i = 0; i < n; i++)
    a[i] = new int[m]();
  return a;
}

bool ** creabl(int n, int m) {
  bool ** a = new bool*[n]();
  for (int i = 0; i < n; i++)
    a[i] = new bool[m]();
  return a;
}

bool valid(int ** a, int i, int j, int x, int y, int n, int m) {
  return (i >= 0) && (i < n) && (j >= 0) && (j < m) && (a[i][j] == a[x][y]) && !marked[i][j];
}

int mark(int ** a, int i, int j, int n, int m) {
  queue< pair<int, int> > q;
  q.push(make_pair(i, j));
  marked[i][j] = true;
  int x, y, count = 0;
  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    count++;
    if (valid(a, x + 1, y, x, y, n, m)) {marked[x + 1][y] = true; q.push(make_pair(x + 1, y));}
    if (valid(a, x - 1, y, x, y, n, m)) {marked[x - 1][y] = true; q.push(make_pair(x - 1, y));}
    if (valid(a, x, y + 1, x, y, n, m)) {marked[x][y + 1] = true; q.push(make_pair(x, y + 1));}
    if (valid(a, x, y - 1, x, y, n, m)) {marked[x][y - 1] = true; q.push(make_pair(x, y - 1));}
  }
  return count;
}

int count(int ** a, int n, int m, int total) {
  int pro = 0;
  int reg = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
	  if (!marked[i][j]) {
	    pro += mark(a, i, j, n, m);
	    reg++;
	    if (pro == total)
	      return reg;
	  }
  return reg;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n;
  h = create(n, n);
  c = create(n, n);
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      h[i][j] = s[j];
      if (s[j] == 'G')
        c[i][j] = 'R';
      else 
        c[i][j] = s[j];
    }
  }
  marked = creabl(n, n);
  cout << count(h, n, n, n * n) << " ";
  marked = creabl(n, n);
  cout << count(c, n, n, n * n) << "\n";
  return 0;
}

