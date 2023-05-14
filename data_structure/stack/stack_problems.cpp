#include <iostream>
#include <string>
#include <stack>

using namespace std;

////////////////////////////////
// Implement two stacks in one array

class TwoStack
{
  int *arr;
  int top1;
  int top2;
  int size;

public:
  TwoStack(int size)
  {
    this->size = size;
    top1 = -1;
    top2 = size;
    arr = new int[size];
  }

  void push1(int data)
  {
    // at least one empty place is present
    if ((top2 - top1) > 1)
    {
      top1++;
      arr[top1] = data;
    }
    else
    {
      cout << "stack1 overflow.." << endl;
    }

  }

  void push2(int data)
  {
    if ((top2 - top1) > 1)
    {
      top2--;
      arr[top2] = data;
    }
    else
    {
      cout << "stack2 overflow.." << endl;
    }
  }

  int pop1()
  {
    if (top1 >= 0)
    {
      return arr[top1--];
    }
    else
    {
      cout << "stack1 underflow" << endl;
      return -1;
    }
  }

  int pop2()
  {
    if (top2 < size)
    {
      return arr[top2++];
    }
    else
    {
      cout << "stack2 underflow" << endl;
      return -1;
    }
  }

  int peek1()
  {
    if (top1 >= 0)
    {
      return arr[top1];
    }
    else
    {
      cout << "stack1 is empty" << endl;
      return -1;
    }
  }

  int peek2()
  {
    if (top2 < size)
    {
      return arr[top2];
    }
    else
    {
      cout << "stack2 is empty" << endl;
      return -1;
    }
  }
};

/////////////////////////////////////////////
// Reverse a string using stack
string reverse_str(const string str)
{
  stack<char> s;
  for (int i = 0; i < str.length(); ++i)
  {
    s.push(str[i]);
  }

  string res = "";
  while (!s.empty())
  {
    res.push_back(s.top());
    s.pop();
  }

  return res;
}

/////////////////////////////////////
// delete middle element from
// an integer stack

void print_stack(stack<int> st)
{
  stack<int> tst;
  while (!st.empty())
  {
    tst.push(st.top());
    st.pop();
  }

  while (!tst.empty())
  {
    cout << tst.top() << " ";
    tst.pop();
  }
  cout << endl;
}

void remove_middle(stack<int>& istack, int count, int n)
{
  if (count == (n / 2))
  {
    istack.pop();
    return;
  }

  int temp = istack.top();
  istack.pop();
  remove_middle(istack, count + 1, n);
  istack.push(temp);
}

int main()
{
  // Implement two stacks using one array
  // TwoStack ts(10);
  // ts.push1(1);
  // cout << "stack1: " << ts.peek1() << endl;
  // ts.push1(2);
  // cout << "stack1: " <<  ts.peek1() << endl;
  // ts.push1(3);
  // cout << "stack1: " <<  ts.peek1() << endl;
  // ts.push1(4);
  // cout << "stack1: " <<  ts.peek1() << endl;
  // ts.push1(5);
  // cout << "stack1: " <<  ts.peek1() << endl;
  // ts.push1(6);
  // cout << "stack1: " <<  ts.peek1() << endl;

  // ts.push2(1);
  // cout << "stack2: " << ts.peek2() << endl;
  // ts.push2(2);
  // cout << "stack2: " << ts.peek2() << endl;
  // ts.push2(3);
  // cout << "stack2: " << ts.peek2() << endl;
  // ts.push2(4);
  // cout << "stack2: " << ts.peek2() << endl;
  // ts.push2(5);
  // cout << "stack2: " << ts.peek2() << endl; 
  
  // ts.pop2();
  // ts.push2(5);
  // cout << "stack2: " << ts.peek2() << endl; 
  
  // ts.push1(7);
  // cout << "stack1: " << ts.peek1() << endl;
  // ts.pop1();
  // ts.push1(7);
  // cout << "stack1: " << ts.peek1() << endl;

  // Reverse a string using stack
  // string str = "subhash";
  // cout << "original : " << str << "\nreversed: " << reverse_str(str) << endl;

  // Delete middle element from an integer stack
  stack<int> istack;
  istack.push(1);
  istack.push(2);
  istack.push(3);
  istack.push(4);
  istack.push(5);
  istack.push(6);
  print_stack(istack);

  int count = 0;
  remove_middle(istack, count, istack.size());
  print_stack(istack);

  return 0;
}