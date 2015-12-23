#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int lazyUnitSum(string s) {
  int aux_num = 0;
  char buff[1000];
  while(s.size() > 1) {
    aux_num = 0;
    for(int i = 0; i < s.size(); i++) {
      aux_num += s[i] - '0';
    }
    sprintf(buff, "%d", aux_num);
    s = buff;
  }
  return s[0] - '0';
}

int  main() { 
  int tests;
  string s;
  if(scanf("%d", &tests) == 0);
    while(tests--) {
      cin  >> s;
      cout << lazyUnitSum(s) << endl;
    }
  return 0;
}

