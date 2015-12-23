#include <cstdio>

int prime[34] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
  53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,  103, 107, 109, 113, 127, 
  131, 137, 139};
  
bool is_prime(int n) {
  for (int i = 0; i < 33; i++) {
	if (n < prime[i]) break;
    if (n % prime[i] == 0 && n != prime[i])
      return false;
  }
  return true;
}

int max_factor(int n) {
  if (n == 2) return 2;
  int max = n;
  int i = 0;
  do {
    if (max % prime[i] == 0) {
      max /= prime[i]; 
      i = 0;
    }
    else 
      i++;	 
  } while (!is_prime(max));
  return max;
}


int main() {  
  int n;
  int t;
  int max = 0;
  int num = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if(max_factor(n) > max) {
	  max = max_factor(n);
	  num = n;
	}
  }
  printf("%d\n", num);
  return 0;
}

