#include <iostream>
#include <string>
#include <vector>

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

char get_max_occuring_char(string str)
{
  int arr[26];
  for (int i = 0; i < 26 ; ++i)
  {
    arr[i] = 0;
  }

  int len_str = str.length();
  for (int i = 0; i < len_str; ++i)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      arr[str[i] - 'a']++;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      arr[str[i] - 'A']++;
    }
  }

  int max = arr[0];
  int max_idx = 0;
  for (int i = 1; i < 26; ++i)
  {
    if (max < arr[i])
    {
      max = arr[i];
      max_idx = i;
    }
  }
  return 'a' + max_idx; 
}

string replace_spaces(string &str)
{
  string temp = "";
  
  for (int i = 0; i < str.length(); ++i)
  {
    if (str[i] == ' ')
    {
      temp.push_back('@');
      temp.push_back('4');
      temp.push_back('0');
    }
    else
    {
      temp.push_back(str[i]);
    }
  }
  return temp;
}

string remove_all_occurence_of_substring(string str, const string part)
{
  while (str.length() && (str.find(part) < str.length()))
  {
    str.erase(str.find(part), part.length());
  }
  return str;
}

// Checks if the permutation of the part exists in
// the provided input string.. e.g. permutation of 'ab'
// are 'ab' and 'ba'.. constraint: all letters in the
// string and part
bool check_count_equal(int arr[26], int arr2[26])
{
  for (int i = 0; i < 26; ++i)
  {
    if (arr[i] != arr2[i])
    {
      return false;
    }
  }
  return true;
}

bool does_permutation_exist(string part, string str)
{
  int count_part[26] = { 0 };
  // store count of each character
  for (int i = 0; i < part.length(); ++i)
  {
    count_part[part[i] - 'a']++;
  }

  // now traverse str in window of size part and compare
  int i = 0;
  int count_str[26] = { 0 };
  int window_size = part.length();

  while ((i < window_size) && (i < str.length()))
  {
    count_str[str[i] - 'a']++;
    i++;
  }

  if (check_count_equal(count_part, count_str))
  {
    return true;
  }

  while (i < str.length())
  {
    count_str[str[i] - 'a']++;
    count_str[str[i - window_size] - 'a']--;
    i++;

    if (check_count_equal(count_part, count_str))
    {
      return true;
    }
  }

  return false;
}

string remove_adjacent_duplicates(string str)
{
  int count_removal = 0;
  do
  {
    int i = 0;
    count_removal = 0;
    while (i < str.length())
    {
      if (str[i + 1] && (str[i] == str[i + 1]))
      {
        str.erase(i, 2);
        count_removal++;
        cout << "Iteration : " << i << " string : " << str << endl;
        continue;
      }
      ++i;
    }
  } while (count_removal);
  return str;
}

// returns length of compressed string
int compress_string(vector<char>& chars)
{
  cout << "Input length " << chars.size() << endl; 
  int i = 0;
  int ansIndex = 0;
  int n = chars.size();

  while (i < n)
  {
    int j = i + 1;
    while (j < n && (chars[i] == chars[j]))
    {
      j++;
    }
    
    // store the initial character
    chars[ansIndex++] = chars[i];
    int count = j - i;
    if (count > 1)
    {
      // convert count into single digit and put it in the vector
      string cnt = to_string(count);
      for (char ch: cnt)
      {
        chars[ansIndex++] = ch;
      }
    }
    i = j;
  }
  cout << "vector : ";
  for (int i = 0; i < ansIndex; ++i)
  {
    cout << chars[i];
  }
  cout << endl;
  return ansIndex;
}

int main()
{
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
  // string str = "Hello Who are you";
  // cout << "Str : " << str << endl;
  // string r_str = reverse_words_in_str(str);
  // cout << "Reversed : " << r_str << endl;

  // MAXIMUM OCCURENCE
  // string str;
  // cin >> str;
  // char ch = get_max_occuring_char(str);
  // cout << "Max occuring char : " << ch << endl;

  // REPLACE SPACES
  // string str;
  // getline(cin, str);
  // string newstr = replace_spaces(str);
  // cout << "New String : " << newstr << endl;

  // REMOVE ALL OCCURENCES OF A SUBSTRING
  // string str, part;
  // cout << "Enter the sentence : ";
  // getline(cin, str);
  // cout << "Enter substring : ";
  // getline(cin, part);
  // string res = remove_all_occurence_of_substring(str, part);
  // cout << "Resulting string : " << res;

  // PERMUTATION IN STRING
  // string str, part;
  // cout << "Enter the sentence : ";
  // getline(cin, str);
  // cout << "Enter substring : ";
  // getline(cin, part);
  // cout << "Does permutation exist : " << (does_permutation_exist(part, str) ? "Yes" : "No");

  // REMOVE ADJACENT DUPLICATE CHARACTERS
  // string str;
  // getline(cin, str);
  // string res = remove_adjacent_duplicates(str);
  // cout << "Res : " << res;

  // STRING COMPRESSION.. Leetcode 443 for description
  vector<char> vec = {'a', 'a', 'b', 'c', 'c', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'e', 'e', 'e'};
  cout << "Res: " << compress_string(vec);


  return 0;
}