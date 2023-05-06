#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* prev;
  Node* next;

  // constructor
  Node(int d)
  {
    this->data = d;
    this->prev = NULL;
    this->next = NULL;
  }

  // destructor
  ~Node()
  {
    int val = this->data;
    if (this->next != NULL)
    {
      delete this->next;
      this->next = NULL;
    }
    cout << "Memory free with data " << val << endl;
  }
};

void print_dll(Node* &head)
{
  Node* temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// Length of the DLL
int get_length_dll(Node* &head)
{
  int len = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    len++;
    temp = temp->next;
  }
  return len;
}

// insert element at start of DLL
void insert_at_head(Node* &head, int d)
{
  Node* temp = new Node(d);
  temp->next = head;
  head->prev = temp;
  head = temp;
}

// Insert element at the end of Doubly Linked list
void insert_at_end(Node* &tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  temp->prev = tail;
  tail = temp;
}

// Insert at position in DLL
void insert_at_pos(Node* &head, Node* &tail, int pos, int d)
{
  if (pos == 1)
  {
    insert_at_head(head, d);
    return;
  }

  Node *traverse_node = head;
  int i = 1;
  while(i < (pos - 1))
  {
    traverse_node = traverse_node->next;
    i++;
  }

  if (traverse_node->next == NULL)
  {
    insert_at_end(tail, d);
    return;
  }

  Node *node = new Node(d);
  node->prev = traverse_node;
  node->next = traverse_node->next;
  traverse_node->next->prev = node;
  traverse_node->next = node;
}

// delete a node from dll
void delete_node(Node* &head, Node* &tail, int pos)
{
  if (pos == 1)
  {
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
  }
  else
  {
    Node *curr = head;
    int i = 1;
    while (i < pos)
    {
      curr = curr->next;
      i++;
    }

    if (curr->next == NULL)
    {
      tail = curr->prev;
      tail->next = NULL;
      curr->prev = NULL;
      delete curr;
      return;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->next = NULL;
    curr->prev = NULL;

    delete curr;
  }
}

int main()
{
  Node *head = new Node(10);
  Node *tail = head;
  print_dll(head);

  cout << get_length_dll(head) << endl;

  insert_at_head(head, 5);
  print_dll(head);

  insert_at_head(head, 1);
  print_dll(head);
  
  insert_at_end(tail, 20);
  print_dll(head);

  insert_at_pos(head, tail, 3, 10);
  print_dll(head);
  
  insert_at_pos(head, tail, 5, 100);
  print_dll(head);

  delete_node(head, tail, 5);
  print_dll(head);
  cout << "Head " << head->data << "\tTail " << tail->data << endl;

  return 0;
}