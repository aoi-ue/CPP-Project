#include <iostream>
using namespace std;

// node constructor 
struct Node {
    int value; 
    struct Node * next; 
}; 

void push(struct Node** head_ref, int node_value) {
    struct Node* newNode = new Node; 

    newNode->value = node_value; 
    newNode->next = (*head_ref); 

    (*head_ref) = newNode; 
}   

void append(struct Node** head_ref, int node_value) {
    struct Node* newNode = new Node; 

    struct Node* last = *head_ref; 

    newNode->value = node_value; 
    newNode->next = NULL; 
    
    if ((*head_ref) == NULL) {
        *head_ref = newNode;
        return; 
    }

    while (last->next != NULL) {
        last = last->next; 
    }

   last->next = newNode; 

}

// remove 


void print_all(struct Node* node){

    while (node != NULL) {
        cout << node->value << "->"; 
        node = node->next; 
    }

    if (node == NULL) cout << "null"; 
}

int main()
{
    cout << "----\n";
    
    // initialize an empty head 
    struct Node* Head = NULL; 

    append(&Head, 30); 
    push(&Head, 20); 
    push(&Head, 10); 
    push(&Head, 20); 
    append(&Head, 30); 

    print_all(Head);

    cout << "\n----";

    return 0;
}