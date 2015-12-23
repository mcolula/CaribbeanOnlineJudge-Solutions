#include <iostream>
#include <queue>

using namespace std;

typedef struct {
  int i;
  int j;
  int w;
} point;

bool ** marked;
int  ** weight;

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

point new_point(int i, int j, int w) {
  point p;
  p.i = i;
  p.j = j;
  p.w = w;
  return p;
}

bool operator<(const point &p, const point &q) {
  return p.w == q.w ? p.j < q.j : p.w > q.w;
}

bool valid(int i, int j, int n, int m) {
  return (i >= 0) && (i < n) && (j >= 0) && (j < m) && !marked[i][j];
}

int search(int n, int m) {
  priority_queue<point> pq;
  for (int i = 0; i < n; i++) {
    pq.push(new_point(i, 0, weight[i][0]));
    marked[i][0] = true;
  }
  int i, j, w; 
  while (!pq.empty()) {
    i = pq.top().i;
    j = pq.top().j;
    w = pq.top().w; pq.pop();
    if (j == m - 1) return w;
    if (valid(i + 1, j, n, m)) { marked[i + 1][j] = true; pq.push(new_point(i + 1, j, w + weight[i + 1][j])); }
    if (valid(i - 1, j, n, m)) { marked[i - 1][j] = true; pq.push(new_point(i - 1, j, w + weight[i - 1][j])); }
    if (valid(i, j + 1, n, m)) { marked[i][j + 1] = true; pq.push(new_point(i, j + 1, w + weight[i][j + 1])); }
    if (valid(i, j - 1, n, m)) { marked[i][j - 1] = true; pq.push(new_point(i, j - 1, w + weight[i][j - 1])); }
  }
  return -1;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  weight = create(n, m);
  marked = creabl(n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> weight[i][j];
  cout << search(n, m) << "\n";
  return 0;
}

