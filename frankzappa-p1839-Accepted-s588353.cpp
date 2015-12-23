#include <iostream>

using namespace std;

int calcularNaranjas(int naranjas)
{
	  cout << 8 * naranjas + 42 << endl;
    return 0;
}

int main()
{
  int a, b;
  cin >> a;
  for(int i = 0; i < a; i++)
  {
    cin >> b;
    calcularNaranjas(b);
  }
  return 0;
}
