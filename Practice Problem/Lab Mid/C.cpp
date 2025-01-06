//13
// In this problem, you will have to check whether two binary trees are equal or not.
// Input:
// First line: r1, the value of root of the first tree. (-2147483648<=r1<=2147483647)
// Next line: n1, the number of operations. (1<=n1<=10000)
// Next n lines: op key val, three integers (0<=op<=1, -2147483648 <= key, val <=
// 2147483647). If op = 0, set the left child of the node in the first tree with the value key to
// val. If op = 1, set the right child of the node in the first tree with the value key to val. If
// the key is not found, ignore the command.
// Next line: r2, the value of root of the second tree. (-2147483648<=r2<=2147483647)
// Next line: n2, the number of operations. (1<=n2<=10000)
// Next n lines: op key val, three integers (0<=op<=1, -2147483648 <= key, val <=
// 2147483647). If op = 0, set the left child of the node in the second tree with the value
// key to val. If op = 1, set the right child of the node in the second tree with the value key
// to val. If the key is not found, ignore the command.
// Output:
// 1, if the trees are equal. 0, otherwise.


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
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

    Node *right = find(root->right, key); // Search in the right sub-tree

    if (right) {
        return right; // If found in the right sub-tree
    }

    return NULL; // If not found in any sub-tree
}

// Function to check if two trees are equal

bool areEqual(Node *root1, Node *root2) {
    if (!root1 && !root2) {
        return true; // If both trees are empty
    }

    if (!root1 || !root2) {
        return false; // If one of the trees is empty
    }
    
    if(root1->data != root2->data){
        return false;
    }

    bool  l = areEqual(root1->left, root2->left);

    bool  r = areEqual(root1->right, root2->right);


    return l && r;

}

int main(){
    
    int r1, n1, r2, n2;
    cin >> r1 >> n1;
    Node *root1 = new Node(r1);

    for (int i = 0; i < n1; i++) {
        int op, key, val;
        cin >> op >> key >> val;
        Node *node = find(root1, key);

        if (node) {
            if (op == 0) {
                node->left = new Node(val);
            } else {
                node->right = new Node(val);
            }
        }
    }

    cin >> r2 >> n2;
    Node *root2 = new Node(r2);
    for (int i = 0; i < n2; i++) {
        int op, key, val;
        cin >> op >> key >> val;
        Node *node = find(root2, key);

        if (node) {
            if (op == 0) {
                node->left = new Node(val);
            } else {
                node->right = new Node(val);
            }
        }
    }
 
    cout << areEqual(root1, root2) << endl;

    return 0;
}