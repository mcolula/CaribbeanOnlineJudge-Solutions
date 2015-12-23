#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int boxes(int items, int capacity, int * lookup) {
  if (capacity == 1)
    lookup[items - 1] = items;
  if (capacity >= items)
    lookup[items - 1] = 1;
  if (lookup[items - 1] == -1)
    if (items % 2 == 0)
	  lookup[items - 1] = 2 * boxes(items / 2, capacity, lookup);
    else 
      lookup[items - 1] = boxes(items / 2, capacity, lookup) + boxes(items - items / 2, capacity, lookup);
  return lookup[items - 1];
}

int main() {
  int t, n, c;
  int * table;
  cin >> t;
  while (t--) {
    cin >> n >> c;
    table = new int[n];
    fill_n(table, n, -1);
    cout << boxes(n, c , table) << endl;
  }
  return 0;
}

