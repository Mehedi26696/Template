

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void Inorder(Node* & root){
    // base case 
    if(root == NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(Node* & root){
    // base case 
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    Inorder(root->left);
    Inorder(root->right);
}

void Postorder(Node* & root){
    // base case 
    if(root == NULL){
        return;
    }
    
    
    Inorder(root->left);
    Inorder(root->right);
    cout<<root->data<<" ";
}



Node* insertIntoBST(Node* & root ,int d){
    //base case

    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data ){
        // right subtree

        root->right = insertIntoBST(root->right , d);
    }

    else{

        // left subtree
        root->left = insertIntoBST(root->left,d);
    }

    return root;
}

bool search(Node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        return false;
    }
    if (d == root->data)
    {
        return true;
    }
    else if (d > root->data)
    {
        // right subtree
        return search(root->right, d);
    }
    else
    {
        // left subtree
        return search(root->left, d);
    }   
}

Node * minValueNode(Node* node) 
{ 
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) {
        current = current->left; 
    }
         
    return current; 
}

Node * maxValueNode(Node* node) 
{ 
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->right != NULL) {
        current = current->right; 
    }
         
    return current; 
}


Node * InorderPredecessor(Node* root, int key){
    Node* pre = NULL;
    Node* current = root;
    while(current != NULL){
        if(current->data == key){
            if(current->left != NULL){
                pre = current->left;
                while(pre->right != NULL){
                    pre = pre->right;
                }
            }
            return pre;
        }
        else if(current->data < key){
            pre = current;
            current = current->right;
        }
        else{
            current = current->left;
        }
    }
    return pre;
}


Node * InorderSuccessor(Node* root, int key){
    Node* suc = NULL;
    Node* current = root;
    while(current != NULL){
        if(current->data == key){
            if(current->right != NULL){
                suc = current->right;
                while(suc->left != NULL){
                    suc = suc->left;
                }
            }
            return suc;
        }
        else if(current->data < key){
            current = current->right;
        }
        else{
            suc = current;
            current = current->left;
        }
    }
    return suc;
}


Node * deleteFromBST(Node* root , int key){
    if(root == NULL){
        return root;
    }

    if(key < root->data){
        root->left = deleteFromBST(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteFromBST(root->right,key);
    }
    else{
        // case 1: Node to be deleted is leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case 2: Node to be deleted has one child
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // case 3: Node to be deleted has two children
        Node* temp = InorderSuccessor(root,root->data);
        root->data = temp->data;
        root->right = deleteFromBST(root->right,temp->data);
    }
}
 

int main() {
    Node* root = NULL;
    root = insertIntoBST(root, 5);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);
    insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);
    cout<<"Inorder Traversal : ";
    Inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal : ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal : ";
    Postorder(root);

    cout<<endl;

    if(search(root, 4)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    Node* minNode = minValueNode(root);
    cout<<"Minimum Value Node : "<<minNode->data<<endl;

    Node* maxNode = maxValueNode(root);
    cout<<"Maximum Value Node : "<<maxNode->data<<endl;


    Node* pre = InorderPredecessor(root, 4);
    if(pre != NULL){
        cout<<"Inorder Predecessor of 4 : "<<pre->data<<endl;
    }
    else{
        cout<<"Inorder Predecessor of 4 : NULL"<<endl;
    }

    Node* suc = InorderSuccessor(root, 4);
    if(suc != NULL){
        cout<<"Inorder Successor of 4 : "<<suc->data<<endl;
    }
    else{
        cout<<"Inorder Successor of 4 : NULL"<<endl;
    }

    deleteFromBST(root, 4);
    cout<<"Inorder Traversal : ";
    Inorder(root);
    cout<<endl;
    return 0;
}


