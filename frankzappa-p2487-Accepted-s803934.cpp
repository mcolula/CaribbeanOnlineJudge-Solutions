#include <algorithm>	
#include <iostream>

using namespace std;

int * v;
int * w;
int * prev;
int * table;

int revenue(int item, int capacity) {
  for (int i = item; i >= 0; i--) {
    for (int j = 1; j <= capacity; j++)
      if (j >= w[i]) 
        table[j] = max(prev[j], v[i] + prev[j - w[i]]);
      else
        table[j] = prev[j];
    copy(table, table + capacity + 1, prev);
  }
  return table[capacity];
}

int main() {
  int n, m;
  cin >> n >> m;
  table = new int[m + 1]();
  prev = new int[m + 1]();
  v = new int[n]();
  w = new int[n]();
  for (int i = 0; i < n; i++)
    cin >> w[i] >> v[i]; 
  cout << revenue(n - 1, m) << endl;
}
