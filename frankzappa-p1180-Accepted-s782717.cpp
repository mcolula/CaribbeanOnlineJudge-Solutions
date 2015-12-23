#include <iostream>
#include <cstdio>

using namespace std;

int read_values(int * a, int n) {
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  return 0;
}

int result(int * a, int * b, int n) {
  for(int i = 0; i < n; i++)
    printf("%d ", a[i] - b[i]);
  printf("\n");
}

int main() {  
  int a[6] = {1, 1, 2, 2, 2, 8};
  int b[6];
  int n;
  scanf("%d", &n);
  while (n--) {
    read_values(b, 6);
    result(a, b, 6);
  } 
}
