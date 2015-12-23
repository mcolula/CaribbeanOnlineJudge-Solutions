#include <cstdio>
#include <queue>

using namespace std;

int main() {
  priority_queue< int, vector<int>, greater<int> > pq;
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    pq.push(n);
  }
  while (!pq.empty()) {
    n = pq.top();
    pq.pop();
    printf("%d\n", n); 
  }
  return 0;
}
