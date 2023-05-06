#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* next;

  // constructor
  Node(int data)
  {
    this -> data = data;
    this -> next = NULL;
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
    cout << "Deleted : " << val << endl;
  }
};

// Intsert at head
void insert_at_head(Node* &head, int d)
{
  // Create  new node
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}

// Insert at tail
void insert_at_tail(Node* &tail, int d)
{
  Node* temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

// Insert at a position
void insert_at_position(Node* &head, Node* &tail, int pos, int d)
{
  if (pos == 1)
  {
    insert_at_head(head, d);
    return;
  }
  Node* temp = new Node(d);
  Node* traverse_node = head;
  int i = 1;
  while (i++ < (pos - 1))
  {
    traverse_node = traverse_node->next;
  }
  temp->next = traverse_node->next;
  traverse_node->next = temp;
}

// void delete a node
void delete_node(Node* &head, int pos)
{
  if (pos == 1)
  {
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
  }
  else
  {
    Node *curr = head;
    Node *prev = NULL;
    int i = 1;
    while (i < (pos))
    {
      prev = curr;
      curr = curr->next;
      i++;
    }
    
    prev->next = curr->next;
    
    curr->next = NULL;
    delete curr;
  }
}

void print_linked_list(Node* &head)
{
  Node* temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}


// int main()
// {
//   Node* head = new Node(10);
//   Node* tail = head; // as there exist only one node
//   print_linked_list(head);
//   insert_at_head(head, 20);
//   print_linked_list(head);
//   insert_at_head(head, 30);
//   print_linked_list(head);
//   insert_at_tail(tail, 20);
//   print_linked_list(head);
//   insert_at_tail(tail, 30);
//   print_linked_list(head);

//   insert_at_position(head, tail, 4, 5);
//   print_linked_list(head);

//   insert_at_position(head, tail, 7, 10);
//   print_linked_list(head);

//   delete_node(head, 5);
//   print_linked_list(head);

//   return 0;
// }