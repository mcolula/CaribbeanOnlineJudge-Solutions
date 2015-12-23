#include <algorithm>
#include <cstdio>
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
  return ((i >= 0) && (i < n) && (j >= 0) && (j < m)) && marked[i][j];
}

int count(int i, int j, int n, int m) {
  queue< pair<int, int> > q;
  q.push(make_pair(i, j));
  marked[i][j] = false;
  int count = 0;
  int a, b;
  while (!q.empty()) {
    a = q.front().first;
    b = q.front().second;
    q.pop();
    count++;
    if (valid(a + 1, b, n, m)) {marked[a + 1][b] = false; q.push(make_pair(a + 1, b));}
    if (valid(a - 1, b, n, m)) {marked[a - 1][b] = false; q.push(make_pair(a - 1, b));}
    if (valid(a, b + 1, n, m)) {marked[a][b + 1] = false; q.push(make_pair(a, b + 1));}
    if (valid(a, b - 1, n, m)) {marked[a][b - 1] = false; q.push(make_pair(a, b - 1));}
  }
  return count;
}

int largest(int n, int m, int k) {
  int s = 0;
  int x = 0;
  int c = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (marked[i][j]) {
	    c  = count(i, j, n, m);
	    x  = max(x, c);
	    s += c;
	    if (s == k)
	      return x;
	  }
  return x;
}

int main() {
  int n, m, k;
  int i, j;
  scanf("%d %d %d", &n, &m, &k);	
  marked = create(n, m);
  for (int h = 0; h < k; h++) {
    scanf("%d %d", &i, &j);
    marked[i - 1][j - 1] = true;
  }
  printf("%d\n", largest(n, m, k));
  return 0;
}





