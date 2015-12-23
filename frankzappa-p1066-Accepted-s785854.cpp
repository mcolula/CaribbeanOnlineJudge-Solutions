#include <cstdio>
#include <cmath>

#define PI 3.141592653589793

double cper(int n, double r) {
  return 2 * n * r * tan(PI / n);
}

double iper(int n, double r) {
  return 2 * n * r * sin(PI / n);
}


int main() {
	int t;
	int n;
	double r;
	scanf("%d", &t);
	while (t--) {
	  scanf("%lf %d", &r, &n);
	  printf("%.4lf %.4lf\n", iper(n, r), cper(n, r));
	}
	return 0;
}

