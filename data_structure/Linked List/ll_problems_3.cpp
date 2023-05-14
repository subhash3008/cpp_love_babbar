#include <iostream>
#include <unordered_map>
#include "linked_list.cpp"

using namespace std;

////////////////////////////////////////////
// Add 2 Linked Lists
Node* reverse_ll(Node* head)
{
  Node* curr = head;
  Node* prev = NULL;
  Node* next = NULL;
  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

void insert_at_sum_tail(Node* &head, Node* &tail, int num)
{
  Node *temp = new Node(num);
  if (head == NULL)
  {
    head = temp;
    tail = temp;
    return;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

Node* add_two_ll(Node* head1, Node* head2)
{
  // reverse
  Node* first = reverse_ll(head1);
  Node* second = reverse_ll(head2);
  // sum
  Node* sumHead = NULL;
  Node* sumTail = sumHead;
  int carry = 0;

  while ((first != NULL) || (second != NULL) || (carry != 0))
  {
    int val1 = 0;
    if (first != NULL)
    {
      val1 = first->data;
    }

    int val2 = 0;
    if (second != NULL)
    {
      val2 = second->data;
    }

    int sum = carry + val1 + val2;
    int digit = sum % 10;
    insert_at_sum_tail(sumHead, sumTail, digit);
    carry = sum / 10;

    if (first != NULL)
    {
      first = first->next;
    }
    if (second != NULL)
    {
      second = second->next;
    }
  }

  // reverse to get final LL
  return reverse_ll(sumHead);
}

/////////////////////////////////////////////
// Clone a Random ptr Linked list
class NodeR: public Node
{
public:
  NodeR* next;
  NodeR* random;

  // constructor
  NodeR(int d): Node(d)
  {
    this->next = NULL;
    this->random = NULL;
  }
};

// Intsert at head
void insert_at_head(NodeR* &head, int d)
{
  // Create  new node
  NodeR *temp = new NodeR(d);
  temp->next = head;
  head = temp;
}

// Insert at tail
void insert_at_tail(NodeR* &head, NodeR* &tail, int d)
{
  NodeR* temp = new NodeR(d);
  if (head == NULL && tail == NULL)
  {
    head = temp;
    tail = temp;
    return;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

void print_linked_list(NodeR* head)
{
  NodeR* temp = head;
  while (temp != NULL)
  {
    cout << "el : " << temp->data;
    if (temp->random != NULL)
    {
      cout << ", random: " << temp->random->data << endl;
    }
    temp = temp->next;
  }
  cout << endl;
}

// Perform cloning using map
NodeR* clone_random_ptr_ll_map(NodeR* head)
{
  NodeR* cloneHead = NULL;
  NodeR* cloneTail = NULL;

  NodeR* temp = head;
  while (temp != NULL)
  {
    insert_at_tail(cloneHead, cloneTail, temp->data);
    temp = temp->next;
  }

  unordered_map<NodeR*, NodeR*> oldToNewMapping;

  NodeR *origNode = head;
  NodeR *clonedNode = cloneHead;
  while (origNode != NULL && clonedNode != NULL)
  {
    oldToNewMapping[origNode] = clonedNode;
    origNode = origNode->next;
    clonedNode = clonedNode->next;
  }
  
  origNode = head;
  clonedNode = cloneHead;
  while (origNode != NULL)
  {
    clonedNode->random = oldToNewMapping[origNode->random];
    origNode = origNode->next;
    clonedNode = clonedNode->next;
  }
  return cloneHead;
}

// perform cloning without using map
NodeR* clone_random_ptr_ll_n_map(NodeR* head)
{
  NodeR* oHead = head;
  NodeR* cHead = NULL;
  NodeR* cTail = NULL;

  NodeR* temp = head;
  while (temp != NULL)
  {
    insert_at_tail(cHead, cTail, temp->data);
    temp = temp->next;
  }

  NodeR* oNode = head;
  NodeR* cNode = cHead;
  while (oNode != NULL)
  {
    NodeR* next = oNode->next;
    oNode->next = cNode;
    oNode = next;

    next = cNode->next;
    cNode->next = oNode;
    cNode = next;
  }

  oNode = oHead;
  cNode = cHead;

  while (cNode != NULL)
  {
    cNode->random = oNode->random->next;
    oNode = oNode->next;
    if (oNode != NULL)
    {
      oNode = oNode->next;
    }
    cNode = cNode->next;
    if (cNode != NULL)
    {
      cNode = cNode->next;
    }
  }

  oNode = oHead;
  cNode = cHead;
  while (oNode != NULL)
  {
    oNode->next = cNode->next;
    oNode = oNode->next;

    if (oNode != NULL)
    {
      cNode->next = oNode->next;
    }
    else
    {
      cNode->next = NULL;
    }
    cNode = cNode->next;
  }

  return cHead;
}

////////////////////////////////////////////
// Merge Sort in Linked List

Node* find_mid(Node* &head)
{
  Node* slow = head;
  Node* fast = head->next;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

Node* merge_two_sorted_ll(Node* left, Node* right)
{
  if (left == NULL)
  {
    return right;
  }

  if (right == NULL)
  {
    return left;
  }
  
  Node* res = new Node(-1);
  Node* temp = res;

  while (left != NULL && right != NULL)
  {
    if (left->data < right->data)
    {
      temp->next = left;
      temp = left;
      left = left->next;
    }
    else
    {
      temp->next = right;
      temp = right;
      right = right->next;
    }
  }

  while (left != NULL)
  {
    temp->next = left;
    temp = left;
    left = left->next;
  }

  while (right != NULL)
  {
    temp->next = right;
    temp = right;
    right = right->next;
  }

  return res->next;
}

Node* merge_sort(Node* &head)
{
  // base case
  if (head == NULL || head->next == NULL)
  {
    return head;
  }

  // break ll into two halves after finding mid
  Node* mid = find_mid(head);
  Node* left = head;
  Node* right = mid->next;
  mid->next = NULL;
  // recursive calls to sort both halves
  left = merge_sort(left);
  right = merge_sort(right);

  return merge_two_sorted_ll(left, right);
}

//////////////////////////////////////////
// Flatten a linked list
class NodeC: public Node
{
public:
  NodeC* next;
  NodeC* child;

  NodeC(int d): Node(d)
  {
    this->next = NULL;
    this->child = NULL;
  }
};

void print_linked_list(NodeC* head)
{
  NodeC* temp = head;
  while (temp != NULL)
  {
    NodeC* tempC = temp;
    while (tempC != NULL)
    {
      cout << tempC->data << " ";
      tempC = tempC->child;
    }
    temp = temp->next;
  }
  cout << endl;
}

Node* flatten_ll(NodeC* head)
{
  if (head == NULL)
  {
    return NULL;
  }

  Node* res = new Node(head->data);
  Node* node = res;
  NodeC* temp = head->child;
  while (temp != NULL)
  {
    Node* next = new Node(temp->data);
    node->next = next;
    node = next;

    temp = temp->child;
  }

  print_linked_list(res);

  Node* right = flatten_ll(head->next);
  return merge_two_sorted_ll(res, right);
}

int main()
{
  // add 2 linked lists
  // Node* head1 = new Node(5);
  // Node* tail1 = head1;
  // insert_at_tail(tail1, 0);
  // print_linked_list(head1);

  // Node* head2 = new Node(1);
  // Node* tail2 = head2;
  // insert_at_tail(tail2, 5);
  // insert_at_tail(tail2, 0);
  // print_linked_list(head2);

  // Node* sum = add_two_ll(head1, head2);
  // print_linked_list(sum);

  // Clone a linked list with random pointer
  // makeshift code to test the logic
  // NodeR* head = new NodeR(1);
  // NodeR* tail = head;
  // insert_at_tail(head, tail, 2);
  // insert_at_tail(head, tail, 3);
  // insert_at_tail(head, tail, 4);
  // insert_at_tail(head, tail, 5);
  // head->random = head->next->next; // 1->3
  // head->next->random = head;       // 2->1
  // head->next->next->random = head->next->next->next->next; // 3->5
  // head->next->next->next->random = head->next->next; // 4->3
  // head->next->next->next->next->random = head->next; // 5->2

  // // NodeR* clonedLLMap = clone_random_ptr_ll_map(head);
  // // cout << "original : " << endl;
  // // print_linked_list(head);
  // // cout << "Cloned LL:" << endl;
  // // print_linked_list(clonedLLMap);

  // cout << "Original : " << endl;
  // print_linked_list(head);
  // NodeR* clonedLLNMap = clone_random_ptr_ll_n_map(head);
  // cout << "Cloned LL:" << endl;
  // print_linked_list(clonedLLNMap);

  // Merge Sort in Linked List
  // Node* head = new Node(3);
  // Node* tail = head;
  // insert_at_tail(tail, 2);
  // insert_at_tail(tail, 1);
  // insert_at_tail(tail, 5);
  // insert_at_tail(tail, 9);
  // print_linked_list(head);

  // cout << "Sorting....." << endl;
  // Node* sortedll = merge_sort(head);
  // print_linked_list(sortedll);

  // Flatten a linked List
  NodeC* head = new NodeC(1);
  head->child = new NodeC(2);
  head->child->child = new NodeC(3);
  head->child->child->child = new NodeC(4);
  head->next = new NodeC(5);
  head->next->child = new NodeC(6);
  head->next->child->child = new NodeC(7);
  head->next->next = new NodeC(8);
  head->next->next->child = new NodeC(9);
  head->next->next->next = new NodeC(10);
  print_linked_list(head);

  Node* flatLL = flatten_ll(head);
  print_linked_list(flatLL);

  return 0;
}