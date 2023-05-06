#include "linked_list.cpp"

//////////////////////////////////////
// REVERSE A LINKED LIST

Node* reverse_linked_list(Node* head)
{
  Node *curr = head;
  Node *prev = NULL;

  while (curr != NULL)
  {
    Node *forward = curr->next;
    curr->next = prev;

    prev = curr;
    curr = forward;
  }
  return prev;
}

// using recursion
Node* reverse_linked_List_recur(Node* head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }

  Node* remaining_reverse = reverse_linked_List_recur(head->next);

  head->next->next = head;
  head->next = NULL;

  return remaining_reverse;
}

/////////////////////////////////////////
// Middle of a linked list

int get_length_ll(Node *head)
{
  Node* temp = head;
  int len = 0;
  while (temp != NULL)
  {
    len++;
    temp = temp->next;
  }
  return len;
}

Node* middle_ll_len(Node *head)
{
  int len = get_length_ll(head);
  int mid = (len / 2) + 1;

  int i = 1;
  Node *temp = head;

  while (i < mid)
  {
    i++;
    temp = temp->next;
  }
  return temp;
}

// using 2 pointers
Node* middle_linked_list (Node* head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

/////////////////////////////////////////
// Reverse Linked List in K-Groups

Node* k_reverse_ll(Node* head, int k)
{
  if (head == NULL)
  {
    return NULL;
  }

  // reverse k elements
  Node *forward = NULL;
  Node *prev = NULL;
  Node *curr = head;
  int count = 0;

  // reverse k elements
  while (curr != NULL && count < k)
  {
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    count++;
  }

  // use recursion to solve remaining cases
  if (forward != NULL)
  {
    head -> next = k_reverse_ll(forward, k);
  }

  return prev;
}

int main()
{
  Node* head = new Node(10);
  Node* tail = head; // as there exist only one node
  print_linked_list(head);
  insert_at_head(head, 20);
  print_linked_list(head);
  insert_at_head(head, 30);
  print_linked_list(head);
  insert_at_tail(tail, 20);
  print_linked_list(head);
  insert_at_tail(tail, 30);
  print_linked_list(head);

  insert_at_position(head, tail, 4, 5);
  print_linked_list(head);

  insert_at_position(head, tail, 7, 10);
  print_linked_list(head);

  // REVERSE A LINKED LIST
  // head = reverse_linked_list(head);
  // cout << "Reversed : ";
  // print_linked_list(head); 
  // head = reverse_linked_List_recur(head);
  // cout << "Reversed : ";
  // print_linked_list(head);

  // Middle of a linked list 
  // Node *middle = middle_linked_list(head);
  // cout << "data at middle : " << middle->data << endl;
  // insert_at_position(head, tail, 8, 100);
  // print_linked_list(head);
  // middle = middle_ll_len(head);
  // cout << "data at middle after addition: " << middle->data << endl;

  // REVERSE a linked list in K-Groups
  head = k_reverse_ll(head, 2);
  cout << "Reversed : ";
  print_linked_list(head);

  return 0;
}