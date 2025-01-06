
#include<iostream>

using namespace std;

struct Queue{
    
    struct Node{
        int val;
        Node *next;
    };

    Node *head = NULL;
    Node *tail = NULL;

    void push(int ch){
        Node *node = (Node *)malloc(sizeof(Node));
        node->val = ch;
        node->next = NULL;

        if(head == NULL){
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void pop(){
        if(head == NULL){
            return;
        }

        Node *node = head;
        head = head->next;
        
        delete node;
    }

    int front(){
        return head->val;
    }
    bool empty(){
        return head == NULL;
    }

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}