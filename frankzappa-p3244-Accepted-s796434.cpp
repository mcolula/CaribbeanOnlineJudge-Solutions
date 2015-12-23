#include <cstdio>

int modulo(int a, int m) { return a >= 0 ? a % m : modulo(a + m, m); }

int find_max(int * slice, int size) {
  int max = 0;
  int aux = 0;
  for (int i = 0; i < size + 3; i++) {
    aux += slice[modulo(i, size)];
    if (i > 3) 
	  aux -= slice[modulo(i - 4, size)];
    if (aux >= max)
      max = aux;
  }
  return max;
}


int main() {
  int n = 8; 
  int * pizza = new int[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &pizza[i]);
  printf("%d\n", find_max(pizza, n));
  return 0;
}

