#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <typename T>
void print_vect(vector<T> vect)
{
  for (int i = 0; i < vect.size(); ++i)
  {
    cout << vect[i] << " ";
  }
  cout << endl;
}

template <typename T>
void print_vect_vect(vector<vector<T>> vect)
{
  for (int i = 0; i < vect.size(); ++i)
  {
    for (int j = 0; j < vect[i].size(); ++j)
    {
      cout << vect[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

///////////////////////////////////////
// next smaller element
// input: [2, 1, 4, 3]
// output: [1, -1, 3, -1]
vector<int> find_next_smaller(vector<int> vect)
{
  stack<int> st;
  st.push(-1);
  vector<int> res(vect.size());

  int n = vect.size();
  for (int i = n - 1; i >= 0; --i)
  {
    int curr = vect[i];
    while (st.top() >= curr)
    {
      st.pop();
    }
    res[i] = st.top();
    st.push(curr);
  }
  return res;
}

////////////////////////////////////////////////
// Find largest area of rectangle in histogram

vector<int> next_smaller(vector<int> vect)
{
  stack<int> st;
  st.push(-1);
  vector<int> res(vect.size());

  int n = vect.size();
  for (int i = n - 1; i >= 0; --i)
  {
    int curr = vect[i];
    while (st.top() != -1 && vect[st.top()] >= curr)
    {
      st.pop();
    }
    res[i] = st.top();
    st.push(i);   // store index
  }
  return res;
}

vector<int> prev_smaller(vector<int> vect)
{
  stack<int> st;
  st.push(-1);
  vector<int> res(vect.size());

  for (int i = 0; i < vect.size(); ++i)
  {
    int curr = vect[i];
    while (st.top() != -1 && vect[st.top()] >= curr)
    {
      st.pop();
    }
    res[i] = st.top();
    st.push(i);   // store index
  }
  return res;
}

int largest_rect_area(vector<int> hist)
{
  int n = hist.size();
  vector<int> next(n);
  next = next_smaller(hist);

  vector<int> prev(n);
  prev = prev_smaller(hist);

  int area = -1;
  for (int i = 0; i < n; ++i)
  {
    int len = hist[i];
    if (next[i] == -1)
    {
      next[i] = n;
    }
    int breadth = next[i] - prev[i] - 1;

    int new_area = len * breadth;
    area = max(area, new_area);
  }

  return area;
}

////////////////////////////////////////////
// Celebrity problem

int check_celebrity(vector<vector<int>> celebIndex, int n)
{
  // Fill a stack
  stack<int> st;
  for (int i = 0; i < n; ++i)
  {
    st.push(i);
  }

  // check for potential celebrity
  while (st.size() > 1)
  {
    int a = st.top();
    st.pop();

    int b = st.top();
    st.pop();

    if (celebIndex[a][b] == 1)
    {
      st.push(b);
    }
    // else if (knows(celebIndex, b, a))
    else
    {
      st.push(a);
    }
  }

  // verify the celebrity
  int p_celeb = st.top();

  int zero_count = 0;
  for (int j = 0; j < n; j++)
  {
    if (celebIndex[p_celeb][j] == 0)
    {
      zero_count++;
    }
  }
  if (zero_count != n)
  {
    return -1;
  }

  int one_count = 0;
  for (int i = 0; i < n; ++i)
  {
    if (celebIndex[i][p_celeb] == 1)
    {
      one_count++;
    }
  }
  if (one_count != (n - 1))
  {
    return -1;
  }

  return p_celeb;
}

//////////////////////////////////////////////////
// Maximum Rectangular area in a binary matrix
// - solution makes use of laregst area in histagram solution

int get_max_rect_area_binary_mat(vector<vector<int>> mat)
{
  int n = mat.size();
  int m = mat[0].size();
  int area = largest_rect_area(mat[0]);

  for (int i = 1; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      // update row
      if (mat[i][j] != 0)
      {
        mat[i][j] += mat[i - 1][j];
      }
      else
      {
        mat[i][j] = 0;
      }
    }
    area = max(area, largest_rect_area(mat[i]));
  }
  return area;
}

int main()
{
  // find next smaller element
  // vector<int> vect{2, 1, 4, 3};
  // print_vect(vect);
  // vector<int> res = find_next_smaller(vect);
  // print_vect(res);

  // area of largest rectangle in a histogram
  // vector<int> hist{2, 1, 5, 6, 2, 3};
  // int area = largest_rect_area(hist);
  // cout << "Largest area : " << area << endl;

  // celebrity problem
  // vector<vector<int>> celebIndex{
  //   {0, 1, 0},
  //   {0, 0, 0},
  //   {0, 1, 0}
  // };
  // // vector<vector<int>> celebIndex{
  // //   {0, 1},
  // //   {1, 0}
  // // };
  // print_vect_vect(celebIndex);
  // int celeb = check_celebrity(celebIndex, celebIndex[0].size());
  // cout << "Celebrity is:: " << celeb << endl;

  // max rectangle area in binary matrix
  vector<vector<int>> mat{
    {0, 1, 1, 0},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1}
  };
  print_vect_vect(mat);
  int area = get_max_rect_area_binary_mat(mat);
  cout << "Maximum rectangular area : " << area << endl;

  return 0;
}