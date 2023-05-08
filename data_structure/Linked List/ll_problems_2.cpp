#include "linked_list.cpp"
#include <map>

/////////////////////////////////////////////////
// Remove Duplicates - sorted LL
void remove_dup_sorted_ll(Node* &head)
{
  if (head == NULL || head->next == NULL)
  {
    return;
  }

  Node *curr = head;

  while (curr->next != NULL)
  {
    if (curr->data == curr->next->data)
    {
      Node *temp = curr->next;
      if (curr->next->next == NULL)
      {
        curr->next = NULL;
      }
      else
      {
        curr->next = curr->next->next;
      }
      temp->next = NULL;
      delete temp;
    }
    else
    {
      curr = curr->next;
    }
  }
}

/////////////////////////////////////////////////
// Remove Duplicates - sorted LL

void remove_dup_unsorted_ll_nested_loop(Node* &head)
{
  if (head == NULL || head->next == NULL)
  {
    return;
  }

  Node *curr = head;
  while (curr != NULL)
  {
    Node *temp = curr->next;
    Node *prev = curr;
    while (temp != NULL)
    {
      if (temp->data == curr->data)
      {
        Node *to_delete = temp;
        temp = temp->next;
        prev->next = temp;
        to_delete->next = NULL;
        delete to_delete;
      }
      else
      {
        prev = temp;
        temp = temp->next;
      }
    }
    curr = curr->next;
  }
}

void remove_dup_unsorted_ll_map(Node* &head)
{
  if (head == NULL && head->next == NULL)
  {
    return;
  }
  map<int, bool> does_exists;
  
  Node *curr = head;
  Node *prev = NULL;

  while (curr != NULL)
  {
    if (does_exists[curr->data] == true)
    {
      Node *to_del = curr;
      curr = curr->next;
      prev->next = curr;
      to_del->next = NULL;
      delete to_del;
    }
    else
    {
      does_exists[curr->data] = true;
      prev = curr;
      curr = curr->next;
    }
  }

}


int main()
{
  // Remove Duplicates - sorted ll
  // Node *head = new Node(1);
  // Node *tail = head;
  // insert_at_tail(tail, 2);
  // insert_at_tail(tail, 2);
  // insert_at_tail(tail, 3);
  // insert_at_tail(tail, 3);
  // insert_at_tail(tail, 3);
  // insert_at_tail(tail, 4);
  // insert_at_tail(tail, 4);
  // insert_at_tail(tail, 5);
  // insert_at_tail(tail, 5);
  // print_linked_list(head);

  // remove_dup_sorted_ll(head);
  // print_linked_list(head);

  // Remove Duplicates - unsorted LL
  Node *head = new Node(4);
  Node *tail = head;
  insert_at_tail(tail, 2);
  insert_at_tail(tail, 5);
  insert_at_tail(tail, 4);
  insert_at_tail(tail, 4);
  insert_at_tail(tail, 4);
  insert_at_tail(tail, 2);
  insert_at_tail(tail, 2);
  insert_at_tail(tail, 5);
  print_linked_list(head);

  // remove_dup_unsorted_ll_nested_loop(head);
  remove_dup_unsorted_ll_map(head);
  
  print_linked_list(head);



  return 0;
}