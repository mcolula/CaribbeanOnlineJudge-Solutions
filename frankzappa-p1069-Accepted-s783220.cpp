#include <iostream>
#include <cstdio>

using namespace std;

int bottles(int n, int c) {
  if (c < 2) return 0;
  if (n < c) return 0;
  return n / c + bottles(n / c + (n % c), c);
}


int main(){
  int t;
  int e, f, c;
  scanf("%d", &t);
  while (t--) { 
    scanf("%d %d %d", &e, &f, &c);
    printf("%d\n", bottles(e + f, c));
  }
  return 0;
}
