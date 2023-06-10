#include <iostream>

using namespace std;

/////////////////////////////////
// Double ended queue implementation

class Deque
{
private:
  int *m_arr;
  int m_rear;
  int m_front;
  int m_size;

public:
  Deque(int n)
  {
    m_size = n;
    m_arr = new int[m_size];
    m_rear = -1;
    m_front = -1;
  }

  bool pushFront(int val)
  {
    // check if the queue is full
    if (((m_front == 0) && (m_rear == (m_size - 1))) ||
      (m_rear == (m_front - 1) % (m_size - 1)))
    {
      std::cout << "Deque is full" << endl;
      return false;
    }
    else if (m_front == -1) // first element insert
    {
      m_front = m_rear = 0;
    }
    else if ((m_front == 0) && (m_rear != (m_size - 1))) // maintain cyclic nature at boundary
    {
      m_front = m_size - 1;
    }
    else // normal case
    {
      m_front--;
    }
    m_arr[m_front] = val;
    return true;
  }

  bool pushRear(int val)
  {
    // check if the queue is full
    if (((m_front == 0) && (m_rear == (m_size - 1))) ||
      (m_rear == (m_front - 1) % (m_size - 1)))
    {
      std::cout << "Deque is full" << endl;
      return false;
    }
    else if (m_rear == -1) // check for first element
    {
      m_front = m_rear = 0;
    }
    else if ((m_rear == (m_size - 1)) && (m_front != 0)) // check for cyclic maintainance
    {
      m_rear = 0;
    }
    else // normal case
    {
      m_rear++;
    }
    m_arr[m_rear] = val;
    return true;
  }

  int popFront()
  {
    // check for deque empty
    if (m_front == -1)
    {
      std::cout << "Deque is empty" << endl;
      return INT8_MIN;
    }

    int res = m_arr[m_front];
    m_arr[m_front] = -1;
    std::cout << "Deleted:: " << res << endl;

    if (m_front == m_rear) // single element present
    {
      m_front = -1;
      m_rear = -1;
    }
    else if (m_front = (m_size - 1)) // check for cyclic maintainance
    {
      m_front = 0;
    }
    else
    {
      m_front++;
    }
    return res;
  }

  int popRear()
  {
    // check if deque is empty
    if (m_rear == -1)
    {
      std::cout << "Deque is empty" << endl;
      return INT8_MIN;
    }

    int res = m_arr[m_rear];
    m_arr[m_rear] = -1;
    std::cout << "Deleted:: " << res << endl;

    if (m_rear == m_front) // single element
    {
      m_rear = m_front = -1;
    }
    else if (m_rear == 0) // check for cycle maintainance
    {
      m_rear = m_size - 1;
    }
    else
    {
      m_size++;
    }
    return res;
  }

  int front()
  {
    if (m_front == -1)
    {
      std::cout << "Deque is empty" << endl;
      return INT8_MIN;
    }
    return m_arr[m_front];
  }

  int back()
  {
    if (m_rear == -1)
    {
      std::cout << "Deque is empty" << endl;
      return INT8_MIN;
    }
    return m_arr[m_rear];
  }

};

int main()
{
  Deque dq(5);

  dq.pushFront(1);
  dq.pushRear(2);

  std::cout << dq.front() << endl;
  std::cout << dq.back() << endl;
  
  dq.pushRear(3);
  std::cout << dq.front() << endl;
  std::cout << dq.back() << endl;

  dq.pushRear(0);
  std::cout << dq.front() << endl;
  std::cout << dq.back() << endl;
  dq.pushRear(-1);
  std::cout << dq.front() << endl;
  std::cout << dq.back() << endl;

  dq.pushRear(-2);
  std::cout << dq.front() << endl;
  std::cout << dq.back() << endl;

  return 0;
}