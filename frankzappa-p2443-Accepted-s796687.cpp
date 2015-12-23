#include <algorithm>
#include <utility>
#include <cstdio>
#include <vector>

using namespace std;


bool primes[100] = {false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, false, false, false, false, true, false, true, false, false, false, false, false, true, false, false, false, true, false, true, false, false, false, true, false, false, false, false, false, true, false, false, false, false, false, true, false, true, false, false, false, false, false, true, false, false, false, true, false, true, false, false, false, false, false, true, false, false, false, true, false, false, false, false, false, true, false, false, false, false, false, false, false, true, false, false};


int count_primes(int * a, int n) {
  int count  = 0;
  for (int i = 0; i < n; i++)
    if (primes[a[i]])
      count++;
  return count;
}


int main() {
  int t, k, r;
  vector<pair<int, int> > rank(2);
  int * ns;
  scanf("%d", &t);
  scanf("%d", &k);
  ns = new int[k];
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < k; j++)
      scanf("%d", &ns[j]);
    r = count_primes(ns, k);
    for (int k = 0; k < rank.size(); k++)
      if (r > rank[k].second) {
        rank[k].first  = i;
        rank[k].second = r;
        break;
      }
  }
  if (rank[0].second == rank[1].second) 
    printf("No winner\n");
  else 
    printf("Object %d wins with %d rare characteristics\n", rank[0].first + 1, rank[0].second);
  return 0;
}

