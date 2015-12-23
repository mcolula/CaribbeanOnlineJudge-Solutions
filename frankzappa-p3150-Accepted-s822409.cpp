#include <algorithm>
#include <iostream>
#include <limits>

#define N  4
#define M 26

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int * histogram = new int[M];
  for (int i = 0; i < N; i++) {
    getline(cin >> ws, s);
    for (int j = 0; j < s.size(); j++)
      if (s[j] >= 'A' && s[j] <= 'Z')
        histogram[s[j] - 'A']++;
  }
  int m = *max_element(histogram, histogram + M);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < M; j++)
      if (histogram[j] == m - i) {
	    cout << "* ";
	    histogram[j]--;
	  }
	  else 
	    cout << "  ";
    cout << "\n";
  }
  for (int i = 0; i < M; i++)
    cout << (char)(i + 'A') << " ";
  cout << "\n";
  return 0;
}
