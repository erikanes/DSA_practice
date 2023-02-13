#pragma once

#include "GlobalDefine.h"

template<typename T>
class MyLinkedList {
private:
    struct Node {
    public:
        Node() = delete;

        explicit Node(const T& d) :
            data(d),
            prev(nullptr),
            next(nullptr)
        {
            std::cout << "왼값 노드 생성" << std::endl;
        }

        explicit Node(T&& d) noexcept :
            data(std::move(d)),
            prev(nullptr),
            next(nullptr)
        {
            std::cout << "오른값 노드 생성" << std::endl;
        }

        explicit Node(const Node& _node) :
            data(_node.data),
            prev(nullptr),
            next(nullptr)
        {
            std::cout << "노드 복사" << std::endl;
        }

        explicit Node(Node&& _node) noexcept :
            data(std::move(_node.data)),
            prev(nullptr),
            next(nullptr)
        {
            std::cout << "노드 이동" << std::endl;
        }
        
        ~Node() { SAFE_DELETE(next) }

    public:
        Node& operator=(const Node& _node)
        {
            data = _node.data;
            prev = nullptr;
            next = nullptr;
        }

        Node& operator=(Node&& _node)
        {
            data = std::move(_node.data);
            prev = std::move(_node.prev);
            next = std::move(_node.next);

            _node.data = 0;
            _node.prev = nullptr;
            _node.next = nullptr;
        }

    public:
        T data;
        Node* prev;
        Node* next;
    };

public:
    //using iterator = typename MyIterator<T, Node>;

public:
    explicit MyLinkedList() : 
        head_(nullptr),
        tail_(head_),
        current_(head_),
        size_(0)
    {}

    explicit MyLinkedList(const MyLinkedList& list) :
        head_(nullptr),
        tail_(head_),
        current_(head_),
        size_(0)
    {
        this->operator=(list);
    }

    explicit MyLinkedList(MyLinkedList&& list) noexcept :
        head_(list.head_),
        tail_(list.tail_),
        current_(head_),
        size_(list.size_)
    {
        this->operator=(std::forward<MyLinkedList>(list));
    }

    ~MyLinkedList() { SAFE_DELETE(head_); }

public:
    MyLinkedList& operator=(const MyLinkedList& list) {
        std::cout << "왼값 복사 연산" << std::endl;
        Node* node = list.head_;

        while (node) {
            push_back(node->data);
            node = node->next;
        }

        return *this;
    }

    MyLinkedList& operator=(MyLinkedList&& list) noexcept {
        std::cout << "오른값 이동 연산" << std::endl;
        head_ = list.head_;
        tail_ = list.tail_;
        current_ = list.current_;
        size_ = list.size_;

        list.head_ = nullptr;
        list.tail_ = nullptr;
        list.current_ = nullptr;
        list.size_ = 0;

        return *this;
    }

public:
    void push_front(const T& data) {
        Node* newNode = new Node(data);

        if (!head_) {
            head_ = tail_ = newNode;
        }
        else {
            newNode->next = head_;
            newNode->prev = nullptr;
            head_->prev = newNode;
            head_ = newNode;
        }
        ++size_;
    }

    void push_front(T&& data) noexcept {
        Node* newNode = new Node(std::move(data));

        if (!head_) {
            head_ = tail_ = newNode;
        }
        else {
            newNode->next = head_;
            newNode->prev = nullptr;
            head_->prev = newNode;
            head_ = newNode;
        }
        ++size_;
    }

    void push_back(const T& data) {
        Node* newNode = new Node(data);

        if (!tail_) {
            head_ = tail_ = newNode;
        }
        else {
            newNode->next = nullptr;
            newNode->prev = tail_;
            tail_->next = newNode;
            tail_ = newNode;
        }
        ++size_;
    }

    void push_back(T&& data) noexcept {
        Node* newNode = new Node(std::move(data));

        if (!tail_) {
            head_ = tail_ = newNode;
        }
        else {
            newNode->next = nullptr;
            newNode->prev = tail_;
            tail_->next = newNode;
            tail_ = newNode;
        }
        ++size_;
    }

    void pop_front() {
        Node* temp = head_;

        if (head_ != tail_) {
            head_->next->prev = nullptr;
            head_ = head_->next;
        }
        else {
            head_ = tail_ = nullptr;
        }

        temp->prev = nullptr;
        temp->next = nullptr;
        SAFE_DELETE(temp);
        --size_;
    }

    void pop_back() {
        //Node* t = this->find(size_ - 2);
        Node* temp = tail_;

        if (tail_ != head_) {
            tail_->prev->next = nullptr;
            tail_ = tail_->prev;
        }
        else {
            head_ = tail_ = nullptr;
        }

        temp->prev = nullptr;
        temp->next = nullptr;
        SAFE_DELETE(temp);
        --size_;
    }

    void insert(const T& d)
    {
        if (!current_ || !current_->next) {
            push_back(std::forward<T>(d));
        }
        else {
            Node* temp = new Node(d);

            temp->next = current_->next;
            temp->prev = current_;
            current_->next->prev = temp;
            current_->next = temp;
            ++size_;
        }
    }

    void remove(const T& d)
    {
        Node* target = this->find(d);

        if (!target) return;

        if (!target->prev) {
            pop_front();
        }
        else if (!target->next) {
            pop_back();
        }
        else {
            target->prev->next = target->next;
            target->next->prev = target->prev;

            target->prev = nullptr;
            target->next = nullptr;

            SAFE_DELETE(target);
            --size_;
        }
    }

    /*
    // 선형탐색
    bool search(const T& key) {
        Node* h = head_;
        int idx = 0;

        while (h) {
            if (h->data == key) return idx;
            ++idx;
            h = h->next;
        }
        return -1;
    }

    int searchHelper(Node* node, const T& key) {
        if (!node) return -1;
        if (node->data == key) return 0;

        int idx = searchHelper(node->next, key);

        if (idx == -1) return -1;
        return idx + 1;
    }

    // 선형탐색 : 재귀
    int recursiveSearch(const T& key) {
        return searchHelper(head_, key);
    }
    

    void reverse() {
        Node* current = head_;
        Node* prev = nullptr;
        Node* node = nullptr;

        while (current) {
            node = current->next;
            current->next = prev;

            prev = current;
            current = node;
        }
        head_ = prev;
    }
    */

    T& front() {
        if (!head_) abort();
        return head_->data;
    }

    T& back() {
        if (!head_) abort();
        return tail_->data;
    }

    inline const int& size() const { return size_; }

private:
    Node* find(const int& data) {
        Node* n = head_;

        while (n && n->data != data)
            n = n->next;

        return n;
    }

private:
	Node* head_;
	Node* tail_;
    Node* current_;

	int size_;
};