#pragma once
#include <initializer_list>

template<typename T>
struct Node {
    T val;
    Node<T>* next;
};

template<typename T>
class List {
public:
    List() {}

    List(std::initializer_list<T> l) {
        for (const auto &el : l)
            push_back(el);
    }

    ~List() {
        while (head) {
            Node<T> *toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }

    class iterator {
    public:
        iterator() : idx(nullptr) {}
        iterator(Node<T> *idx) : idx(idx) {}
        
        iterator& operator++() {
            if (idx)
                idx = idx->next;
            else 
                idx = nullptr;
            return *this;
        }

        bool operator==(const iterator& it) const {
            return idx == it.idx;
        }

        bool operator!=(const iterator& it) const {
            return idx != it.idx;
        }

        T& operator*() {
            return idx->val;
        }
    private:
        Node<T> *idx;
    };

    iterator begin() const {
        return iterator(head);
    }

    iterator end() const {
        return iterator();
    }

    void push_front(T val) {
        Node<T>* newNode = new Node<T>{val, nullptr};
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(T val) {
        Node<T>* newNode = new Node<T>{val, nullptr};
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
};