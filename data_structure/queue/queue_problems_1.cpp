#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <map>

using namespace std;

void print_queue(queue<int> q)
{
  queue<int> temp;
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    temp.push(q.front());
    q.pop();
  }
  std::cout << endl;

  // while (!temp.empty())
  // {
  //   q.push(temp.front());
  //   temp.pop();
  // }
}

template <typename T>
void print_vector(vector<T> vec)
{
  for (int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec.at(i) << " ";
  }
  std::cout << endl;
}

//////////////////////////////////////
// reverse a queue
/**
 * @brief reverse the input queue using a stack
 * 
 * @param q input queue to be reversed
 * @return queue<int> 
 */
queue<int> reverse_using_stack(queue<int> q)
{
  stack<int> temp;

  while(!q.empty())
  {
    temp.push(q.front());
    q.pop();
  }

  while (!temp.empty())
  {
    q.push(temp.top());
    temp.pop();
  }

  return q;
}

/**
 * @brief reverse an input queue using recursion
 * 
 * @param q input queue to be reversed
 * @return queue<int> 
 */
queue<int> reverse_using_rec(queue<int> q)
{
  if (q.empty())
  {
    return q;
  }

  int el = q.front();
  q.pop();

  queue<int> res = reverse_using_rec(q);
  res.push(el);

  return res;
}

////////////////////////////////////////
// print first negative number in window of k

/**
 * @brief print first negative number in window of k
 * 
 * @param vec vector with input numbers
 * @param N   size of initial input
 * @param k   size of window in which first negative is to be found
 * @return vector<long long int> 
 */
vector<long long int> printFirstNegative(vector<long long int> vec, int N, int k)
{
  vector<long long int> res;

  deque<long long int> dq;

  // process first window of k size
  for (int i = 0; i < k; ++i)
  {
    if (vec[i] < 0)
    {
      dq.push_back(i);
    }
  }

  // store answer of first k size
  if (dq.size()) // at least one element present
  {
    res.push_back(vec[dq.front()]);
  }
  else
  {
    res.push_back(0);
  }

  // process remaining windows
  for (int i = k; i < N; ++i)
  {
    // removal of extra elements of queue if not present in k window
    if (!dq.empty() && ((i - dq.front()) >= k))
    {
      dq.pop_front();
    }

    // insertion
    if (vec[i] < 0)
    {
      dq.push_back(i);
    }

    // get answer
    if (dq.size()) // at least one element present
    {
      res.push_back(vec[dq.front()]);
    }
    else
    {
      res.push_back(0);
    }
  }

  return res;
}

////////////////////////////////////////
// reverse initial k elements

/**
 * @brief reverse only initial K elements of a queue
 * 
 * @param q input queue
 * @param K inital K elements count to be reversed
 * @return queue<int> 
 */
queue<int> reverseKElements(queue<int> q, int K)
{
  stack<int> st;
  int n = q.size();

  for (int i = 0; i < K; ++i)
  {
    st.push(q.front());
    q.pop();
  }

  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }

  for (int i = 0; i < (n - K); ++i)
  {
    q.push(q.front());
    q.pop();
  }

  return q;
}

///////////////////////////////////////
// first non-repeating char in a stream

string firstNonRepeating(string str)
{
  string res = "";
  map<char, int> count;
  queue<char> q;

  for (int i = 0; i < str.length(); ++i)
  {
    count[str[i]]++;
    q.push(str[i]);

    while (!q.empty())
    {
      // repeating
      if (count[q.front()] > 1)
      {
        q.pop();
      }
      else
      {
        res.push_back(q.front());
        break;
      }
    }
    if (q.empty())
    {
      res.push_back('#');
    }
  }
  return res;
}

int main()
{
  // reverse a queue
  // queue<int> q;

  // q.push(4);
  // q.push(3);
  // q.push(1);
  // q.push(10);
  // q.push(2);
  // q.push(6);

  // print_queue(q);
  // queue<int> rqs = reverse_using_stack(q); 
  // print_queue(rqs);
  // queue<int> rqr = reverse_using_stack(rqs); 
  // print_queue(rqr);

  // print first negative in k elements
  // vector<long long int> vect{-8, 2, 3, -6, 10};
  // print_vector(vect);
  // vector<long long int> res = printFirstNegative(vect, vect.size(), 2);
  // print_vector(res);

  // reverse initial k elements
  // queue<int> q;
  // q.push(1);
  // q.push(2);
  // q.push(3);
  // q.push(4);
  // q.push(5);
  // print_queue(q);
  // queue<int> res = reverseKElements(q, 4);
  // print_queue(res);

  // first non-repeating char in a stream
  string str = "aabbc";
  std::cout << str << endl;
  string res = firstNonRepeating(str);
  std::cout << res << endl;


  return 0;
}