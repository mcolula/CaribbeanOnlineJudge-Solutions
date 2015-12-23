#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef unsigned long long int ull;

void rotate(char * s, int n, int k) {
  for (int i = 0; i < n; i++)
    printf("%c", s[(i + n - k) % n]);
  printf("\n");
}

int main() {
  ull n, t;
  char s[100];
  scanf("%llu", &t);
  while (t--) {
	strcpy(s, "");
    scanf("%llu", &n);
    scanf("%s",  s);
    rotate(s, strlen(s), n % strlen(s));
  }
}
