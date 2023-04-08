// binary search works only on monotonic functions
// i.e. elements are in either increasing or
// decreasing order

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

int search_binary(int arr[], int len, int key)
{
  int res = -1;
  int start = 0;
  int end = len - 1;
  // int mid = (start + end) / 2;
  // to avoid overflow when both start and end are at int limits
  int mid = start + ((end - start) / 2);

  while (start <= end)
  {
    if (key == arr[mid])
    {
      res = mid;
      break;
    }
    else if (key < arr[mid])
    {
      end = mid - 1;
    }
    else if (key > arr[mid])
    {
      start = mid + 1;
    }
    mid = start + ((end - start) / 2);
  }
  return res;
}

int main()
{
  int arr_even[] = {5, 11, 13, 17, 19, 27};
  int arr_odd[] = {3, 8, 11, 14, 16};
  int arr_even_len = 6;
  int arr_odd_len = 5;
  int key = 16;

  print_array(arr_even, arr_even_len);
  int index = search_binary(arr_even, arr_even_len, key);
  if (-1 == index)
  {
    cout << "Key not found." << endl;
  }
  else
  {
    cout << "Key found at index " << index << endl;
  }

  print_array(arr_odd, arr_odd_len);
  index = search_binary(arr_odd, arr_odd_len, key);
  if (-1 == index)
  {
    cout << "Key not found." << endl;
  }
  else
  {
    cout << "Key found at index " << index << endl;
  }
}