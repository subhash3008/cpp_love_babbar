#include <iostream>
#include <string>

using namespace std;

int get_length(char str[])
{
  int len = 0;
  for (int i = 0; str[i] != '\0'; ++i)
  {
    len++;
  }
  return len;
}

void reverse_char_str(char str[])
{
  int start = 0;
  int end = get_length(str) - 1;
  while (start <= end)
  {
    swap(str[start++], str[end--]);
  }
}

char to_lowercase(char ch)
{
  if (ch >= 'a' && ch <= 'z')
  {
    return ch;
  }
  else if (ch >= 'A' && ch <= 'Z')
  {
    return (ch - 'A' + 'a');
  }
}

bool check_palindrome(char str[])
{
  int start = 0;
  int end = get_length(str) - 1;

  bool res = true;
  while (start <= end)
  {
    if (to_lowercase(str[start]) != to_lowercase(str[end]))
    {
      res = false;
      break;
    }
    start++;
    end--;
  }
  return res;
}

bool valid_char(char ch)
{
  bool res = false;
  if ((ch >= 'a' && ch <= 'z') ||
    (ch >= '0' && ch <= '9') ||
    (ch >= 'A' && ch <= 'Z'))
  {
    res = true; 
  }
  return res;
}

bool check_valid_palindrome(char str[])
{
  int start = 0;
  int end = get_length(str) - 1;

  bool res = true;
  while (start <= end)
  {
    while (!valid_char(str[start]))
    {
      start++;
    }
    while (!valid_char(str[end]))
    {
      end--;
    }
    if (to_lowercase(str[start]) != to_lowercase(str[end]))
    {
      res = false;
      break;
    }
    start++;
    end--;
  }
  return res;
}

string reverse_str(string str)
{
  string t_str = str;
  int start = 0;
  int end = t_str.length() - 1;
  while (start <= end)
  {
    swap(t_str[start++], t_str[end--]);
  }
  return t_str;
}

string reverse_words_in_str(string str)
{
  string temp_str = "";
  string res_string = "";
  int len = str.length();
  int i = 0;
  while(i < len)
  {
    while ((str[i] != ' ') && (str[i] != '\0'))
    {
      temp_str.push_back(str[i]);
      i++;
    }
    string r_str = reverse_str(temp_str);
    temp_str = "";
    res_string.append(r_str);
    res_string.push_back(' ');
    i++;
  }
  return res_string;
}

int main()
{
  
  string str = "Hello Who are you";
  // char str[100];
  // cout << "Enter the string : ";
  // cin >> str;

  // REVERSE
  // cout << "Str : " << str << endl;
  // reverse_char_str(str);
  // cout << "Reversed str : " << str;

  // PALINDROME
  // cout << "Str : " << str << endl;
  // bool is_palindrome = check_palindrome(str);
  // cout << (is_palindrome ? "Palindrome" : "Not a palindrome") << endl;

  // VALID PALINDROME
  // cout << "Str : " << str << endl;
  // bool is_valid_palindrome = check_valid_palindrome(str);
  // cout << (is_valid_palindrome ? "Valid Palindrome" : "Not a valid palindrome") << endl;

  // REVERSE WORDS IN A STRING
  cout << "Str : " << str << endl;
  string r_str = reverse_words_in_str(str);
  cout << "Reversed : " << r_str << endl;

  return 0;
}