#include <iostream>
#include <cstdio>
#include <cmath>
typedef struct {
  int x;
  int y;
} point;

double dist(point * a, point * b) {
  int x = a->x - b->x;
  int y = a->y - b->y;
  return sqrt(pow(x, 2) + pow(y, 2));
}

point min_dist(point * cows, int n) {
  point pair;
  double aux;
  double m = 1 / 0.0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      aux = dist(&cows[i], &cows[j]);
      if (aux < m) {
        m = aux;
        pair.x = i;
        pair.y = j;
	  }
    }
  return pair;
}


int main() { 
  int t = 0;
  scanf("%d", &t);
  int n = t;
  int i = 0;
  point cows[t];
  while (t--) {
    scanf("%d %d", &cows[i].x, &cows[i].y);
    i++;
  }
  point pair = min_dist(cows, n);
  printf("%d %d\n", pair.x + 1, pair.y + 1);
  return 0;
}

