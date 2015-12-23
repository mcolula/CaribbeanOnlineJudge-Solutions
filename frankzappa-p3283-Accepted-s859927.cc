#include <iostream>
#include <cstdlib>

using namespace std;

#define L   2 * n
#define R   2 * n + 1
#define INC 2  // Increasing     seq
#define NON 1  // Non-decreasing seq
#define NEI 0  // Neither
#define NIL 4  // Null value

typedef struct {
  int fst;
  int lst;
  int seq;
} sequence;

void init(sequence * s, int * input, int lo, int hi, int n) {
  if (lo >= hi) {
    s[n] = {input[lo], input[lo], INC}; 
    return;
  }
  int mi = (lo + hi) / 2;
  init(s, input, lo, mi + 0, L);
  init(s, input, mi + 1, hi, R);
  sequence l = s[L];
  sequence r = s[R];
  if (l.seq == NEI || r.seq == NEI || l.lst >  r.fst) {
    s[n] = {l.fst, r.lst, NEI};
    return;
  }
  if (l.seq == NON || r.seq == NON || l.lst == r.fst) {
    s[n] = {l.fst, r.lst, NON};
    return;
  }
  s[n] = {l.fst, r.lst, INC};
}

sequence query(sequence * s, int lo, int hi, int i, int j, int n) {
  if (i <= lo && j >= hi)
    return s[n];
  if (i >  hi || j <  lo)
    return {0, 0, NIL };
  int mi = (lo + hi) / 2;
  sequence l = query(s, lo, mi + 0, i, j, L);
  sequence r = query(s, mi + 1, hi, i, j, R);
  if (l.seq == NIL)
    return r;
  if (r.seq == NIL)
    return l;
  if (l.seq == NEI || r.seq == NEI || l.lst >  r.fst)
    return {l.fst, r.lst, NEI};
  if (l.seq == NON || r.seq == NON || l.lst == r.fst)
    return {l.fst, r.lst, NON};
  return {l.fst, r.lst, INC};
}

void update(sequence * s, int idx, int val, int lo, int hi, int n) {
  if (idx < lo || idx > hi)
    return;
  if (lo == hi) {
    s[n] = {val, val, INC};
    return;
  }
  int mi = (lo + hi) / 2;
  update(s, idx, val, lo, mi + 0, L);
  update(s, idx, val, mi + 1, hi, R);
  sequence l = s[L];
  sequence r = s[R];
  if (l.seq == NEI || r.seq == NEI || l.lst >  r.fst) {
    s[n] = {l.fst, r.lst, NEI};
    return;
  }
  if (l.seq == NON || r.seq == NON || l.lst == r.fst) {
    s[n] = {l.fst, r.lst, NON};
    return;
  }
  s[n] = {l.fst, r.lst, INC};
}


sequence * create(int * input, int n) {
  sequence * s = new sequence[4 * n]();
  init(s, input, 0, n - 1, 1);
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, o, i, j;
  cin >> n;
  cin >> m;
  int * a = new int[n]();
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sequence * s = create(a, n);
  while (m--) {
    cin >> o >> i >> j;
    if (o == 1)
      update(s, i - 1, j, 0, n - 1, 1);
    else
      cout << query(s, 0, n - 1, i - 1, j - 1, 1).seq << "\n";
  }    
  return 0;
}
