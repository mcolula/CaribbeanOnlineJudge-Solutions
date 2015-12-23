#include <algorithm>
#include <iostream>

using namespace std;

int * w;
int * v;
int ** table;

int ** create(int sz, int cp) {
  int ** table = new int*[sz];
  for (int i = 0; i < sz; i++) {
    table[i] = new int[cp];
    fill_n(table[i], cp, 0);
  }
  return table;
}

int revenue(int item, int capacity) {
  for (int i = item; i >= 0; i--)
    for (int j = 1; j <= capacity; j++)
      if (j >= w[i])
        table[j][i] = max(table[j][i + 1], v[i] + table[j - w[i]][i + 1]);
      else
        table[j][i] = table[j][i + 1];
  return table[capacity][0];
}



int main() {
  int t;
  int item;
  int capacity;
  int total = 0;
  cin >> t;
  while (t--) {
    cin >> item >> capacity;
    v = new int[item];
    w = new int[item];
    table = create(capacity + 1, item + 1);
    for (int i = 0; i < item; i++)
      cin >> w[i] >> v[i];
    total += revenue(item - 1, capacity);
  }
  cout << total << endl;
  return 0;
}
