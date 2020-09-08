#include <iostream>

using namespace std;

/* Datenstruktur eines Knotes des Baums */
struct Node {
    int value;
    Node *left, *right;
    Node *parent;  // optional
};

//Node * root = NULL;

int insertNode(Node ** n, int val){

    Node * temp = new Node();
    temp->value = val;

    if(*n == NULL){
        *n = temp;
        return 0;
    }
    else{
            
        if(temp->value < (*n)->value){

            cout << "Gehe nach links" << endl;
    
            //(*n)->left->parent = *n; //gibt nhn Segmentation error
            insertNode( &((*n)->left), val);

            return 0;

        }
    
        if(temp->value > (*n)->value){

            cout << "Gehe nach rechts" << endl;
            //(*n)->right->parent = *n; //gibt Segmentation errror

            insertNode(&((*n)->right),val);

            return 0;

        }
        
    }

    return -1;
}

void inorder(Node * n){
 
   if(n == NULL){
       cerr << "Ende des Knotens" << endl;
       return;
   }
    cout << n->value << endl;
    inorder(n->left);
    inorder(n->right);
    
}

int main() {
    
    int temp = 0;

    Node * root = NULL;

    temp = insertNode(&root, 5);
    cout << temp << endl;
    temp = insertNode(&root, 1);
    cout << temp << endl;
    temp = insertNode(&root, 7);
    cout << temp << endl;
    temp = insertNode(&root, 4);
    cout << temp << endl;
    temp = insertNode(&root, 9);
    cout << temp << endl;
    temp = insertNode(&root, 2);
    cout << temp << endl;
    temp = insertNode(&root, 8);
    cout << temp << endl;
    temp = insertNode(&root, 3);
    cout << temp << endl;

    inorder(root);

    cout << "Skrr!" << endl;

    return 0;
}
