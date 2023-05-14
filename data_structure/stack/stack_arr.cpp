#include <iostream>
// #include <stack>

using namespace std;

class Stack_Arr
{
  // data members
  int *arr;
  int top;
  int size;

  // methods
public:
  Stack_Arr(int size)
  {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int el)
  {
    if ((size - 1) > top)
    {
      top++;
      arr[top] = el;
    }
    else
    {
      cout << "stack overflow" << endl;
    }
  }

  void pop()
  {
    if (top >= 0)
    {
      top--;
    }
    else
    {
      cout << "stack underflow" << endl;
    }
  }

  int peek()
  {
    if (top >= 0)
    {
      return arr[top];
    }
    else
    {
      cout << "stack is empty." << endl;
      return -1;
    }
  }

  bool is_empty()
  {
    return top == -1;
  }
};

int main()
{
  // stack<int> s;
  // s.push(2);
  // cout << s.top() << endl;
  // s.push(3);
  // cout << s.top() << endl;
  // s.pop();
  // cout << s.top() << endl;

  // if (s.empty())
  // {
  //   cout << "stack is empty" << endl;
  // }
  // else
  // {
  //   cout << "stack is not empty" << endl;
  // }

  Stack_Arr st(5);
  st.push(22);
  cout << st.peek() << endl;
  st.push(33);
  cout << st.peek() << endl;
  st.push(44);
  cout << st.peek() << endl;
  st.push(55);
  cout << st.peek() << endl;
  st.push(66);
  cout << st.peek() << endl;
  st.push(77);
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();

  if (st.is_empty())
  {
    cout << "..stack is empty" << endl;
  }
  else
  {
    cout << "stack is not empty" << endl;
  }

  return 0;
}