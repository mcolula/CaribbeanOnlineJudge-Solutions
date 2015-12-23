#include <iostream>
#include <cstring>
#include <cstdio>

#define ans(p) p ? "Yes" : "No" 

using namespace std;

bool sub_sec(const char * s, const char * t) {
  int j = 0;
  for (int i = 0; i < strlen(t); i++)
    if (s[j] == t[i])
      j++;
  return j == strlen(s);
}


int main() {
  char s[30];
  char t[30];
	while(scanf("%s %s", s, t) != EOF)
    printf("%s\n", ans(sub_sec(s, t)));
  return 0;
}
  
