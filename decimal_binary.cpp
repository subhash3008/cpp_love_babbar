#include <iostream>
#include <math.h>
using namespace std;

void binary_rep()
{
  int n;
  cin >> n;

  if (n < 0)
  {
    n = ~n;
    n += 1;
  }

  int res = 0;
  int i = 0;
  while (n)
  {
    int digit = n & 1;
    res = (digit * pow(10, i)) + res;
    n = n >> 1;
    ++i;
  }
  cout << "Binary is : " << res << endl;
}

void decimal_value()
{
  int n;
  cin >> n;

  int res = 0;
  int i = 0;
  while (n)
  {
    int bit = n % 10;
    if (bit)
    {
      res += pow(2, i);
    }
    n = n / 10;
    ++i;
  }
  cout << "Decimal Value is : " << res << endl;
}

int main()
{
  // binary_rep();
  decimal_value();
}