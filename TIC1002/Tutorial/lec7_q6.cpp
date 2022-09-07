#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename T>
struct BSTNode
{
  T item;
  BSTNode<T> *left, *right;
};

template <typename T>
void traversal(BSTNode<T> &root)
{
  if (root.left != NULL) {
    traversal<T>(*root.left); 
  }
  cout << root.item << endl; 
  if (root.right != NULL) {
    traversal<T>(*root.right); 
  }
}

template <typename T>
bool valid_BST(BSTNode<T> &root)
{
  // your code here
  if (root.left != NULL) {
    if (root.left->item < root.item) {
      if (!valid_BST<T>(*root.left)) {
        return false; 
      }
    } else {
      return false;
    }
  }

  if (root.right != NULL) {
    if (root.right->item >= root.item) {
      if (!valid_BST<T>(*root.right)) {
        return false; 
      }
    } else {
      return false;
    }
  }
  return true; 
}

// void func2() {
//   cout << "f2";
// }

// void func1() {
//   func2();
//   cout << "f1";
//   func2();
// }

int main()
{
  BSTNode<int> node1;
  node1.item = 1;
  BSTNode<int> node2;
  node2.item = 2;

  // func1();

  BSTNode<int> node3;
  node3.item = 3;
  
  BSTNode<int> node4;
  node4.item = 4;

  BSTNode<int> node5;
  node5.item = 5;

  BSTNode<int> node6;
  node6.item = 6;

  BSTNode<int> node7;
  node7.item = 7;

  node4.right = &node5;
  node4.left = &node3;

  node3.left = &node7; 

  // node3.left = &node2;
  // node2.left = &node1;

  // node5.right = &node6;
  // node6.right = &node7;

  traversal(node4); 

  cout << valid_BST(node4) << endl; 

  return 0;
}
