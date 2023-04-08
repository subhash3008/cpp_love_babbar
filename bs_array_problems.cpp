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

int main()
{
  // first_last_occurence_positions();
  peak_index_in_mountain();
}