#include <iostream>
using namespace std;

void print_array(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}


int first_occurence(int arr[], int len, int key)
{
  int start = 0;
  int end = len - 1;
  int mid = start + (end - start) / 2;
  int first_occ = -1;

  while (start <= end)
  {
    if (key == arr[mid])
    {
      first_occ = mid;
      end = mid - 1;
    }
    else if (key > arr[mid])
    {
      start = mid + 1;
    }
    else if (key < arr[mid])
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return first_occ;
}

int last_occurence(int arr[], int len, int key)
{
  int start = 0;
  int end = len - 1;
  int mid = start + (end - start) / 2;
  int last_occ = -1;

  while (start <= end)
  {
    if (key == arr[mid])
    {
      last_occ = mid;
      start = mid + 1;
    }
    else if (key > arr[mid])
    {
      start = mid + 1;
    }
    else if (key < arr[mid])
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return last_occ;
}

void first_last_occurence_positions()
{
  int arr[] = {0, 0, 1, 1, 2, 2, 2, 2, 5};
  // int arr[] = {2};
  // int arr[] = {0, 0, 0, 0};
  int len = 9;
  int key = 2;

  pair<int, int> p;
  p.first = first_occurence(arr, len, key);
  p.second = last_occurence(arr, len, key);
  
  print_array(arr, len);
  cout << "Key : " << key << endl;
  cout << "First occurence : " << p.first << endl;
  cout << "Last occurence : " << p.second << endl;
}


// finding peak element in a mountain array i.e.
// first the array would have ascending and then
// later descending elements. This plotted on a
// graph with index of array would make a mountain
// one way is to find max by linear search O(n)..
// this solution uses binary search O(log n)
void peak_index_in_mountain()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 10, 7, 4, 2, 1};
  int len = 9;

  int start = 0;
  int end = len - 1;
  int mid = start + (end - start) / 2;

  while (start < end)
  {
    // if ((arr[mid - 1] < arr[mid]) && (arr[mid] > arr[mid + 1]))
    // {
    //   cout << "Peak Element : " << arr[mid] << " at index : " << mid;
    //   break;
    // }
    // else if (arr[mid - 1] < arr[mid])
    // {
    //   start = mid + 1;
    // }
    // else if (arr[mid] > arr[mid + 1])
    // {
    //   end = mid - 1;
    // }

    // more efficient
    if (arr[mid] < arr[mid + 1])
    {
      start = mid + 1;
    }
    else
    {
      end = mid;
    }

    mid = start + (end - start) / 2;
  }
  cout << "Peak Element : " << arr[mid] << " at index : " << mid;
}

int pivot_in_arr(int arr[], int arr_len)
{
  int start = 0;
  int end = arr_len - 1;
  int mid = (start + (end - start) / 2);

  while (start < end)
  {
    if (arr[mid] > arr[0])
    {
      start = mid + 1;
    }
    else
    {
      end = mid;
    }
    mid = (start + (end - start) / 2);
  }

  cout << "Pivot is : " << arr[mid] << " at index " << mid << endl;
  return mid;
}

void search_in_sorted_rotated_arr()
{
  int arr[] = {7, 9, 1, 2, 3};
  int arr_len = 5;
  int key = 7;
  print_array(arr, arr_len);
  cout << "Key is : " << key << endl;

  int start = 0;
  int end = arr_len - 1;
  int pivot = pivot_in_arr(arr, arr_len);
  if (arr[pivot] <= key && key <= arr[end])
  {
    start = pivot;
  }
  else
  {
    end = pivot;
  }
  int mid = start + ((end - start) / 2);

  int res = -1;
  while (start <= end)
  {
    if (key == arr[mid])
    {
      res = mid;
      break;
    }
    else if (key > arr[mid])
    {
      start = mid + 1;
    }
    else if (key < arr[mid])
    {
      end = mid - 1;
    }
    mid = start + ((end - start) / 2);
  }
  if (res != -1)
  {
    cout << "Key found at index : " << res << endl;
  }
  else
  {
    cout << "Key not found" << endl;
  }
}

int bs_sqrt_int(int num)
{
  int start = 0;
  int end = num;
  int mid = start + ((end - start) / 2);

  int res = -1;
  while (start <= end)
  {
    int sq = mid * mid;
    if (sq == num)
    {
      res = mid;
      break;
    }
    else if (sq > num)
    {
      end = mid - 1;
    }
    else if (sq < num)
    {
      res = mid;
      start = mid + 1;
    }
    mid = start + ((end - start) / 2);
  }
  return res;
}

