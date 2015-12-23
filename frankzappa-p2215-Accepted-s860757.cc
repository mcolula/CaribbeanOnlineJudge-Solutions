#include <iostream>
#include <queue>

using namespace std;

#define pii pair<int, int>
#define y second
#define x first


bool ** create(int n) {
  bool ** a = new bool*[n]();
  for (int i = 0; i < n; i++)
    a[i] = new bool[n]();
  return a;
}

#define M 8

int ms[M][2] = {{ 2,  0},
                   { 3,  0},
                   {-2,  0},
                   {-3,  0},
                   { 0,  2},
                   { 0,  3},
                   { 0, -2},
                   { 0, -3}};

bool valid(bool ** a, int i, int j, int n) {
  return (i >= 0 && i < n && j >= 0 && j < n) && !a[i][j];
}

int count(bool ** a, int n) {
  vector<pii> v; 
  v.push_back({0, 0});
  a[0][0] = true;
  int total = n * n - 1;
  int k = 0;
  while (v.size() > 0 && total > 0) {
    queue<pii> q;
    for (auto i: v)
      q.push(i);
    v.clear();
    while (!q.empty() && total > 0) {
      pii p = q.front(); q.pop();
      for (int i = 0; i < M; i++)
        if (valid(a, p.x - ms[i][0], p.y - ms[i][1], n)) {
          v.push_back({p.x - ms[i][0], p.y - ms[i][1]});
          a[p.x - ms[i][0]][p.y - ms[i][1]] = true;
          total--;
        }
    }
    k++;
  }
  return total > 0 ? -1 : k;
}


int main() {
  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    bool ** a = create(m);
    cout << count(a, m) << "\n";
  }
  return 0;
}
