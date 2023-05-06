#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* next;

  // constructor
  Node(int d)
  {
    this->data = d;
    this->next = NULL;
  }

  // destructor
  ~Node()
  {
    int val = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "Deleted Data : " << val << endl;
  }
};

void insert_node(Node* &tail, int el, int d)
{
  Node* node_to_ins = new Node(d);

  if (tail == NULL)
  {
    node_to_ins->next = node_to_ins;
    tail = node_to_ins;
  }
  else
  {
    Node *curr = tail;
    while(curr->data != el)
    {
      curr = curr->next;
    }

    node_to_ins->next = curr->next;
    curr->next = node_to_ins;
  }
}

void print_cll(Node* &tail)
{
  Node* temp = tail;
  do
  {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != tail);
  cout << endl;
}

// delete a node from linked list
void delete_node(Node* &tail, int el)
{
  if (tail == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  else
  {
    // assumption: el is always present
    Node *prev = tail;
    Node *curr = prev->next; // tail->next

    while (curr->data != el)
    {
      prev = curr;
      curr = curr->next;
    }

    prev->next = curr->next;
    if (tail == curr)
    {
      tail = prev->next;
    }

    curr->next = NULL;
    delete curr;
  }
}

int main()
{
  Node *tail = NULL;

  insert_node(tail, 5, 3);
  print_cll(tail);

  insert_node(tail, 3, 2);
  print_cll(tail);

  insert_node(tail, 2, 1);
  print_cll(tail);

  insert_node(tail, 1, 10);
  print_cll(tail);

  delete_node(tail, 3);
  print_cll(tail);

  delete_node(tail, 2);
  print_cll(tail);

  delete_node(tail, 1);
  print_cll(tail);

  delete_node(tail, 10);

  return 0;
}