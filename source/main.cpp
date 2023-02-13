#include <iostream>
#include <vector>
#include "MyVector.h"
#include "MyLinkedList.h"
#include "MyStack.h"

using namespace std;

/*#pragma region linked LinkedList

class LinkedList {
    struct Node {
    public:
        Node(const int& d) : data(d), next(nullptr) {}
        ~Node() { if (next) { delete next; next = nullptr; } }

    public:
        int data;
        Node* next;
    };

public:
    LinkedList() : head(nullptr), tail(nullptr), size_(0) {}
    ~LinkedList() { if (head) { delete head; head = nullptr; } }

public:
    void push_front(const int& d) {
        Node* newNode = new Node(d);

        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        ++size_;
    }

    void push_back(const int& d) {
        Node* newNode = new Node(d);

        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        ++size_;
    }

    void pop_front() {
        Node* t = head;
        head = head->next;
        t->next = nullptr;
        delete t;
        --size_;
    }

    void pop_back() {
        Node* t = find(size_ - 2);
        t->next = nullptr;
        delete tail;
        tail = t;

        --size_;
    }

    void insert(const int& d, const int& idx) {
        int i = 0;
        Node* h = head;

        if (idx == 0) {
            push_front(d);
            return;
        }

        while (h && i < idx) {
            h = h->next;
            ++i;
        }

        if (!h) return;

        Node* newNode = new Node(d);
        newNode->next = h->next;
        h->next = newNode;

        ++size_;
    }

    // ¼±ÇüÅ½»ö
    int search(const int& key) {
        Node* h = head;
        int idx = 0;

        while (h) {
            if (h->data == key) return idx;
            ++idx;
            h = h->next;
        }
        return -1;
    }

    int searchHelper(Node* node, const int& key) {
        if (!node) return -1;
        if (node->data == key) return 0;

        int idx = searchHelper(node->next, key);
        
        if (idx == -1) return -1;
        return idx + 1;
    }

    // ¼±ÇüÅ½»ö : Àç±Í
    int recursiveSearch(const int& key) { 
        return searchHelper(head, key);
    }

    void Print() const {
        Node* h = head;

        while (h) {
            cout << h->data << '\n';
            h = h->next;
        }
    }

    inline const int& size() const { return size_; }

private:
    Node* find(const int& idx) {
        Node* n = head;
        int i = 0;

        while (n && i < idx) {
            n = n->next;
            ++i;
        }

        return n;
    }

    void remove(const int& idx) {
        Node* n = head;


    }

private:
    Node* head;
    Node* tail;
    int size_;
};
#pragma endregion */

#pragma region linked list


#pragma endregion

using namespace std;

template <typename _Ty>
void Func(const _Ty& _val)
{
    cout << "¿Þ°ª" << endl;
}

template <typename _Ty>
void Func(_Ty&& _val)
{
    cout << "¿À¸¥°ª" << endl;
}

template <typename _Ty>
void TestFunc(_Ty&& _val)
{
    Func<_Ty>(forward<_Ty>(_val));
}

int main() {
    MyVector<int> vec;
    MyStack<int> st;
    MyLinkedList<int> lst;

    vec.emplace_back(10);
    int a = 20;
    vec.emplace_back(a);

	return 0;
}