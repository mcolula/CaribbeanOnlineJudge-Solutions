#include <cstdio>
#include <queue>

using namespace std;

typedef struct {
  int a;
  int b;
} match;

int classify(const match & m) {
  if (m.a == m.b)
    return 0;
  if (m.a >= m.b)
    return 1;
  return -1;
}

bool operator <(const match & m, const match & n) {
  return (m.b - m.a) > (n.b - n.a);
}

int main() {
  priority_queue<match> fail;
  int t, coin;
  int a, b, c;
  int total = 0;
  int ties  = 0;
  match m;
  scanf("%d %d", &t, &coin);
  while (t--) {
    scanf("%d %d", &a, &b);
    m.a = a;
    m.b = b;
    c = classify(m);
    if (c == 1) 
	  total += 3;
	if (c == 0)
	  ties++;
	if (c ==-1)
	  fail.push(m);
  }
  while (coin > 0 && ties > 0) {
	coin--;
	ties--;
	total += 3;
  }
  while (coin > 0 && !fail.empty()) {
    m = fail.top();
    fail.pop();
    if (coin == (m.b - m.a)) {
	  coin = 0;
	  total += 1;
	}
	if (coin > (m.b - m.a)) {
	  coin -= (m.b - m.a) + 1;
	  m.a = m.b + 1;
	  total += 3;
	}
	if (coin < (m.b - m.a))
	  coin = 0;
  }
  total += ties;
  printf("%d\n", total);
  return 0;
}

