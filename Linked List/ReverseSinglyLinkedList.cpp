



#include<iostream>

using namespace std;

struct ll{

    struct Node{
        int data;
        Node* next;
    };

    Node* head = NULL;
    Node* tail = NULL;

    void insert(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
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
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        tail = head;
        head = prev;
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

    return 0;
}