double bs_sqrt_decimal(int n, int precision, int int_sol)
{
  double factor = 1;
  double ans = int_sol;
  for (int i = 0; i < precision; ++i)
  {
    factor /= 10;
    for (double j = ans; j * j < n; j += factor)
    {
      ans = j;
    }
  }
  return ans;
}



//*********************************************************************
bool is_sol_possible(int arr[], int n, int m, int mid)
{
  int student_count = 1;
  int page_sum = 0;
  for (int i = 0; i < n; ++i)
  {
    if (page_sum + arr[i] <= mid)
    {
      page_sum += arr[i];
    }
    else
    {
      student_count++;
      if (student_count > m || arr[i] > mid)
      {
        return false;
      }
      page_sum = arr[i];
    }
  }
  return true;
}

// google : book allocation problem for description
int allocatebooks(int arr[], int n, int m)
{
  int start = 0;
  int sum = 0;

  for (int i = 0; i < n; ++i)
  {
    sum += arr[i];
  }
  int end = sum;
  int mid = start + ((end - start) / 2);

  int res = -1;
  while (start <= end)
  {
    if (is_sol_possible(arr, n, m, mid))
    {
      res = mid;
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
    mid = start + ((end - start) / 2);
  }
  return res;
}


//*********************************************************************
// google: painter's partition problem

bool is_painter_partition_possible(int arr[], int n, int m, int mid)
{
  int num_painter = 1;
  int num_blocks = 0;

  for (int i = 0; i < n; ++i)
  {
    if (num_blocks + arr[i] <= mid)
    {
      num_blocks += arr[i];
    }
    else
    {
      num_painter++;
      if (num_painter > m || arr[i] > mid)
      {
        return false;
      }
      num_blocks = arr[i];
    }
  }
  return true;
}

int painters_partition(int arr[], int n, int m)
{
  int start = 0;
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += arr[i];
  }
  int end = sum;
  int mid = start + ((end - start) / 2);

  int res = -1;
  while (start <= end)
  {
    if (is_painter_partition_possible(arr, n, m, mid))
    {
      res = mid;
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
    mid = start + ((end - start) / 2);
  }
  return res;
}

//*********************************************************************
// Aggressive bulls problem

bool is_bulls_possible(int arr[], int n, int m, int mid)
{
  int bull_count = 1;
  int last_stall = arr[0];

  for (int i = 0; i < n; ++i)
  {
    if ((arr[i] - last_stall) >= mid)
    {
      bull_count++;
      if (bull_count == m)
      {
        return true;
      }
      last_stall = arr[i];
    }
  }
  return false;
}

int aggressive_bulls(int arr[], int n, int m)
{
  int start = 0;
  int maxi = -1;
  for (int i = 0; i < n; ++i)
  {
    maxi = max(maxi, arr[i]);
  }
  int end = maxi;
  int mid = start + ((end - start) / 2);

  int res = -1;
  while (start <= end)
  {
    if (is_bulls_possible(arr, n, m, mid))
    {
      res = mid;
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = start + ((end - start) / 2);
  }
  return res;
}

int main()
{
  // first_last_occurence_positions();
  // peak_index_in_mountain();

  // int arr[] = {7, 9, 10, 12, 2, 4, 5};
  // int arr_len = 7;
  // pivot_in_arr();

  // search_in_sorted_rotated_arr();

  // int num = 102;
  // int int_sol = bs_sqrt_int(num);
  // double sol = bs_sqrt_decimal(num, 3, int_sol);
  // cout << "Root is " << sol << endl;

  // int arr[] = {10, 20, 30, 40};
  // int arr_len = 4;
  // int num_student = 2;
  // cout << "Result " << allocatebooks(arr, arr_len, num_student) << endl;

  // int arr[] = {5, 5, 5, 5};
  // int arr_len = 4;
  // int num_painter = 2;
  // cout << "Result " << painters_partition(arr, arr_len, num_painter) << endl;

  // ideally array is not sorted and needs to be sorted in processing
  int arr[] = {1, 2, 3, 4, 6};
  int arr_len = 5;
  int num_bulls = 2;
  cout << "Result " << aggressive_bulls(arr, arr_len, num_bulls) << endl;
}