#include <iostream>
#include <utility>
#include <cstring>
#include <queue>

#define J second
#define I first

using namespace std;

int sides8 = 0;
int sides6 = 0;
int sides4 = 0;
bool ** marked;
bool ** canvas;

typedef pair<int, int> pii;

bool ** create(int n, int m) {
  bool ** a = new bool*[n]();
  for (int i = 0; i < n; i++)
    a[i] = new bool[m]();
  return a;
}

int inner(pii p) {
  int i = p.I;
  int j = p.J;
  int total = 0;
  if (!canvas[i][j - 1] && !canvas[i - 1][j] && !canvas[i - 1][j - 1]) total++; // Upper L corner
  if (!canvas[i][j + 1] && !canvas[i - 1][j] && !canvas[i - 1][j + 1]) total++; // Upper R corner
  if (!canvas[i][j + 1] && !canvas[i + 1][j] && !canvas[i + 1][j + 1]) total++; // Lower R corner
  if (!canvas[i][j - 1] && !canvas[i + 1][j] && !canvas[i + 1][j - 1]) total++; // Lower L corner
  return total;
}

int outer(pii p) {
  int i = p.I;
  int j = p.J;
  int total = 0;
  if (canvas[i][j - 1] && canvas[i - 1][j] && !canvas[i - 1][j - 1]) total++; // Upper L corner
  if (canvas[i][j + 1] && canvas[i - 1][j] && !canvas[i - 1][j + 1]) total++; // Upper R corner
  if (canvas[i][j + 1] && canvas[i + 1][j] && !canvas[i + 1][j + 1]) total++; // Lower R corner
  if (canvas[i][j - 1] && canvas[i + 1][j] && !canvas[i + 1][j - 1]) total++; // Lower L corner
  return total;
}

int corners(int i, int j) {
  int total = 0;
  queue<pii>  q;
  q.push(make_pair(i, j));
  marked[i][j] =  true;
  while (!q.empty()) {
    pii p = q.front(); q.pop();
    int i = p.I; int j = p.J;
    total += outer(p); total += inner(p);
    if (!marked[i + 1][j + 0]) {marked[i + 1][j + 0] = true; q.push(make_pair(i + 1, j + 0));}
    if (!marked[i + 0][j + 1]) {marked[i + 0][j + 1] = true; q.push(make_pair(i + 0, j + 1));}
    if (!marked[i - 1][j + 0]) {marked[i - 1][j + 0] = true; q.push(make_pair(i - 1, j + 0));}
    if (!marked[i + 0][j - 1]) {marked[i + 0][j - 1] = true; q.push(make_pair(i + 0, j - 1));}
  }
  return total;
}

void count(int n, int m) {
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
      if (!marked[i][j]) {
        int c = corners(i, j);       
        if (c == 4) sides4++;
        if (c == 6) sides6++;
        if (c == 8) sides8++;
      }
}

int main() {
  char   a;
  int n, m;
  cin >> n;
  cin >> m;
  marked = create(n + 2, m + 2);
  canvas = create(n + 2, m + 2);
  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < m + 2; j++)
      marked[i][j] = true;
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++) {
      cin >> a; 
      if (a == '0') { 
        canvas[i][j] = true ;
        marked[i][j] = false;
      }
    }
  count(n, m);
  cout << sides4 << " " << sides6 << " " << sides8 << "\n";
  return 0;
}
