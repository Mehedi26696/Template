
#include<iostream>

using namespace std;


struct STACK{

    struct Stack{
        int val;
        Stack *next;
    };

    Stack *head = NULL;
    Stack *tail = NULL;

    void push(int ch){
        Stack *node = (Stack *)malloc(sizeof(Stack));
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

        Stack *node = head;
        while(node->next != tail){
            node = node->next;
        }
        tail = node;
        tail->next = NULL;
    }

    int top(){
        return tail->val;
    }

    bool empty(){
        return head == NULL;
    }


};


int main(){

    STACK s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;

}