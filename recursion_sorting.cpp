
#include <iostream>

using namespace std;

void print_array(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

//////////////////////////////////////////////////
// bubble sort
void bubble_sort(int arr[], int n)
{
  if (n == 1)
  {
    return;
  }
  for (int i = 0; i < n - 1; ++i)
  {
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
    }
  }
  bubble_sort(arr, n - 1);
}

////////////////////////////////////////////
// selection sort
void selection_sort(int arr[], int start, int n)
{
  if (start == n)
  {
    return;
  }

  int minIndex = start;
  for (int i = start + 1; i < n; ++i)
  {
    if (arr[i] < arr[minIndex])
    {
      minIndex = i;
    }
  }
  swap(arr[start], arr[minIndex]);
  selection_sort(arr, start + 1, n);
}

///////////////////////////////////////////////
// Insertion Sort
void insertion_sort(int arr[], int start, int n)
{
  if (start == n)
  {
    return;
  }

  int temp = arr[start];
  int j = start - 1;
  while (j >= 0)
  {
    if (arr[j] > temp)
    {
      arr[j + 1] = arr[j];
    }
    else
    {
      break;
    }
    j--;
  }
  arr[j + 1] = temp;

  insertion_sort(arr, start + 1, n);
}


int main()
{
  int arr[] = { 3, 2, 4, 6, 5, 8, 7, 11, 9};
  int size = 9;

  print_array(arr, size);
  cout << "Sorting..." << endl;
  // bubble_sort(arr, size);
  // selection_sort(arr, 0, size);
  insertion_sort(arr, 1, size);
  print_array(arr, size);

  return 0;
}
