#include <iostream>
#include <cstdio>

#define MAX 100

using namespace std;

typedef struct {
  int rows;
  int cols;
  int ** v;
} matrix;

int create(matrix * m, int r, int c) {
  m->cols = c;
  m->rows = r;
  m->v = new int*[MAX];
    for (int i = 0; i < r; i++)
      m->v[i] = new int[c];
  return 0;
}

int read(matrix * m) {
  int val;
  for (int i = 0; i < m->rows; i++)
    for (int j = 0; j < m->cols; j++) {
	  scanf("%d", &val);
	  m->v[i][j] = val;
	}
  return 0;
}

int print(matrix * m) {
  int val;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
	  printf("%d ", m->v[i][j]);
	}
    printf("\n");
  }
  return 0;
}

int mult(matrix * r, matrix * a, matrix * b) {
  if (a->cols != b->rows)
    return -1;
  create(r, a->rows, b->cols);
  for (int i = 0; i < r->rows; i++)
    for (int j = 0; j < r->cols; j++)
      for (int k = 0; k < a->cols; k++) {
	    r->v[i][j] += a->v[i][k] * b->v[k][j];
	  } 
  return 0;
}

int main() {
  matrix m, a, b;
  int c, r;
  scanf("%d %d", &r, &c);
  create(&a, r, c);
  read(&a);
  scanf("%d %d", &r, &c);
  create(&b, r, c);
  read(&b);
  if (!mult(&m, &a, &b)) 
    print(&m);
  else
    printf("The matrices can not be multiplied\n");
  return 0;
}

