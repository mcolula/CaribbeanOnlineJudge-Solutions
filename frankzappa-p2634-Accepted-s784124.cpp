#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstdio>

using namespace std;

int month(const string & s) {
  int index[2];
  int j = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '/') {
      index[j] = i + 1;
      j++;
    }
  return atoi(s.substr(index[0], index[1] - index[0] - 1).c_str());
}

int main() {
  int months[12] = { 0 };
  string id, date;
  int t;
  scanf("%d", &t);
  while (t--) {
    cin >> id;
    cin >> date;
    months[month(date) - 1]++;
  }
  for (int i = 0; i < 12; i++)
    printf("%d %d\n", i + 1, months[i]);
  return 0;
}

