
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

///////////////////////////////////////////////////////
// Merge sort

// int count = 0;             // for inversion count
void merge_sorted_arr(int arr[], int start, int end)
{
  int mid = start + ((end - start) / 2);
  int len1 = mid - start + 1;
  int len2 = end - mid;

  int *first = new int[len1];
  int *second = new int[len2];

  int mainArrIndex = start;
  for (int i = 0; i < len1; ++i)
  {
    first[i] = arr[mainArrIndex++];
  }

  mainArrIndex = mid + 1;
  for (int i = 0; i < len2; ++i)
  {
    second[i] = arr[mainArrIndex++];
  }

  int index1 = 0;
  int index2 = 0;
  mainArrIndex = start;
  while (index1 < len1 && index2 < len2)
  {
    if (first[index1] < second[index2])
    {
      arr[mainArrIndex++] = first[index1++];
    }
    else
    {
      // count += (len1 - index1);      // for inversion count
      arr[mainArrIndex++] = second[index2++];
    }
  }

  while (index1 < len1)
  {
    arr[mainArrIndex++] = first[index1++];
  }

  while (index2 < len2)
  {
    arr[mainArrIndex++] = second[index2++];
  }

  delete[] first;
  delete[] second;
}

void merge_sort(int arr[], int start, int end)
{
  if (start >= end)
  {
    return;
  }

  int mid = start + ((end - start) / 2);

  // sort left part
  merge_sort(arr, start, mid);

  // sort right
  merge_sort(arr, mid + 1, end);

  // merge sorted array
  merge_sorted_arr(arr, start, end);
}


int main()
{
  // int arr[] = {32, 46, 58, 17, 21, 9, 82};
  int arr[] = {8, 4, 2, 1};
  int size = 4;

  print_array(arr, size);
  cout << "Sorting..." << endl;
  // bubble_sort(arr, size);
  // selection_sort(arr, 0, size);
  // insertion_sort(arr, 1, size);
  merge_sort(arr, 0, size - 1);
  print_array(arr, size);

  cout << "inverted count : " << count << endl;

  return 0;
}
