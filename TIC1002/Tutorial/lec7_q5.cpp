#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename T>
struct LinkNode
{
  T item;
  LinkNode<T> *next;
};

// -- DO NOT EDIT ABOVE --

struct Stack
{
  // your code here
  LinkNode<int> *top = NULL;
};

void push(Stack &s, int item)
{
  LinkNode<int> *node = new LinkNode<int>;
  node->item = item;
  node->next = s.top;

  s.top = node;
}

// Note that pop need not return the value that is popped
void pop(Stack &s)
{
  // your code here
  if (s.top == NULL)
    cout << "Stack Underflow" << endl;
  else
  {
    LinkNode<int> *node = s.top;
    cout << "The popped element is " << node->item << endl;

    delete node;

    s.top = s.top->next;
  }
}

void iterate(Stack &s)
{
  LinkNode<int> *curr = s.top;

  while (curr != NULL)
  {
    cout << curr->item << endl;
    curr = curr->next;
  }
}

int peek(Stack &s)
{
  // your code here
  if (s.top == 0)
    return 0;
  return s.top->item;
}

bool empty(Stack &s)
{
  // your code here

  if (s.top == NULL) {
    return true; 
  } 
  return false; 

  // LinkNode<int> *node = s.top;

  // while (s.top != NULL) {
  //   delete node;
  //   s.top = s.top->next;
  // }
  // return s.top; 
}

int main()
{
  Stack stack;
  // init_stack(stack); 

  cout << empty(stack) << endl; 

  push(stack, 3);
  push(stack, 2);
  push(stack, 1);

  // iterate(stack);

  // cout << empty(stack) << endl; 

  pop(stack);
  pop(stack);
  pop(stack);

  // cout << peek(stack) << endl;
  // cout << empty(stack) << endl; 

  push(stack, 1);

  cout << peek(stack) << endl;

  cout << empty(stack) << endl; 

  push(stack, 2);
  push(stack, 1);
  push(stack, 3);

  cout << peek(stack) << endl;

  return 0;
}
