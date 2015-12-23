#include <cstdio>

typedef struct {
  double x;
  double y;
} pair;


bool color(pair * dim, pair * pro, pair * p, bool c) {
	
  double xlimit = dim->x * pro->x;
  double ylimit = dim->y * pro->y;
  
  if (p->y >  ylimit && p->x <= xlimit)
    return c;
    
  else if (p->y <= ylimit && p->x >  xlimit)
    return c;
    
  else if (p->y <= ylimit && p->x <= xlimit) {
    dim->x = xlimit;
    dim->y = ylimit;
    return color(dim, pro, p, !c);
  }
  
  else {
    dim->x -= xlimit;
    dim->y -= ylimit;
    p->x -= xlimit;
    p->y -= ylimit;
    return color(dim, pro, p, !c);
  }
      
}

int main() {
  pair dim;
  pair aux;
  pair pro;
  pair p;
  int  t = 0;
  int  i = 1;
  while (true) {
    scanf("%lf %lf %lf %lf", &dim.y, &dim.x, &pro.y, &pro.x);
    if (dim.x == dim.y && dim.y == pro.x && pro.x == pro.y && pro.y == 0)
      return 0;
    scanf("%d", &t);
    printf("Case %d:\n", i);
    while (t--) {
	  aux.x = dim.x;
	  aux.y = dim.y;
	  scanf("%lf %lf", &p.y, &p.x);
	  if (color(&aux, &pro, &p, false))
	    printf("white\n");
	  else
	    printf("black\n");
	}
	i++;
  }
  return 0;
}

