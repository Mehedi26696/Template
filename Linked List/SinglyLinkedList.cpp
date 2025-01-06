

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

    void insert_atHead(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = head;
        head = temp;
    }

    void insert_atTail(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }

    void insert_atPos(int x, int pos){
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;

        Node* temp1 = head;
        for(int i=0; i<pos-2; i++){
            temp1 = temp1->next;
        }

        temp->next = temp1->next;
        temp1->next = temp;
    }


    void delete_atHead(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_atTail(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        
        tail = temp;
        Node* temp1 = temp->next;
        temp->next = NULL;
        delete temp1;
    }

    void delete_atPos(int pos){
        Node* temp = head;
        for(int i=0; i<pos-2; i++){
            temp = temp->next;
        }

        Node* temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
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

    l.insert_atHead(10);
    l.print();
    cout<<endl;

    l.insert_atTail(20);
    l.print();

    cout<<endl;

    l.insert_atPos(15, 3);

    l.print();

    cout<<endl;

    l.delete_atHead();

    l.print();

    cout<<endl;

    l.delete_atTail();

    l.print();

    cout<<endl;

    l.delete_atPos(3);

    l.print();
}