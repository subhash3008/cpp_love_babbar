#include <iostream>
#include <queue>

using namespace std;

int main()
{
  queue<int> q;

  q.push(11);
  std::cout << "front of queue is " << q.front() << endl;
  std::cout << "rear of queue is " << q.back() << endl;
  q.push(15);
  std::cout << "front of queue is " << q.front() << endl;
  std::cout << "rear of queue is " << q.back() << endl;
  q.push(13);
  std::cout << "front of queue is " << q.front() << endl;
  std::cout << "rear of queue is " << q.back() << endl;

  std::cout << "size of queue is " << q.size() << endl;

  q.pop();
  q.pop();
  q.pop();

  std::cout << "size of queue after pop is " << q.size() << endl;

  if (q.empty())
  {
    std::cout << "queue is empty." << endl;
  }
  else
  {
    std::cout << "queue is not empty" << endl;
  }

  return 0;
}