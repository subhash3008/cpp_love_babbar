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

// input : [1, 3, 2, 7, 11, 8]
// output : [3, 1, 7, 2, 8, 11]
void swap_alternate(int arr[], int size)
{
  for (int i = 0; i < size; i += 2)
  {
    if (i + 1 < size)
    {
      swap(arr[i], arr[i + 1]);
    }
  }
}

// array input size is n (odd) which has single unique
// number e.g 1 3 1 3 6 6 7 10 7
// output : 10
void find_unique(int arr[], int size)
{
  int xor_sum = 0;
  for (int i = 0; i < size; ++i)
  {
    xor_sum ^= arr[i];
  }
  cout << "Unique element is : " << xor_sum << endl;
}

// array contains n integers starting from 1 till
// n - 1, at least once. There is one integer twice.
// print the duplicate number
void find_duplicates(int arr[], int size)
{
  int max_num = size - 1;
  int expected_sum = (max_num * (max_num + 1)) / 2;
  int sum = 0;
  for (int i = 0; i < size; ++i)
  {
    sum += arr[i];
  }
  cout << "Duplicate number is : " << sum - expected_sum << endl;
}


void print_intersection(int arr1[], int arr2[], int arr1_size, int arr2_size)
{
  // cout << "[";
  // for (int i = 0; i < arr1_size; ++i)
  // {
  //   for (int j = 0; j < arr2_size; ++j)
  //   {
  //     if (arr1[i] < arr2[j])
  //     {
  //       break;
  //     }

  //     if (arr1[i] == arr2[j])
  //     {
  //       cout << arr1[i] << " ";
  //       arr2[j] = INT_MIN;
  //       break;
  //     }
  //   }
  // }
  // cout << "]";

  // optimized
  int i = 0;
  int j = 0;
  cout << "[";
  while (i < arr1_size && j < arr2_size)
  {
    if (arr1[i] == arr2[j])
    {
      cout << arr1[i] << " ";
      i++;
      j++;
    }
    else if (arr1[i] < arr2[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  cout << "]";
}


// print set of 2 numbers from array which result in
// same number as input expected_sum after addition 
void pair_sum(int arr[], int size, int expected_sum)
{
  for (int i = 0; i < size; ++i)
  {
    for (int j = i + 1; j < size; ++j)
    {
      if (arr[i] + arr[j] == expected_sum)
      {
        cout << min(arr[i], arr[j]) << " " << max(arr[i], arr[j]) << endl;
      }
    }
  }
}

// print set of 3 numbers from array which result in
// same number as input expected_sum after addition 
void triplet_sum(int arr[], int size, int expected_sum)
{
  for (int i = 0; i < size; ++i)
  {
    for (int j = i + 1; j < size; ++j)
    {
      for (int k = j + 1; k < size; ++k)
      {
        if ((arr[i] + arr[j] + arr[k]) == expected_sum)
        {
          cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
        }
      }
    }
  }
}

// sort all 0s and 1s together in a single traverse
// it can also be done as: sorting the array using 
// inbuilt method or counting the number of 0s and 1s
// and creating a new array with result. But both these
// methods would need more than one traversal
void sort_0_1(int arr[], int size)
{
  int i = 0, j = size - 1;
  while (i < j)
  {
    if (arr[i] == 0)
    {
      i++;
    }
    else if (arr[j] == 1)
    {
      j--;
    }
    else if (arr[i] == 1 && arr[j] == 0)
    {
      swap(arr[i], arr[j]);
      i++;
      --j;
    }

  }
}

int main()
{
  // int arr_even[] = {1, 3, 2, 7, 11, 8};
  // int size_even = 6;
  // print_array(arr_even, size_even);
  // swap_alternate(arr_even, size_even);
  // print_array(arr_even, size_even);

  // int arr_odd[] = {1, 3, 2, 7, 11, 8, 9};
  // int size_odd = 7;
  // print_array(arr_odd, size_odd);
  // swap_alternate(arr_odd, size_odd);
  // print_array(arr_odd, size_odd);

  // int arr[] = {1, 3, 1, 3, 6, 6, 7, 10, 7};
  // int arr_size = 9;
  // print_array(arr, arr_size);
  // find_unique(arr, arr_size);

  // int arr[] = {6, 3, 1, 5, 4, 3, 2};
  // int arr_size = 7;
  // print_array(arr, arr_size);
  // find_duplicates(arr, arr_size);

  // int arr1[] = {1, 2, 2, 2, 3, 4};
  // int arr2[] = {2, 2, 3, 3};
  // int arr1_size = 6;
  // int arr2_size = 4;
  // print_array(arr1, arr1_size);
  // print_array(arr2, arr2_size);
  // print_intersection(arr1, arr2, arr1_size, arr2_size);

  // int arr[] = {1, 2, 3, 4, 5};
  // int arr_size = 5;
  // int expected_sum = 5;
  // print_array(arr, arr_size);
  // pair_sum(arr, arr_size, expected_sum);

  // int arr[] = {1, 2, 3, 4, 5};
  // int arr_size = 5;
  // int expected_sum = 12;
  // print_array(arr, arr_size);
  // triplet_sum(arr, arr_size, expected_sum);

  int arr[] = {0, 1, 0, 1, 1, 0};
  int arr_size = 6;
  print_array(arr, arr_size);
  sort_0_1(arr, arr_size);
  print_array(arr, arr_size);
}