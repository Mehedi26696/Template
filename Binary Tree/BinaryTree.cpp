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

// Helper function to find the node with the given key
Node* findNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    Node* leftResult = findNode(root->left, key);
    if (leftResult != NULL) {
        return leftResult;
    }

    return findNode(root->right, key);
}

Node* insert(Node* root, int option, int key, int data) {
    if (root == NULL) {
        return NULL; // Key not found, so insertion cannot happen
    }

    // Find the node with the given key
    Node* targetNode = findNode(root, key);

    if (targetNode == NULL) {
        cout << "Key " << key << " not found. Cannot insert " << data << "." << endl;
        return root;
    }

    // Insert the new node as the left or right child
    if (option == 1) {
        if (targetNode->left == NULL) {
            targetNode->left = new Node(data);
        } else {
            cout << "Left child of node " << key << " already exists." << endl;
        }
    } else if (option == 2) {
        if (targetNode->right == NULL) {
            targetNode->right = new Node(data);
        } else {
            cout << "Right child of node " << key << " already exists." << endl;
        }
    }

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
    // Create the root node
    Node* root = new Node(1);

    // Insert nodes using the key
    root = insert(root, 1, 1, 2); // Insert 2 as the left child of node 1
    root = insert(root, 2, 1, 3); // Insert 3 as the right child of node 1
    root = insert(root, 1, 2, 4); // Insert 4 as the left child of node 2
    root = insert(root, 2, 2, 5); // Insert 5 as the right child of node 2
    root = insert(root, 1, 3, 6); // Insert 6 as the left child of node 3
    root = insert(root, 2, 3, 7); // Insert 7 as the right child of node 3

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
