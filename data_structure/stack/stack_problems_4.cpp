#include <iostream>
#include <limits.h>
#include <stack>

using namespace std;

//////////////////////////////////////
// implement N stacks in an arr

class NStack
{
private:
  int *arr;
  int *top;
  int *next;

  int freespot;
  int n, s;

public:
  NStack(int N, int s)
  {
    this->n = N;
    this->s = s;
    this->arr = new int[s];
    this->top = new int[n];
    this->next = new int[s];

    // initialize top
    for (int i = 0; i < n; ++i)
    {
      this->top[i] = -1;
    }

    // initialize next
    for (int i = 0; i < s - 1; ++i)
    {
      this->next[i] = i + 1;
    }
    this->next[s - 1] = -1;

    this->freespot = 0;
  }

  bool push(int val, int stackNum)
  {
    // check for overflow
    if (freespot == -1)
    {
      return false;
    }

    int index = freespot;
    freespot = next[index];
    arr[index] = val;
    next[index] = top[stackNum - 1];
    top[stackNum - 1] = index;

    return true;
  }

  int pop(int stackNum)
  {
    if (top[stackNum - 1] == -1)
    {
      return -1;
    }

    int index = top[stackNum - 1];
    top[stackNum - 1] = next[index];
    int val = arr[index];
    next[index] = freespot;
    freespot = index;

    return val;
  }
};


/////////////////////////////////////////////
// special stack with get_min as O(1)

class SpecialStack
{
private:
  stack<int> st;
  int mini = INT_MAX;

public:

  int push(int val)
  {
    if (st.empty())
    {
      st.push(val);
      mini = val;
    }
    else
    {
      if (val < mini)
      {
        int newVal = 2 * val - mini;
        st.push(newVal);
        mini = val;
      }
      else
      {
        st.push(val);
      }
    }
  }

  int pop()
  {
    if (st.empty())
    {
      return -1;
    }

    int curr = st.top();
    st.pop();
    if (curr > mini)
    {
      return curr;
    }
    else
    {
      int prevMin = mini;
      mini = 2 * mini - curr;
      return prevMin;
    }
  }

  int top()
  {
    if (st.empty())
    {
      return -1;
    }
    int curr = st.top();
    if (curr < mini)
    {
      int prevMin = mini;
      mini = 2 * mini - curr;
      return prevMin;
    }
    return st.top();
  }

  bool isEmpty()
  {
    return st.empty();
  }

  int getMin()
  {
    if (st.empty())
    {
      return -1;
    }
    return mini;
  }
};

int main()
{
  // implement N stacks in an array
  // NStack st(3, 6);
  // std::cout << "Pushing 10 in stack 1" << endl;
  // st.push(10, 1);
  // std::cout << "Pushing 20 in stack 1" << endl;
  // st.push(20, 1);
  // std::cout << "Pushing 30 in stack 2" << endl;
  // st.push(30, 2);
  // std::cout << "popping stack 1: " << st.pop(1) << endl;
  // std::cout << "popping stack 2: " << st.pop(2) << endl;

  // implement special stack with min operation as O(1)
  SpecialStack st;
  st.push(5);
  std::cout << "Minimum : " <<  st.getMin() << endl;
  st.push(3);
  std::cout << "Minimum : " <<  st.getMin() << endl;
  st.push(8);
  std::cout << "Minimum : " <<  st.getMin() << endl;
  st.push(2);
  std::cout << "Minimum : " <<  st.getMin() << endl;
  st.push(4);
  std::cout << "Minimum : " <<  st.getMin() << endl;

  return 0;
}