
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

    void insert_atHead(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }

    void insert_atTail(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    void insert_atPos(int x, int pos){
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        temp->prev = NULL;

        Node* temp1 = head;
        for(int i=0; i<pos-2; i++){
            temp1 = temp1->next;
        }

        temp->next = temp1->next;
        temp1->next->prev = temp;
        temp1->next = temp;
        temp->prev = temp1;
    }

    void delete_atHead(){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

    void delete_atTail(){


        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    void delete_atPos(int pos){
        Node* temp = head;
        for(int i=0; i<pos-2; i++){
            temp = temp->next;
        }



        Node* temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;

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

    l.insert_atHead(10);
    cout<<endl;
    l.print();

    l.insert_atTail(20);
    cout<<endl;
    l.print();

    l.insert_atPos(30, 3);

    cout<<endl;

    l.print();

    l.delete_atHead();
    cout<<endl;

    l.print();

    l.delete_atTail();

    cout<<endl;

    l.print();

    l.delete_atPos(3);

    cout<<endl;

    l.print();
    

    return 0;

}

