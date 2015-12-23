#include <algorithm>
#include <iostream>

using namespace std;

int n;
int ** value;
int ** table;

int sum(int n) {
  table[0][0] = value[0][0];
  for(int i = 1; i < n; i++)
    for (int j = 0; j <= i; j++)
      if (j == 0)
        table[i][j] = value[i][j] + table[i - 1][j];
      else
        table[i][j] = value[i][j] + max(table[i - 1][j], table[i - 1][j - 1]);
  return *max_element(table[n - 1], table[n - 1] + n);
}


int ** create(int n)  {
  int ** a = new int*[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[i]();
  return a;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 0) {
	  cout << "0" << endl;
	  return 0;  
    }
    value = create(n);
    table = create(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++)
        cin >> value[i][j];
    cout << sum(n) << endl;
  }
  return 0;
}

	
