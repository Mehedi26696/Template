//13
#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct LinkedListNode {
    LinkedListNode* next;
    int val;
};

struct LinkedList {
    LinkedListNode* head = NULL;
    LinkedListNode* tail = NULL;

    void insert_last(int x) {
        LinkedListNode* a = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        a->next = NULL;
        a->val = x;
        if (tail) {
            tail->next = a;
            tail = a;
        } else {
            head = a;
            tail = a;
        }
    }

    void print() {
        LinkedListNode* p = head;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

struct LinkedListofLinkedListNode {
    LinkedListofLinkedListNode* next;
    LinkedList* list;
};

struct LinkedListofLinkedList {
    LinkedListofLinkedListNode* head = NULL;
    LinkedListofLinkedListNode* tail = NULL;

    void insert_last(LinkedList* x) {
        LinkedListofLinkedListNode* a = (LinkedListofLinkedListNode*)malloc(sizeof(LinkedListofLinkedListNode));
        a->next = NULL;
        a->list = x;
        if (tail) {
            tail->next = a;
            tail = a;
        } else {
            head = a;
            tail = a;
        }
    }
};

LinkedList* sortLinkedListofLinkedList(LinkedListofLinkedList* lol) {
    if (!lol->head) {

        return NULL;
    }

    LinkedListofLinkedListNode* current = lol->head;
    LinkedList* merged = current->list;  
    current = current->next;

    while (current) {
        LinkedListNode* p1 = merged->head;
        LinkedListNode* p2 = current->list->head;
        LinkedList* temp = new LinkedList();  
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                temp->insert_last(p1->val);
                p1 = p1->next;
            } else {
                temp->insert_last(p2->val);
                p2 = p2->next;
            }
        }

     
        while (p1) {
            temp->insert_last(p1->val);
            p1 = p1->next;
        }
        while (p2) {
            temp->insert_last(p2->val);
            p2 = p2->next;
        }

        merged = temp; 
        current = current->next;
    }

    return merged;
}

int main() {
    int n, m, v;
    cin >> n;
    LinkedListofLinkedList* lol = new LinkedListofLinkedList();
    for (int i = 0; i < n; i++) {
        LinkedList* l = new LinkedList();
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> v;
            l->insert_last(v);
        }
        lol->insert_last(l);
    }

    LinkedList* sorted = sortLinkedListofLinkedList(lol);

    sorted->print();

    return 0;
}
