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

/////////////////////////////////////////////////
// SELECTION SORT
/////////////////////////////////////////////////

// Space : O(1)
// Time: O(n^2)
// Use case: where arr_len is small and memory constraints exist
// [64, 25, 12, 22, 11]
// [11, 25, 12, 22, 64]
// [11, 12, 25, 22, 64]
// [11, 12, 22, 25, 64]
// [11, 12, 22, 25, 64]
void selection_sort(int arr[], int arr_len, int order)
{
  cout << "Selection Sort :: " << endl;
  for (int i = 0; i < (arr_len - 1); ++i)
  {
    for (int j = i + 1; j < arr_len; ++j)
    {
      int minIndex = i;
      if (order == 1)
      {
        if (arr[j] < arr[minIndex])
        {
          minIndex = j;
        }
      }
      else if (order == -1)
      {
        if (arr[j] > arr[minIndex])
        {
          minIndex = j;
        }
      }
      swap(arr[i], arr[minIndex]);
    }
  }
}


/////////////////////////////////////////////////
// BUBBLE SORT
/////////////////////////////////////////////////

// Every ith round, ith largest element reaches
// to end.. Array is sorted in (n-1) rounds
// Space : O(1)
// time : O(n^2)
// [6, 2, 8, 4, 10]
// [2, 6, 4, 8, 10]
// [2, 4, 6, 8, 10]
// [2, 4, 6, 8, 10]
// [2, 4, 6, 8, 10]
void bubble_sort (int arr[], int arr_len, int order)
{
  cout << "Bubble Sort :: " << endl;
  for (int i = 0; i < (arr_len - 1); ++i)
  {
    for (int j = 0; j < (arr_len - 1 - i); ++j)
    {
      if (order == 1)
      {
        if (arr[j] > arr[j + 1])
        {
          swap(arr[j], arr[j + 1]);
        }
      }
      else if (order == -1)
      {
        if (arr[j] < arr[j + 1])
        {
          swap(arr[j], arr[j + 1]);
        }
      }
    }
  }
}


/////////////////////////////////////////////////
// INSERTION SORT
/////////////////////////////////////////////////

// Number of iterations: (n - 1)
// Time Complexity: O(n^2), Best Case: O(n)
// [10, 1, 7, 4, 8, 2, 11]
// [1, 10, 7, 4, 8, 2, 11]
// [1, 7, 10, 4, 8, 2, 11]
// [1, 4, 7, 10, 8, 2, 11]
// [1, 4, 7, 8, 10, 2, 11]
// [1, 2, 4, 7, 8, 10, 11]
// [1, 2, 4, 7, 8, 10, 11]
void insertion_sort(int arr[], int arr_len, int order)
{
  cout << "Insertion Sort :: " << endl;
  for (int i = 1; i < arr_len; ++i)
  {
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0)
    {
      if (order == 1)
      {
        if (arr[j] > temp)
        {
          arr[j + 1] = arr[j];
        }
        else
        {
          break;
        }
      }
      else if (order == -1)
      {
        if (arr[j] < temp)
        {
          arr[j + 1] = arr[j];
        }
        else
        {
          break;
        }
      }
      j--;
    }
    arr[j + 1] = temp;
  }
}


int main()
{
  int arr[] = {29, 72, 98, 13, 87, 66, 52, 51, 36};
  int arr_len = 9;
  int order = -1;

  // print_array(arr, arr_len);
  // selection_sort(arr, arr_len, order);
  // print_array(arr, arr_len);

  // print_array(arr, arr_len);
  // bubble_sort(arr, arr_len, order);
  // print_array(arr, arr_len);

  print_array(arr, arr_len);
  insertion_sort(arr, arr_len, order);
  print_array(arr, arr_len);

  return 0;
}