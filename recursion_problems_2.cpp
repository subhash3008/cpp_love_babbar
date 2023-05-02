#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_2d_int_vec(vector<vector<int>> vec)
{
  cout << "[" << endl;
  for (int i = 0; i < vec.size(); ++i)
  {
    vector<int> row = vec[i];
    cout << "\t[";
    for (int j = 0; j < row.size(); ++j)
    {
      cout << row[j] << " ";
    }
    cout << "]," << endl;
  }
  cout << "]";
}

void print_string_vec(vector<string> vec)
{
  cout << "[";
  for (int i = 0; i < vec.size(); ++i)
  {
    cout << (vec[i].empty() ? "\"\"" : vec[i]) << ", ";
  }
  cout << "]";
}

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

/////////////////////////////////////
// get powerset for input array

void get_subsets(
  vector<int>& nums,
  vector<int> output, 
  int index,
  vector<vector<int>>& ans)
{
  // base case
  if (index >= nums.size())
  {
    ans.push_back(output);
    return;
  }

  // Exclude
  get_subsets(nums, output, index + 1, ans);

  // Include
  int el = nums[index];
  output.push_back(el);
  get_subsets(nums, output, index + 1, ans);
}

/////////////////////////////////////////////
// Subsequence of a string
void get_subsequence(string str, string output, int index, vector<string>& res)
{
  if (index >= str.length())
  {
    res.push_back(output);
    return;
  }

  // Exclude
  get_subsequence(str, output, index + 1, res);

  // Include
  char ch = str[index];
  output.push_back(ch);
  get_subsequence(str, output, index + 1, res);
}

///////////////////////////////////////////////
// Phone Keypad Mapping string subsets

void phone_mapping_subsets(string digits, string out, int index, vector<string>& res, vector<string> mapping)
{
  // base case
  if (index >= digits.length())
  {
    res.push_back(out);
    return;
  }

  int num = digits[index] - '0';
  string value = mapping[num];

  for (int i = 0; i < value.length(); ++i)
  {
    out.push_back(value[i]);
    phone_mapping_subsets(digits, out, index + 1, res, mapping);
    // remove last lette or else it would be added to next output
    out.pop_back();
  }
}

////////////////////////////////////////////////
// Permutations
void permutations(string str, vector<string>& res, int index)
{
  // base case
  if (index >= str.length())
  {
    res.push_back(str);
    return;
  }

  for (int i = index; i < str.length(); ++i)
  {
    swap(str[i], str[index]);
    permutations(str, res, index + 1);

    // backtrack
    swap(str[i], str[index]);
  }
}

///////////////////////////////////////////////////
// RAT IN A MAZE

bool is_path_possible(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> m)
{
  if (((x >= 0 && x < n) && (y >= 0 && y < n)) &&
    (visited[x][y] == 0) &&
    (m[x][y] == 1))
  {
    return true;
  }
  return false;

}

void get_path(
  vector<vector<int>>& m,
  int n,
  vector<string>& res,
  int x,
  int y,
  vector<vector<int>> visited,
  string path)
{
  // base case
  if ((x == n - 1) && (y == n - 1))
  {
    res.push_back(path);
    return;
  }

  visited[x][y] = 1;

  // 4 Possible paths - Down, Left, Right, Up
  int new_x, new_y;
  // Down
  new_x = x + 1;
  new_y = y;
  if (is_path_possible(new_x, new_y, n, visited, m))
  {
    path.push_back('D');
    get_path(m, n, res, new_x, new_y, visited, path);
    path.pop_back();
  }

  // Left
  new_x = x;
  new_y = y - 1;
  if (is_path_possible(new_x, new_y, n, visited, m))
  {
    path.push_back('L');
    get_path(m, n, res, new_x, new_y, visited, path);
    path.pop_back();
  }

  // Up
  new_x = x - 1;
  new_y = y;
  if (is_path_possible(new_x, new_y, n, visited, m))
  {
    path.push_back('D');
    get_path(m, n, res, new_x, new_y, visited, path);
    path.pop_back();
  }

  // Right
  new_x = x;
  new_y = y + 1;
  if (is_path_possible(new_x, new_y, n, visited, m))
  {
    path.push_back('R');
    get_path(m, n, res, new_x, new_y, visited, path);
    path.pop_back();
  }

  visited[x][y] = 0;
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

  // Powerset
  // vector<int> nums{1, 2, 3};

  // vector<vector<int>> ans;
  // vector<int> output;
  // int index = 0;
  // get_subsets(nums, output, index, ans);
  // print_2d_int_vec(ans);

  // Subsequence
  // string str = "abc";

  // vector<string> res;
  // string output;
  // int index = 0;

  // get_subsequence(str, output, index, res);
  // print_string_vec(res);

  // Phone Keypad Mapping string subsets
  // string digits = "78";
  // vector<string> res;
  // string output;
  // int index = 0;
  // vector<string> mappings{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  // phone_mapping_subsets(digits, output, index, res, mappings);
  // print_string_vec(res);

  // permutations
  // vector<string> res;
  // string str = "abc";
  // int index = 0;
  // permutations(str, res, index);
  // print_string_vec(res);

  // RAT IN A MAZE
  vector<vector<int>> maze
  {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
  };
  int n = 4;

  vector<string> res;
  string path = "";
  int src_x = 0;
  int src_y = 0;
  vector<vector<int>> visited = maze;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      visited[i][j] = 0;
    }
  }

  get_path(maze, n, res, src_x, src_y, visited, path);
  print_string_vec(res);

  return 0;
}