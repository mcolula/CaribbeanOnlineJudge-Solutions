#include <cstdio>
#include <cmath>

using namespace std;

int main () { 
  int t;
  int x1, y1;
  int x2, y2;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%.0lf\n", abs(x1 - x2) + abs(y1 - y2));
  }
  return 0;
} 
