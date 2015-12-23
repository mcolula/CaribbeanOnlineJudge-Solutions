#include <iostream>

using namespace std;

int calcularNaranjas(int n)
{
  int naranjas;
  if(n == 0)
	return 0;
  else
  { 
	cin >> naranjas;
	cout << 8 * naranjas + 42 << endl;
	return calcularNaranjas(n - 1);
  }
	
}

int main()
{
  int a;
  cin >> a;
  calcularNaranjas(a);
  return 0;
}
