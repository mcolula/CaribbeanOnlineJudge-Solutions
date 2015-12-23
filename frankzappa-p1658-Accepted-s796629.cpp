#include <cstdio> 

int * secuence;

int main() {
  int n, t, num, longest;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    secuence = new int[n];
    scanf("%d", &secuence[0]);
    longest = 0;
    for (int i = 1, j = 0; i < n; i++) {
      scanf("%d", &num);
      if (num > secuence[longest])
        secuence[++longest] = num;
      else { 
        for (j = longest; j >= 0; j--) {
          if (num > secuence[j])
            break;
	    }
        secuence[j + 1] = num; 
      }
    }
    printf("%d\n", longest + 1);
  }
  return 0;  
}
