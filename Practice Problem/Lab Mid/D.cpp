//13

// In this problem, you will have to implement a binary search tree.
// You must use the given template.
// Input:
// First line: n, an integer. (1<=n<=10000)
// Next n lines: v (-2147483648<=v<=2147483647), an integer to be inserted in the binary
// search tree.
// Next line: m, an integer. (1<=m<=10000)
// Next m lines: k (-2147483648<=k<=2147483647), an integer to be deleted from the
// binary search tree.
// Output:
// Each line contains the values in the tree according to the in-order traversal.

#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct BST
{
    struct node
    {
        int val;
        node *left;
        node *right;
        node *parent;
         
    };
    node *root = NULL;

    void insert_value(node *p, int x)
    {
        // Your code starts here - 001

         // use recursion to insert the value in the tree
         
        
        if (root == NULL)
        {
            root = new node;
            root->val = x;
            root->left = NULL;
            root->right = NULL;
            root->parent = NULL;
            return;
        }
        if (x < p->val)
        {
            if (p->left == NULL)
            {
                p->left = new node;
                p->left->val = x;
                p->left->left = NULL;
                p->left->right = NULL;
                p->left->parent = p;
                return;
            }
            else
            {
                insert_value(p->left, x);
            }
        }
        else
        {
            if (p->right == NULL)
            {
                p->right = new node;
                p->right->val = x;
                p->right->left = NULL;
                p->right->right = NULL;
                p->right->parent = p;
                return;
            }
            else
            {
                insert_value(p->right, x);
            }
        }
         
        // Your code ends here - 001
    }

    void inorder(node *p)
    {
        // Your code starts here - 002

        if (p == NULL)
        {
            return;
        }
        inorder(p->left);
        cout << p->val << endl;
        inorder(p->right);
        // Your code ends here - 002
    }

    void delete_value(int x)
    {
        // Your code starts here - 003
         
        // use recursion to delete the value from the tree

        node *p = root; 
        while (p != NULL)
        {
            if (p->val == x)
            {
                break;
            }
            if (x < p->val)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (p == NULL)
        {
            return;
        }

        if (p->left == NULL && p->right == NULL)
        {
            if (p->parent == NULL)
            {
                root = NULL;
            }
            else if (p->parent->left == p)
            {
                p->parent->left = NULL;
            }
            else
            {
                p->parent->right = NULL;
            }
            delete p;
        }
        else if (p->left == NULL)
        {
            if (p->parent == NULL)
            {
                root = p->right;
                root->parent = NULL;
            }
            else if (p->parent->left == p)
            {
                p->parent->left = p->right;
                p->right->parent = p->parent;
            }
            else
            {
                p->parent->right = p->right;
                p->right->parent = p->parent;
            }
            delete p;
        }
        else if (p->right == NULL)
        {
            if (p->parent == NULL)
            {
                root = p->left;
                root->parent = NULL;
            }
            else if (p->parent->left == p)
            {
                p->parent->left = p->left;
                p->left->parent = p->parent;
            }
            else
            {
                p->parent->right = p->left;
                p->left->parent = p->parent;
            }
            delete p;
        }
        else
        {
            node *q = p->right;
            while (q->left != NULL)
            {
                q = q->left;
            }
            p->val = q->val;
            if (q->parent->left == q)
            {
                q->parent->left = q->right;
                if (q->right != NULL)
                {
                    q->right->parent = q->parent;
                }
            }
            else
            {
                q->parent->right = q->right;
                if (q->right != NULL)
                {
                    q->right->parent = q->parent;
                }
            }
            delete q;
        }
        
        // Your code ends here - 003
    }
};

int main()
{

    BST *bst = new BST();
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        bst->insert_value(bst->root, v);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        bst->delete_value(v);
    }
    bst->inorder(bst->root);
    return 0;
}
