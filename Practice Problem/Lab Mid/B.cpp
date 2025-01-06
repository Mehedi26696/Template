//13

// Ternary Tree


// In this problem, you will have a ternary tree of integers where each node has up to three
// children: left child, mid-child, and right child. You will have to print the tree in a new
// order that prints the tree in the following order: left sub-tree, mid sub-tree, node value,
// and finally the right sub-tree.
// Input:
// First line: r, the value of root. (-2147483648<=r<=2147483647)
// Next line: n, the number of operations. (1<=n<=10000)
// Next n lines: op key val, three integers (0<=op<=2, -2147483648<=key,
// val<=2147483647). If op = 0, set the left child of the node with the value key to val. If op
// = 1, set the mid child of the node with the value key to val. If op = 2, set the right child of
// the node with the value key to val. If the key is not found, ignore the command.
// Output:
// Each line contains the values in the tree according to the new order.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right, *middle;

    Node(int data) {
        this->data = data;
        this->left = this->right = this->middle = NULL;
    }
};

// Function to find a node with the given key in the tree
Node* find(Node *root, int key) {
    if (!root){
        return NULL; // If the tree is empty
    }

    if (root->data == key) {
        return root; // If the root node has the key
    }
    
    Node *left = find(root->left, key); // Search in the left sub-tree

    if (left) {
        return left; // If found in the left sub-tree
    }

    Node *middle = find(root->middle, key); // Search in the middle sub-tree

    if (middle) {
        return middle; // If found in the middle sub-tree
    }

    Node *right = find(root->right, key); // Search in the right sub-tree

    if (right) {
        return right; // If found in the right sub-tree
    }

    return NULL; // If not found in any sub-tree
}

// Function to print the tree in the required order
void print(Node *root) {
    if (!root) return;

    // Left Sub-tree
    print(root->left);
    // Middle Sub-tree
    print(root->middle);
    // Node Value
    cout << root->data << endl;
    // Right Sub-tree
    print(root->right);
}

int main() {
    int r, n;
    cin >> r >> n;

    Node *root = new Node(r);

    while (n--) {
        int op, key, val;
        cin >> op >> key >> val;

        // Find the node with the given key
        Node *parent = find(root, key);
        
        if (!parent) {
            continue; // If the key is not found, ignore the command
        }

        // Create a new node for the value
        Node *child = new Node(val);

        // Assign the child to the correct position
        if (op == 0) {
            parent->left = child; // Add as left child
        } else if (op == 1) {
            parent->middle = child; // Add as middle child
        } else if (op == 2) {
            parent->right = child; // Add as right child
        }
    }

    print(root); // Print the tree in the required order

    return 0;
}
