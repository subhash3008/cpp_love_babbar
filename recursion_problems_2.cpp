#include <iostream>
#include <string>

using namespace std;

//////////////////////////////////////////
// Reverse string
void reverse(string &str, int start, int end)
{
  if (start >= end)
  {
    return;
  }
  swap(str[start++], str[end--]);
  reverse(str, start, end);
}

//////////////////////////////////////////
// Palindrome
bool palindrome(string str, int start, int end)
{
  if (start >= end)
  {
    return true;
  }
  if (str[start++] != str[end--])
  {
    return false;
  }
  return palindrome(str, start, end);
}

///////////////////////////////////////////
// Find power
long long int find_pow(long long int num, int power)
{
  if (power == 1)
  {
    return num;
  }
  
  long long int ans = find_pow(num, power / 2);

  if (power & 1)
  {
    // odd
    return num * ans * ans;
  }
  else
  {
    // even
    return ans * ans;
  }
}

int main()
{
  // string s;
  // getline(cin, s);
  // cout << "Entered : " << s << endl;
  // reverse(s, 0, s.length() - 1);
  // cout << "Reversed : " << s << endl;

  
  // string s;
  // getline(cin, s);
  // cout << "Entered : " << s << endl;
  // cout << "Is Palindrome : " << (palindrome(s, 0, s.length() - 1) ? "Yes" : "No") << endl;

  // long long int num;
  // int power;
  // cout << "Enter number and power: ";
  // cin >> num;
  // cin >> power;
  // cout << "Res : " << find_pow(num, power) << endl;

  return 0;
}