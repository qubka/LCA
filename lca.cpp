#include <iostream> 
#include <vector> 

using namespace std; 

struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 

Node *newNode(int index) 
{ 
    Node *temp = new Node; 
    temp->key = index; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
