#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;

  Node(int d)
  {
    this->data = d;
    this->next = NULL;
  }

  ~Node()
  {
    int val = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "Deleted : " << val << endl;
  }
};

class Stack_LL
{
  Node *head = NULL;

public:
  Stack_LL()
  {
    head = NULL;
  }

  void push(int data)
  {
    Node* temp = new Node(data);
    if (head == NULL)
    {
      head = temp;
    }
    else
    {
      temp->next = head;
      head = temp;
    }
  }

  void pop()
  {
    if (head == NULL)
    {
      cout << "stack underflow" << endl;
    }
    else
    {
      Node* temp = head;
      head = head->next;
      
      temp->next = NULL;
      delete temp;
    }
  }

  int peek()
  {
    if (head == NULL)
    {
      cout << "stack is empty" << endl;
      return -1;
    }
    else
    {
      return head->data;
    }
  }

  bool is_empty()
  {
    return head == NULL;
  }
};

int main()
{
  Stack_LL st;
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
}