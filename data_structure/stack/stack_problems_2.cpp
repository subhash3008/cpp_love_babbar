#include <iostream>
#include <string>
#include <stack>

using namespace std;

template <typename T> 
void print_stack(stack<T> st)
{
  stack<T> tst;
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

//////////////////////////////////////////
// Valid Parenthesis
bool parenthesis_match(char open, char close)
{
  if (open == '[')
  {
    return close == ']';
  }
  if (open == '{')
  {
    return close == '}';
  }
  if (open == '(')
  {
    return close == ')';
  }
  return false;
}

bool is_valid_parenthesis(const string str)
{
  stack<char> s;
  for (int i = 0; i < str.length(); ++i)
  {
    char ch = str[i];

    // if opening
    if (ch == '[' || ch == '{' || ch == '(')
    {
      s.push(ch);
    }
    else if (ch == ']' || ch == '}' || ch == ')')
    {
      // for closing bracket
      if (!s.empty())
      {
        if (!parenthesis_match(s.top(), ch))
        {
          return false;
        }
        else
        {
          s.pop();
        }
      }
      else
      {
        return false;
      }
    }
  }
  if (s.empty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

/////////////////////////////////////////
// insert an element at bottom
void insert_at_bottom(stack<int>& st, int num)
{
  if (st.empty())
  {
    st.push(num);
    return;
  }
  int top = st.top();
  st.pop();
  insert_at_bottom(st, num);
  st.push(top);
}

/////////////////////////////////////////////
// reverse a stack
stack<int> reverse_stack(stack<int> st)
{
  stack<int> temp;
  while (!st.empty())
  {
    temp.push(st.top());
    st.pop();
  }
  return temp;
}

void reverse_stack_recur(stack<int> &st)
{
  if (st.empty())
  {
    return;
  }

  int top = st.top();
  st.pop();
  reverse_stack_recur(st);
  insert_at_bottom(st, top);
}

///////////////////////////////////
// sort a stack
void sorted_insert(stack<int>& st, int num)
{
  if (st.empty() || (!st.empty() && (st.top() < num)))
  {
    st.push(num);
    return;
  }
  int n = st.top();
  st.pop();

  sorted_insert(st, num);

  st.push(n);
}

void sort_stack(stack<int>& st)
{
  if (st.empty())
  {
    return;
  }

  int num = st.top();
  st.pop();

  sort_stack(st);

  sorted_insert(st, num);
}

///////////////////////////////////////////
// Check for redundand brackets
bool check_redundand_brackets(const string str)
{
  stack<char> st;

  for (int i = 0; i < str.length(); ++i)
  {
    char ch = str[i];
    if (ch == '(' || (
      ch == '+' ||
      ch == '-' ||
      ch == '*' ||
      ch == '/'
    ))
    {
      st.push(ch);
    }
    else
    {
      if (ch == ')')
      {
        bool isRedundand = true;
        while (st.top() != '(')
        {
          char top = st.top();
          if (top == '+' || top == '-' || top == '*' || top == '/')
          {
            isRedundand = false;
          }
          st.pop();
        }
        if (isRedundand == true)
        {
          return true;
        }
        st.pop();
      }
    }
  }
  return false;
}

////////////////////////////////////////
// get minimum cost to make a string valid
// string -> made up of { and }
// valid -> every opening { has a closing }
int get_min_cost_valid_str(const string str)
{
  if (str.length() % 2 == 1)
  {
    return -1;
  }


  stack<char> st;
  for (int i = 0; i < str.length(); ++i)
  {
    char ch = str[i];
    if (ch == '{')
    {
      st.push(ch);
    }
    else
    {
      if (!st.empty() && (st.top() == '{')) // here ch = }, so remove valid pair
      {
        st.pop();
      }
      else
      {
        st.push(ch);
      }
    }
  }
  print_stack(st);
  int a = 0; // close brace
  int b = 0; // open bracce
  while (!st.empty())
  {
    if (st.top() == '{')
    {
      b++;
    }
    else if (st.top() == '}')
    {
      a++;
    }
    st.pop();
  } 
  cout << "a: " << a << ", b: " << b << endl;
  cout << ((a + 1) / 2) << endl;
  cout << ((b + 1) / 2) << endl;

  return (((a + 1) / 2) + ((b + 1) / 2));

}

int main()
{
  // Valid parenthesis
  // string str = "[{[()}]";
  // cout << "Is Valid : " << (is_valid_parenthesis(str) ? "Yes" : "No");

  // insert at bottom
  // stack<int> s;
  // s.push(1);
  // s.push(2);
  // s.push(3);
  // s.push(4);
  // s.push(5);
  // print_stack(s);
  // insert_at_bottom(s, 0);
  // print_stack(s);

  // reverse a stack
  // stack<int> s;
  // s.push(1);
  // s.push(2);
  // s.push(3);
  // s.push(4);
  // s.push(5);
  // print_stack(s);
  // // stack<int> rs = reverse_stack(s);
  // reverse_stack_recur(s);
  // print_stack(s);

  // sort a stack
  // stack<int> s;
  // s.push(10);
  // s.push(-2);
  // s.push(3);
  // s.push(-4);
  // s.push(5);
  // print_stack(s);
  // sort_stack(s);
  // print_stack(s);

  // check for redundand brackets
  // string str = "(a + ((b * c) / d))";
  // bool res = check_redundand_brackets(str);
  // cout << "Is redundand brackets present?? " << (res ? "Yes" : "No");

  // get min cost for making a string valid
  string str = "{{{}}}}}}}{{";
  int res = get_min_cost_valid_str(str);
  cout << "res : " << res << endl;

  return 0;
}