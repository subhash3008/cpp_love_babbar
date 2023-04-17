#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  if (n <= 1)
  {
    return false;
  }
  for (int i = 2; i < n; ++i)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

// google : Sieve of Eratosthenes
int count_primes(int n)
{
  int count = 0;
  vector<bool> prime(n+1, true);
  prime[0] = prime[1] = false;

  for (int i = 2; i < n; ++i)
  {
    if (prime[i])
    {
      count++;
      for (int j = 2*i; j < n; j = j + i)
      {
        prime[j] = false;
      }
    }
  }
  return count;
}

// euclid's algorithm
int iterative_gcd(int a, int b)
{
  if (a == 0)
  {
    return b;
  }
  if (b == 0)
  {
    return a;
  }
  while (a != b)
  {
    if (a > b)
    {
      a = a - b;
    }
    else
    {
      b = b - a;
    }
  }
  return a;
}

// to find: (x^n)%m
int modular_exponentiation(int x, int n, int m)
{
  int res = 1;
  while (n > 0)
  {
    if (n & 1)
    { // odd
      res = (1LL * (res) * (x % m)) % m;
    }
    x = (1LL * (x % m) * (x % m)) % m;
    n = n >> 1;
  }
  return res;
}

int main()
{
  // int n;
  // cout << "Enter n : ";
  // cin >> n;
  // cout << "total number of prime numbers less than input are " << count_primes(n);
  
  // int n, m;
  // cout << "Enter n and m: ";
  // cin >> n;
  // cin >> m;
  // cout << "gcd : " << iterative_gcd(n, m);

  int x, n, m;
  cout << "Enter x, n and m: ";
  cin >> x;
  cin >> n;
  cin >> m;
  cout << modular_exponentiation(x, n, m);
}