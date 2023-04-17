#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<vector<int>> vect)
{
  for (int row = 0; row < vect.size(); ++row)
  {
    vector<int> v_row = vect.at(row);
    for (int col = 0; col < v_row.size(); ++col)
    {
      cout << v_row.at(col) << " ";
    }
    cout << endl;
  }
}

bool is_present(int arr[][3], int target, int rowCount, int colCount)
{
  for (int row = 0; row < rowCount; ++row)
  {
    for (int col = 0; col < colCount; ++col)
    {
      if (target == arr[row][col])
      {
        return true;
      }
    }
  }
  return false;
}

void print_row_sum(int arr[][3], int rowCount, int colCount)
{
  int sum = 0;
  for (int row = 0; row < rowCount; ++row)
  {
    for (int col = 0; col < colCount; ++col)
    {
      sum += arr[row][col];
    }
    cout << "Sum for row " << row << " is " << sum << "." << endl;
    sum = 0;
  }
}

int larget_sum_row(int arr[][3], int rowCount, int colCount)
{
  int arr_sum[rowCount] = { 0 };
  int sum = 0;
  for (int row = 0; row < rowCount; ++row)
  {
    for (int col = 0; col < colCount; ++col)
    {
      sum += arr[row][col];
    }
    arr_sum[row] = sum;
    sum = 0;
  }

  int max = INT_MIN;
  int maxIndex = 0;
  for (int i = 0; i < rowCount; ++i)
  {
    if (max < arr_sum[i])
    {
      max = arr_sum[i];
      maxIndex = i;
    }
  }

  return maxIndex;
}

void print_like_wave(vector<vector<int>> vect, int nRows, int mCols)
{
  for (int col = 0; col < mCols; ++col)
  {
    if (col & 1)
    {
      // odd -> bottom to top
      for (int row = nRows - 1; row >= 0; --row)
      {
        cout << vect[row][col] << " ";
      }
    }
    else
    {
      // even -> top to bottom
      for (int row = 0; row < nRows; ++row)
      {
        cout << vect[row][col] << " ";
      }
    }
    cout << endl;
  }
}

vector<int> print_spiral(vector<vector<int>> vect)
{
  vector<int> ans;

  int nRows = vect.size();
  int mCols = vect[0].size();

  int count = 0;
  int total = nRows * mCols;

  int startingRow = 0;
  int startingCol = 0;
  int endingRow = nRows - 1;
  int endingCol = mCols - 1;

  while (count < total)
  {
    // starting row
    for (int idx = startingCol; count < total && idx <= endingCol; ++idx)
    {
      ans.push_back(vect[startingRow][idx]);
      count++;
    }
    startingRow++;

    // ending col
    for (int idx = startingRow; count < total && idx <= endingRow; ++idx)
    {
      ans.push_back(vect[idx][endingCol]); 
      count++;
    }
    endingCol--;

    // ending row
    for (int idx = endingCol; count < total && idx >= startingCol; --idx)
    {
      ans.push_back(vect[endingRow][idx]); 
      count++;
    }
    endingRow--;

    // starting col
    for (int idx = endingRow; count < total && idx >= startingRow; --idx)
    {
      ans.push_back(vect[idx][startingCol]); 
      count++;
    }
    startingCol++;
  }
  return ans;
}

vector<vector<int>> rotate_by_90_degree(vector<vector<int>> vect)
{
  vector<vector<int>> res;
  int nRows = vect.size();
  int mCols = vect[0].size();

  for (int col = 0; col < mCols; ++col)
  {
    vector<int> v_row;
    for (int row = nRows - 1; row >= 0; --row)
    {
      v_row.push_back(vect[row][col]);
    }
    res.push_back(v_row);
  }
  return res;
}


// vector should be sorted row wise and every start of row 
// should be more than end of previous row for ascending order
bool binary_search(vector<vector<int>> vect, int target)
{
  int row = vect.size();
  int col = vect[0].size();

  int start = 0;
  int end = (row * col - 1);

  int mid = start + ((end - start) / 2);

  while (start <= end)
  {
    int el = vect[mid/col][mid%col]; 
    if (el == target)
    {
      return true;
    }
    else if (el < target)
    {
      start = mid + 1;
    }
    else if (el > target)
    {
      end = mid - 1;
    }
    mid = start + ((end - start) / 2);
  }
  return false;
}


// elements in both rows and columns are sorted 
bool search_element_sorted_2(vector<vector<int>> vect, int target)
{
  int row = vect.size();
  int col = vect[0].size();

  int rowIndex = 0;
  int colIndex = col - 1;

  while ((rowIndex < row) && (colIndex >= 0))
  {
    int el = vect[rowIndex][colIndex];
    if (el == target)
    {
      return true;
    }
    else if (el < target)
    {
      rowIndex++;
    }
    else if (el > target)
    {
      colIndex--;
    }
  }
  return false;
}

int main()
{
  // int arr[3][4] = {{1, 11, 111, 1111}, {2, 22, 222, 2222}, {3, 33, 333, 3333}};
  int arr[3][3];

  // Take input
  // cout << "Enter the elements : " << endl;
  // for (int row = 0; row < 3; ++row)
  // {
  //   for (int col = 0; col < 3; ++col)
  //   {
  //     cin >> arr[row][col];
  //   }
  // }

  // display elements
  // cout << "Printing the elements.." << endl;
  // for (int row = 0; row < 3; ++row)
  // {
  //   for (int col = 0; col < 3; ++col)
  //   {
  //     cout << arr[row][col] << " ";
  //   }
  //   cout << endl;
  // }

  // Search
  // cout << "Enter the element to search : ";
  // int target;
  // cin >> target;

  // if (is_present(arr, target, 3, 4))
  // {
  //   cout << "Element found";
  // }
  // else
  // {
  //   cout << "Element not found";
  // }

  // print_row_sum(arr, 3, 3);

  // int row_num = larget_sum_row(arr, 3, 3);
  // cout << "Largest sum exist in row " << row_num << endl;

  vector<vector<int>> vect;
  int r = 3;
  int c = 3;
  cout << "enter the elements : ";
  for (int row = 0; row < r; ++row)
  {
    vector<int> v_row;
    for (int col = 0; col < c; ++col)
    {
      int temp;
      cin >> temp;
      v_row.push_back(temp);
    }
    vect.push_back(v_row);
  }
  cout << "Printing..." << endl;
  print_vector(vect);

  // print_like_wave(vect, r, c);

  // vector<int> res = print_spiral(vect);
  // for (int i = 0; i < res.size(); ++i)
  // {
  //   cout << res.at(i) << " ";
  // }
  // cout << endl;

  // cout << "Rotating..." << endl;
  // print_vector(rotate_by_90_degree(vect));

  cout << "Element to search : ";
  int target_el;
  cin >> target_el;

  // cout << (binary_search(vect, target_el) ? "Found" : "Not found") << endl;
  cout << (search_element_sorted_2(vect, target_el) ? "Found" : "Not found") << endl;

  return 0;
}