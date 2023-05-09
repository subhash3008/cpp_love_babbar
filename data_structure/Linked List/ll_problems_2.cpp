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

/////////////////////////////////////////
// Sort 0s, 1s and 2s in an array

void sort_012_ll_count(Node* &head)
{
  map<int, int> count_numbers;
  Node *curr = head;
  while (curr != NULL)
  {
    count_numbers[curr->data]++;
    curr = curr->next;
  }

  curr = head;
  while (curr != NULL)
  {
    if (count_numbers[0] != 0)
    {
      curr->data = 0;
      count_numbers[0]--;
    }
    else if (count_numbers[1] != 0)
    {
      curr->data = 1;
      count_numbers[1]--;
    }
    else if (count_numbers[2] != 0)
    {
      curr->data = 2;
      count_numbers[2]--;
    }
    curr = curr->next;
  }
}

void insert_sort_012_tail(Node* &tail, Node* & curr)
{
  tail->next = curr;
  tail = curr;
}

void sort_012_ll_link(Node* &head)
{
  Node *zeroHead = new Node(-1);
  Node *zeroTail = zeroHead;
  Node *oneHead = new Node(-1);
  Node *oneTail = oneHead;
  Node *twoHead = new Node(-1);
  Node *twoTail = twoHead;

  Node *curr = head;
  // Populate 3 separate linked lists
  while (curr != NULL)
  {
    int val = curr->data;
    if (val == 0)
    {
      insert_sort_012_tail(zeroTail, curr);
    }
    else if (val == 1)
    {
      insert_sort_012_tail(oneTail, curr);
    }
    else if (val == 2)
    {
      insert_sort_012_tail(twoTail, curr);
    }
    curr = curr->next;
  }

  // merge the list now
  if (oneHead->next != NULL) // 1s List is not empty
  {
    zeroTail->next = oneHead->next;
  }
  else
  {
    // 1s List is empty
    zeroTail->next = twoHead->next;
  }

  oneTail->next = twoHead->next;
  twoTail->next = NULL;

  head = zeroHead->next;

  // delete dummy nodes
  zeroHead->next = NULL;
  delete zeroHead; 
  oneHead->next = NULL;
  delete oneHead;
  twoHead->next = NULL;
  delete twoHead;
}


////////////////////////////////////////
// Merge two sorted linked lists
Node* merge_two_sorted_ll(Node* head1, Node* head2)
{
  if (head1 == NULL)
  {
    return head2;
  }

  if (head2 == NULL)
  {
    return head1;
  }

  Node *prev = head1;
  Node *curr = head1->next;
  Node *temp = head2;
  while (curr != NULL && temp != NULL)
  {
    if ((temp->data >= prev->data) && (temp->data <= curr->data))
    {
      prev->next = temp;
      Node *temp_next = temp->next;
      temp->next = curr;
      
      prev = temp;
      temp = temp_next;
    }
    else
    {
      prev = curr;
      curr = curr->next;
    }
  }

  if (temp != NULL)
  {
    prev->next = temp;
    curr = temp;
  }

  return head1;
}

////////////////////////////////////////////////
// Check if a linked list is palindrome
Node* get_middle_node(Node* head)
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

Node* reverse(Node* head)
{
  Node* curr = head;
  Node *prev = NULL;
  Node *next = NULL;
  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}


bool is_palindrome_ll(Node* head)
{
  if (head == NULL || head->next == NULL)
  {
    return true;
  }

  // get middle
  Node *mid = get_middle_node(head);
  cout << "Middle data : " << mid->data << endl;

  // reverse 2nd half
  mid->next = reverse(mid->next);
  print_linked_list(head);

  // compare both halves
  Node *head1 = head;
  Node *head2 = mid->next;

  bool res = true;
  while (head1 != mid && head2 != NULL)
  {
    if (head1->data != head2->data)
    {
      res = false;
      break;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  cout << "Cheked palindrome. reversing the list 2nd half..." << endl;

  // reverse 2nd half to get original LL
  mid->next = reverse(mid->next);
  print_linked_list(head);

  return res;
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
  // Node *head = new Node(4);
  // Node *tail = head;
  // insert_at_tail(tail, 2);
  // insert_at_tail(tail, 5);
  // insert_at_tail(tail, 4);
  // insert_at_tail(tail, 4);
  // insert_at_tail(tail, 4);
  // insert_at_tail(tail, 2);
  // insert_at_tail(tail, 2);
  // insert_at_tail(tail, 5);
  // print_linked_list(head);
  // remove_dup_unsorted_ll_nested_loop(head);
  // remove_dup_unsorted_ll_map(head);
  // print_linked_list(head);

  // Sort 0s 1s and 2s in a LL
  // Node *head = new Node(1);
  // Node *tail = head;
  // insert_at_tail(tail, 0);
  // insert_at_tail(tail, 2);
  // insert_at_tail(tail, 0);
  // insert_at_tail(tail, 1);
  // insert_at_tail(tail, 2);
  // insert_at_tail(tail, 0);
  // print_linked_list(head);

  // // sort_012_ll_count(head);
  // sort_012_ll_link(head);
  // print_linked_list(head);

  // Merge two sorted Linked Lists
  // Node *head1 = new Node(1);
  // Node *tail1 = head1;
  // // insert_at_tail(tail1, 3);
  // // insert_at_tail(tail1, 4);
  // // insert_at_tail(tail1, 6);
  // print_linked_list(head1);

  // Node *head2 = new Node(7);
  // Node *tail2 = head2;
  // // insert_at_tail(tail2, 8);
  // print_linked_list(head2);

  // Node *head = merge_two_sorted_ll(head1, head2);
  // print_linked_list(head);

  // Check if a LL is palindrome
  Node* head = new Node(1);
  Node *tail = head;
  insert_at_tail(tail, 2);
  insert_at_tail(tail, 3);
  insert_at_tail(tail, 4);
  insert_at_tail(tail, 3);
  insert_at_tail(tail, 2);
  insert_at_tail(tail, 1);
  print_linked_list(head);

  cout << (is_palindrome_ll(head) ? "Palindrome" : "Not a Palindrome") << endl;

  return 0;
}