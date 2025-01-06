
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
 

Node* buldTreeDynamically(Node* root ){
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new Node(data); // Create a new node with the input data

    // Base case for recursion

    if (data == -1)
    {
        return NULL; // If data is -1, this node is NULL
    }

    // Recursively build the left and right subtrees
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buldTreeDynamically(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buldTreeDynamically(root->right);

    return root;
}

void printInorder(Node* node) {
    if (node == NULL) {
        return;
    }

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(Node* node) {
    if (node == NULL) {
        return;
    }

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node* node) {
    if (node == NULL) {
        return;
    }

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}


int main() {
    
    Node* root = NULL;
    root = buldTreeDynamically(root);

    cout << "Inorder: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder: ";
    printPreorder(root);
    cout << endl;

    cout << "Postorder: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
