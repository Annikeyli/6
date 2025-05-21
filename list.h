#include <iostream>
using namespace std;
#include <string.h> 
#include "Znak.h"

template <class T>
class MyList {
    class Node {
    public:
        T info;
        Node* next = nullptr;
        Node(T info, Node* next) :info(info), next(next) {};
        Node(T info) :info(info), next(nullptr) {};
        Node() {};
    };
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    void addBegin(T a);
    void addEnd(T a);
    Node* listCopy(Node* head, Node*& tailCopy);
    int insertList(Node* head, int x);
    bool IsEmpty();
    void deleteEl(T a);
    void deleteList();
    friend ostream& operator<<(ostream& os, MyList<T>& l) {
        for (Node* t = l.head; t != nullptr; t = t->next) os << t->info << " \n";
        return os;
    }
};

template <class T>
void MyList<T>::addBegin(T a) {
    Node* t = new Node(a, head);
    if (!head) head = tail = t;
    else head = t;
}

template <class T>
void MyList<T>::addEnd(T a) {
    Node* t = new Node(a);
    if (!head) {
        head = tail = t; return;
    }
    tail->next = t;
    tail = t;
}

template <class T>
void MyList<T>::deleteList() {
    Node* t = head;
    while (t) {
        Node* g = t;
        t = t->next;
        delete g;
    }
    head = tail = nullptr;
}

template<class T>
bool MyList<T>::IsEmpty() {
    return head == nullptr;

}

template<class T>
void MyList<T>::deleteEl(T a) {
    if (head == nullptr) return;

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->info == a) {
            if (prev == nullptr) {
                head = curr->next;
                if (tail == curr) tail = nullptr;
            }
            else {
                prev->next = curr->next;
                if (tail == curr) tail = prev;
            }
            Node* toDelete = curr;
            curr = curr->next;
            delete toDelete;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

template <class T>
typename MyList<T>::Node* MyList<T>::listCopy(Node* head, Node*& tailCopy) {
    Node* head1 = nullptr;
    Node* prev = nullptr;
    tailCopy = nullptr;

    for (Node* h = head; h; h = h->next) {
        Node* newNode = new Node(h->info);
        if (!head1) {
            head1 = prev = newNode;
        }
        else {
            prev->next = newNode;
            prev = newNode;
        }
        tailCopy = newNode;
    }
    return head1;
}

template <class T>
int MyList<T>::insertList(Node* head, int x) {
    Node* nodeX = nullptr;
    Node* h;
    for (h = head; h && h->info.getNumber() != x; h = h->next);

    if (h) {
        Node* tailCopy = nullptr;
        Node* headCopy = listCopy(head, tailCopy);
        tailCopy->next = h->next;
        h->next = headCopy;
        return 0;
    }
    return -1;
}
