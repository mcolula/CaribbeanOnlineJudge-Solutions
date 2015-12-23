#include <iostream>
#include <cmath>

using namespace std;

double solve(double b, double c) {
  return (-b + sqrt(b * b - 4 * c)) / 2; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, b;
  cin >> r;
  cin >> b;
  int w = ceil(solve(-2 - r / 2.0, r + b));
  cout << max(w, (r + b) / w) << " " << min(w, (r + b) / w) << endl;
  return 0;
}
