#include <iostream>
#include <string>

using namespace std;

int factorial(int n)
{
  if (n == 1)
  {
    return 1;
  }
  return n * factorial(n - 1);
}

int power(int num, int pow)
{
  if (pow == 1)
  {
    return num;
  }
  return num * power(num, pow - 1);
}

void counting_print(int num)
{
  if (num == 0)
    return;
  counting_print(num - 1); // for 1 2 3 4.....
  cout << num << " ";
  // counting_print(num - 1); // for ....4, 3, 2, 1
}

int nth_fibonacci(int num)
{
  if (num == 0)
  {
    return 0;
  }
  if (num == 1)
  {
    return 1;
  }
  return nth_fibonacci(num - 1) + nth_fibonacci(num - 2);
}

int count_distinct_ways_to_count_stairs(int num_of_stairs)
{
  if (num_of_stairs < 0)
  {
    return 0;
  }
  if (num_of_stairs == 0)
  {
    return 1;
  }
  return count_distinct_ways_to_count_stairs(num_of_stairs - 1) + count_distinct_ways_to_count_stairs(num_of_stairs - 2);
}

/////////////////////////////////////////////////////////////
// input: 412, output: Four One Two
// needs a function for digit name
string get_digit_name(int n)
{
  string nameArr[10] = {
    "Zero",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine"
  };
  return nameArr[n];
}


void say_digits(int num)
{
  cout << "Test : " << num << endl;
  if (num == 0)
  {
    return;
  }
  int rem = num % 10;
  say_digits(num / 10);
  cout << get_digit_name(rem) << " ";
}

/////////////////////////////////////////////
bool is_sorted(int arr[], int size)
{
  if (size == 0 || size == 1)
  {
    return true;
  }
  if (arr[0] > arr[1])
  {
    return false;
  }
  else
  {
    return is_sorted(arr + 1, size - 1);
  }
}

//////////////////////////////////////////////////
// Sum of array
int sum_rec(int arr[], int size)
{
  if (size == 1)
  {
    return arr[0];
  }
  return arr[0] + sum_rec(arr + 1, size - 1);
}

/////////////////////////////////////////////////
// Linear search
bool linear_search(int arr[], int size, int key)
{
  if (size == 1)
  {
    if (arr[0] == key)
    {
      return true;
    }
    return false;
  }
  return linear_search(arr + 1, size - 1, key);
}

////////////////////////////////////////////////////
// Binary search

void print (int arr[], int start, int end, int key)
{
  for (int i = start; i < end; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl << "Start : " << start << " End: " << end << " Key: " << key << endl;
}

bool binary_search(int arr[], int start, int end, int key)
{
  int mid = start + ((end - start) / 2);
  print(arr, start, end, key);
  if (start >= end)
  {
    return false;
  }
  if (arr[mid] == key)
  {
    return true;
  }
  else if (arr[mid] < key)
  {
    cout << "Key is bigger.. and curr el " << arr[mid] <<endl;
    return binary_search(arr, mid + 1, end, key);
  }
  else if (arr[mid] > key)
  {
    cout << "Key is smaller.. and curr el " << arr[mid] <<endl;
    return binary_search(arr, start, mid - 1, key);
  }
}


int main()
{
  int num;
  // cout << "Enter the number for factorial : ";
  // cin >> num;
  // cout << "Factorial : " << factorial(num) << endl;

  // cout << "Enter the number to find power : ";
  // cin >> num;
  // int pow;
  // cout << "Enter the power : ";
  // cin >> pow;
  // cout << "Res : " << power(num, pow);

  // cout << "Enter number for counting : ";
  // cin >> num;
  // counting_print(num);

  // cout << "Enter n for fibonacci : ";
  // cin >> num;
  // cout << "Res : " << nth_fibonacci(num);

  // cout << "Enter number of stairs : ";
  // cin >> num;
  // cout << "Number of ways : " << count_distinct_ways_to_count_stairs(num);

  // cout << "Enter the number : ";
  // cin >> num;
  // say_digits(num);

  // int arr[] = {1, 3, 4, 5, 7, 9, 12, 15};
  // cout << (is_sorted(arr, sizeof(arr)/sizeof(arr[0])) ? "Sorted" : "Not Sorted");

  // int arr[] = {1, 2, 3, 4, 5};
  // cout << "Sum : " << sum_rec(arr, sizeof(arr)/sizeof(arr[0]));

  // int arr[] = {3, 2, 5, 1, 6};
  // int key = 16;
  // cout << "Is present?? " << (linear_search(arr, sizeof(arr)/sizeof(arr[0]), key) ? "Yes" : "No");

  int arr[] = {2, 4, 6, 8, 10, 14, 18};
  int key = 70;
  cout << (binary_search(arr, 0, sizeof(arr)/sizeof(arr[0]), key) ? "Present" : "Not present");
}