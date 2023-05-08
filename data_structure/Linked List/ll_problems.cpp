#include "linked_list.cpp"
// #include "circular_linked_list.cpp" // To test for cicrular LL

#include <map>

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


/////////////////////////////////////////
// Check if a List is circular
bool is_circular_ll(Node* head) {
  if (head == NULL)
  {
    return true;
  }

  if (head->next == NULL)
  {
    return false;
  }
  else if (head->next == head)
  {
    return true;
  }

  Node* slow = head;
  Node* fast = head;
  bool isCircular = false;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow->data == fast->data)
    {
      isCircular = true;
      break;
    }
  }

  return isCircular;
}

bool is_circular_ll2(Node *head)
{
  if (head == NULL)
  {
    return true;
  }

  if (head->next == NULL)
  {
    return false;
  }
  else if (head ->next == head)
  {
    return true;
  }

  Node *temp = head;
  while (temp != NULL && temp != head)
  {
    temp = temp->next;
  }

  if (temp == NULL)
  {
    return false;
  }
  else if (temp == head)
  {
    return true;
  }
}

/////////////////////////////////////////////
// Detect a cycle in the loop

bool is_cycle_present(Node* head)
{
  if (head == NULL)
  {
    return false;
  }
  
  map<Node*, bool> visited;
  Node *temp = head;

  while (temp != NULL)
  {
    if (visited[temp] == true)
    {
      return true;
    }
    else
    {
      visited[temp] = true;
    }
    temp = temp->next;
  }

  return false;
}


Node* is_cycle_present_floyd(Node *head)
{
  if (head == NULL)
  {
    return NULL;
  }

  Node *slow = head;
  Node *fast = head;

  while (slow != NULL && fast != NULL)
  {
    slow = slow->next;
    fast = fast->next;
    if (fast != NULL)
    {
      fast = fast->next;
    }
    if (slow == fast)
    {
      return slow;
    }
  }
  return NULL;
}

Node* get_starting_node_of_cycle(Node *head)
{
  if (head == NULL)
  {
    return NULL;
  }

  Node *intersection = is_cycle_present_floyd(head);

  Node *slow = head;
  while (slow != intersection)
  {
    slow = slow->next;
    intersection = intersection->next;
  }

  return slow;
}

void remove_cycle_ll(Node *head)
{
  if (head == NULL)
  {
    return;
  }

  Node* start_node = get_starting_node_of_cycle(head);
  Node* temp = start_node;

  while (temp->next != start_node)
  {
    temp = temp->next;
  }

  cout << "removing cycle from node : " << temp->data;
  cout << " pointing to " << start_node->data << endl;
  temp->next = NULL;

}


int main()
{
  Node* head = new Node(1);
  Node* tail = head; // as there exist only one node
  print_linked_list(head);
  insert_at_head(head, 2);
  print_linked_list(head);
  insert_at_head(head, 3);
  print_linked_list(head);
  insert_at_tail(tail, 4);
  print_linked_list(head);
  insert_at_tail(tail, 5);
  print_linked_list(head);

  insert_at_position(head, tail, 4, 6);
  print_linked_list(head);
  insert_at_position(head, tail, 7, 7);
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
  // head = k_reverse_ll(head, 2);
  // cout << "Reversed : ";
  // print_linked_list(head);

  // Check if a linked list is circular
  // Node *tail = NULL;
  // insert_node(tail, 5, 3);
  // print_cll(tail);
  // insert_node(tail, 3, 2);
  // print_cll(tail);
  // insert_node(tail, 2, 1);
  // print_cll(tail);
  // cout << "Is Circular ?? " << (is_circular_ll(tail) ? "Yes" : "No") << endl;

  // Detect a cycle in the loop
  tail->next = head->next;  // to create a cycle in the LL
  bool is_present = is_cycle_present(head);
  cout << "Is Cycle Present ?? " << (is_present ? "Yes" : "No") << endl;
  if (is_present)
  {
    Node *start = get_starting_node_of_cycle(head);
    cout << "Starting node of cycle : " << start->data << endl;
    remove_cycle_ll(head);
    is_present = is_cycle_present(head);
    cout << "Is Cycle Present ?? " << (is_present ? "Yes" : "No") << endl;
  }

  return 0;
}