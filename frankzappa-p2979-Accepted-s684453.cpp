#include <iostream>
#include <cstdio>

using namespace std;

int count (int a[], int n) {
  int i, j = 0;
  for(i = 0; i < n; i++)
    if(a[i] != i + 1)
      j++;
  return j;
}

int main() {
	int t;
  int n;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    cout << count(a, n) << endl;  
  }
	return 0;
}
