#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> vec)
{
  for (int el:vec)
  {
    cout << el << " ";
  }
  cout << endl;
}

vector<int> reverse_vector(vector<int> v)
{
  int start = 0;
  int end = v.size() - 1;
  while (start <= end)
  {
    swap(v[start], v[end]);
    start++;
    end--;
  }
  return v;
}

vector<int> reverse_vector_after_m(vector<int> v, int m)
{
  int start = m + 1;
  int end = v.size() - 1;
  while (start <= end)
  {
    swap(v[start], v[end]);
    start++;
    end--;
  }
  return v;
}

vector<int> merge_sorted(vector<int> v1, int n1, vector<int> v2, int n2)
{
  vector<int> res;
  int i = 0, j = 0;
  while ((i < n1) && (j < n2))
  {
    if (v1[i] < v2[j])
    {
      res.push_back(v1[i++]);
    }
    else if (v1[i] > v2[j])
    {
      res.push_back(v2[j++]);
    }
  }
  while (i < n1)
  {
    res.push_back(v1[i++]);
  }
  while (j < n2)
  {
    res.push_back(v2[j++]);
  }
  return res;
}

void move_zeros(vector<int> &v)
{
  int non_zero_idx = 0;
  for (int j = 0; j < v.size(); ++j)
  {
    if(v[j] != 0)
    {
      swap(v[j], v[non_zero_idx++]);
    }
  }
}

void rotate_vector(vector<int> &v, int k)
{
  int n = v.size();
  vector<int> temp(n);
  for (int i = 0; i < n; ++i)
  {
    temp[(i + k) % n] = v[i];
  }
  v = temp;
}

bool check_sorted_rotated(vector<int> v)
{
  int count = 0;
  int n = v.size();
  for (int i = 1; i < n; ++i)
  {
    if (v[i - 1] > v[i])
    {
      count++;
    }
  }
  if (v[n - 1] > v[0])
  {
    count++;
  }
  return count <= 1;
}

vector<int> sum_vect(vector<int> v1, vector<int> v2)
{
  int i = v1.size() - 1;
  int j = v2.size() - 1;
  int carry = 0;

  vector<int> ans;

  while (i >= 0 && j >= 0)
  {
    int sum = v1[i--] + v2[j--] + carry;
    carry = sum / 10;
    sum = sum % 10;

    ans.push_back(sum);
  }

  while (i >= 0)
  {
    int sum = v1[i--] + carry;
    carry = sum / 10;
    sum = sum % 10;

    ans.push_back(sum);
  }

  while (j >= 0)
  {
    int sum = v2[j--] + carry;
    carry = sum / 10;
    sum = sum % 10;

    ans.push_back(sum);
  }

  while (carry)
  {
    int sum = carry;
    carry = sum / 10;
    sum = sum % 10;
    ans.push_back(sum);
  }

  ans = reverse_vector(ans);
  return ans;
}

int main()
{
  // REVERSE
  // vector<int> v;
  // v.push_back(11);
  // v.push_back(7);
  // v.push_back(3);
  // v.push_back(12);
  // v.push_back(4);

  // cout << "Brfore reverse : " << endl;
  // print_vector(v);
  // int m = 1;
  // vector<int> ans = reverse_vector_after_m(v, m);
  // cout << "After reverse : " << endl;
  // print_vector(ans);

  // MERGE SORTED
  // vector<int> num1{1, 3, 5, 7, 9};
  // vector<int> num2{2, 4, 6, 8, 10, 12};

  // print_vector(num1);
  // print_vector(num2);
  // cout << "Merging..." << endl; 
  // vector<int> res = merge_sorted(num1, num1.size(), num2, num2.size());
  // print_vector(res);

  // MOVE ZEROS
  // vector<int> vec{0, 1, 0, 3, 12, 0};
  // print_vector(vec);
  // move_zeros(vec);
  // print_vector(vec);

  // ROTATE ARRAY
  // vector<int> vec{-1, -100, 3, 7, 11, 4, 5, 6, 8, 9, 10};
  // int k = 2;
  // print_vector(vec);
  // rotate_vector(vec, k);
  // cout << "Rotating Vector" << endl;
  // print_vector(vec);

  // CHECK SORTED ROTATED
  // vector<int> vec1{1, 2, 3, 4, 5, 6};
  // vector<int> vec2{3, 4, 5, 6, 1, 2};
  // vector<int> vec3{3, 4, 5, 6, 1, 7};

  // cout << "Is sorted rotated vec1?? " << check_sorted_rotated(vec1) << endl;
  // cout << "Is sorted rotated vec2?? " << check_sorted_rotated(vec2) << endl;
  // cout << "Is sorted rotated vec3?? " << check_sorted_rotated(vec3) << endl;

  // SUM TWO ARRAYS
  vector<int> vec1{1, 2, 3, 4};
  vector<int> vec2{9, 9};

  vector<int> res = sum_vect(vec1, vec2);
  print_vector(res);
}