#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef struct {
  int x;
  int y;
  int w; 
} point;

point goal;

point crea(int x, int y, int w) {
  point p;
  p.x = x;
  p.y = y;
  p.w = w;
  return p;
}

int dist(point p, point q) {
  return pow(p.x - q.x, 2) + pow(p.y - q.y, 2);
}

bool operator <(const point & p, const point & q) { 
  int distP = dist(p, goal);
  int distQ = dist(q, goal);
  if (distP == distQ)
    return p.w > q.w;
  else
    return distP > distQ;
}

bool valid(int y, int x, int n) {
  return x < n && y < n && x >= 0 && y >= 0;
}

vector<point> next(point * p, bool ** visited, int n) {
  vector<point> ps;
  int x = p->x;
  int y = p->y;
  int w = p->w;
  if (valid(y, x - 1, n) && !visited[y][x - 1]) {
	visited[y][x - 1] = true;
    ps.push_back(crea(x - 1, y, w + 1));
  }
  if (valid(y, x + 1, n) && !visited[y][x + 1]) {
    visited[y][x + 1] = true;
    ps.push_back(crea(x + 1, y, w + 1));
  }
  if (valid(y - 1, x, n) && !visited[y - 1][x]) {
	visited[y - 1][x] = true;
    ps.push_back(crea(x, y - 1, w + 1));
  }
  if (valid(y + 1, x, n) && !visited[y + 1][x]) {
	visited[y + 1][x] = true;
    ps.push_back(crea(x, y + 1, w + 1));
  }
  return ps;
}

int search(point * start, bool ** visited, int n) {
  priority_queue<point> pq;
  pq.push(*start);
  vector<point> neighbors;
  point current;
  while (!pq.empty()) {
    current = pq.top();
    pq.pop();
    neighbors = next(&current, visited, n);
    for (auto & i : neighbors) {
      pq.push(i);
    }
    if (current.x == goal.x && current.y == goal.y)
      return current.w;
  }
  return -1;
}

bool ** init(int n) {
  bool ** a = new bool*[n];
  for (int i = 0; i < n; i++)
    a[i] = new bool[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = false;
  return a;
}

int main() {
  int size;
  char c;
  point start; 
  cin >> size;
  bool ** v = init(size);
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) {
	  cin >> c;
	  if (c == 'm') {
	    v[i][j] = true;
	    start = crea(j, i, 0);
	  }
	  if (c == '#') {
	    goal = crea(j, i, 0);
	  }
	  if (c == '*') {
	    v[i][j] = true;  
	  }
	}
  cout << search(&start, v, size) << endl;
  return 0;
}
