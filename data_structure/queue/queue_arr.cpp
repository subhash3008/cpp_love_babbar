#include <iostream>

using namespace std;

class Queue
{
private:
  int *arr;
  int size;
  int front;
  int rear;

public:
  Queue()
  {
    size = 1000;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  void push(int val)
  {
    if (rear == size)
    {
      std::cout << "Queue is full." << endl;
    }
    else
    {
      arr[rear++] = val;
    }
  }

  int pop()
  {
    if (front == rear)
    {
      std::cout << "Queue is empty." << endl;
    }
    else
    {
      int val = arr[front];
      arr[front++] = -1;
      std::cout << "Deleting from Queue:: " << val << endl;
      if (front == rear)
      {
        std::cout << "Queue is now empty.." << endl;
        front = 0;
        rear = 0;
      }
      return val;
    }
  }

  int top()
  {
    if (front == rear)
    {
      std::cout << "Queue is empty" << endl;
      return -1;
    }
    else
    {
      return arr[front];
    }
  }

  bool isEmpty()
  {
    return front == rear;
  }

  void print()
  {
    if (front == rear)
    {
      std::cout << "Queue is empty." << endl;
    }
    else
    {
      for (int i = front; i < rear; ++i)
      {
        std::cout << arr[i] << " ";
      }
      std::cout << endl;
    }
  }
};

////////////////////////////////////////
// Circular queue
class CircularQueue
{
private:
  int *arr;
  int front;
  int rear;
  int size;
public:
  CircularQueue()
  {
    size = 5;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  bool push(int val)
  {
    if (((front == 0) && (rear == (size -1))) ||
      (rear == (front - 1) % (size - 1))) // check if queue is full
    {
      std::cout << "Queue is full" << endl;
      return false;
    }
    else if (front == -1) // first element
    {
      front = 0;
      rear = 0;
    }
    else if ((rear == (size - 1)) && front != 0)
    {
      rear = 0;
    }
    else
    {
      rear++;
    }
    arr[rear] = val;
    return true;
  }

  int pop()
  {
    if (front == -1)
    {
      std::cout << "Queue is empty" << endl;
    }

    int val = arr[front];
    std::cout << "Deleted:: " << val << endl;
    arr[front] = -1;

    if (front == rear) // single element
    {
      front = -1;
      rear = -1;
    }
    else if (front == (size - 1)) // front is at end
    {
      front = 0; // to maintain cyclic nature
    }
    else
    {
      front++;
    }
    return val;
  }

  int top()
  {
    if (front == -1)
    {
      std::cout << "Queue is empty." << endl;
      return -1;
    }
    else
    {
      return arr[front];
    }
  }

  int back()
  {
    if (rear == -1)
    {
      std::cout << "Queue is empty." << endl;
      return -1;
    }
    else
    {
      return arr[rear];
    }
  }
};

int main()
{
  // Queue q;

  // q.push(10);
  // q.print();
  // q.push(29);
  // q.print();
  // q.push(39);
  // q.print();
  // q.pop();
  // q.print();
  // q.pop();
  // q.pop();

  // std::cout << q.top() << endl;

  // if (q.isEmpty())
  // {
  //   std::cout << "Queue is empty." << endl;
  // }
  // else
  // {
  //   std::cout << "Queue is not empty" << endl;
  // }

  ///////////////////////////////////////
  // circular queue
  CircularQueue cq;
  cq.push(10);
  std::cout << "Queue front :: " << cq.top() << endl;
  std::cout << "Queue back :: " << cq.back() << endl;
  cq.push(20);
  std::cout << "Queue front :: " << cq.top() << endl;
  std::cout << "Queue back :: " << cq.back() << endl;
  cq.push(30);
  std::cout << "Queue front :: " << cq.top() << endl;
  std::cout << "Queue back :: " << cq.back() << endl;
  cq.push(40);
  std::cout << "Queue front :: " << cq.top() << endl;
  std::cout << "Queue back :: " << cq.back() << endl;
  cq.push(50);
  std::cout << "Queue front :: " << cq.top() << endl;
  std::cout << "Queue back :: " << cq.back() << endl;
  cq.push(60);


  cq.pop();
  std::cout << "Queue front :: " << cq.top() << endl;
  std::cout << "Queue back :: " << cq.back() << endl;
  
  cq.push(60);
  std::cout << "Queue front :: " << cq.top() << endl;
  std::cout << "Queue back :: " << cq.back() << endl;

  return 0;
}