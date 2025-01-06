


#include<iostream>

using namespace std;

struct ll{

    struct Node{
        int data;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;
    Node* tail = NULL;

    void insert(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        temp->prev = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    void reverse(){
        Node* temp = head;
        while(temp != NULL){
            Node* temp1 = temp->next;
            temp->next = temp->prev;
            temp->prev = temp1;
            temp = temp1;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
};

int main(){
    int n;
    cin>>n;

    ll l;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        l.insert(x);
    }

    l.print();
    cout<<endl;

    l.reverse();

    l.print();
}