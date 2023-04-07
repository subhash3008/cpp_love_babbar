#include <iostream>

void fibonacci()
{
  int n;
  std::cin >> n;

  int a = 0, b = 1;
  std::cout << "Fibonacci : " << a << std::endl;
  std::cout << "Fibonacci : " << b << std::endl;
  for (int i = 2; i <= n; ++i)
  {
    int fib = a + b;
    std::cout << "Fibonacci : " << fib << std::endl;

    a = b;
    b = fib;
  }
}

void prime()
{
  int n;
  std::cin >> n;

  bool isPrime = true;
  for (int i = 2; i < n; ++i)
  {
    if (n % i == 0)
    {
      std::cout << "Not a prime number.." << std::endl;
      isPrime = false;
      break;
    }
  }

  if (isPrime)
  {
    std::cout << "Number is prime number";
  }
}

int main()
{
  // fibonacci();
  prime();
}