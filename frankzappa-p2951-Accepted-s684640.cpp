#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

int main() {
  int num;
  string s;
  set<string> ks;
  set<string>::iterator it;
  it = ks.begin();
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    ks.insert(it, s);
  }
  cout << ks.size() << endl;
	return 0;
}

