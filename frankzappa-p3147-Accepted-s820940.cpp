#include <iostream>

using namespace std;


int count(int * a, int * b, int n) {
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      b[j - i] += a[j];
      if (b[j - i] == 0) return true;
	}
  return false;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  int zero;
  cin >> t;
  while(t--){
    cin >> n;
    int * a = new int[n]();
    int * b = new int[n]();
    for (int i = 0; i < n; i++)
	  cin >> a[i];
    if (count(a, b, n))
      cout << "YES\n";
    else
      cout << "NO\n";
    delete[] a;
  }
}

