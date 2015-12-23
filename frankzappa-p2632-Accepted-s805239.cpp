#include <algorithm>
#include <cstdio>

using namespace std;

int ** create(int n) {
  int ** a = new int*[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[n]();
  return a;
}

int ** t1;
int ** t2;

void read(int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) {
	  scanf("%d", &t1[i][j]);
	  t2[i][j] = t1[i][j] * t1[i][j];
	}  
}

int letter(int n, int ** t) {
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= i; j++)
      if (j == 0)
        t[i][j] += t[i - 1][j];
      else
        t[i][j] += max(t[i - 1][j], t[i - 1][j - 1]);
  return *max_element(t[n - 1], t[n - 1] + n);
}

int main() {
  int n;
  scanf("%d", &n);
  t1 = create(n);
  t2 = create(n);
  read(n);
  int n1 = letter(n, t2);
  int n2 = letter(n, t1);
  printf("%d %d\n%c%c\n", n1, n2, n1 % 26 + 'a', n2 % 26 + 'a'); 
}
