#include <utility>
#include <cstdio>

using namespace std;

typedef pair<int, int> grid;


grid reduce(int a, int b) {
  if (a < b)
    return make_pair(a % 2 == 0 ? 2 : 1, b);
  if (b < a)
    return make_pair(a, b % 2 == 0 ? 2 : 1);
  else
    return make_pair(a % 2 == 0 ? 2 : 1, b % 2 == 0 ? 2 : 1);
}

char direction(grid g) {
  if (g.first == 1 && g.second >= 1) return 'R';
  if (g.first >= 1 && g.second == 1) return 'D';
  if (g.first == 2 && g.second >= 1) return 'L';
  if (g.first >= 1 && g.second == 2) return 'U';
}



int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
	  scanf("%d %d", &n, &m);
	  printf("%c\n", direction(reduce(n, m)));
	}	
	return 0;
}

