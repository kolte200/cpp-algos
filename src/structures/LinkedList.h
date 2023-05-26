#pragma once

#include "common.h"


template <typename T> class LinkedListNode {
    public:
        T data;
        LinkedListNode<T>* next;

        LinkedListNode() : next(NULL) {}
        LinkedListNode(T data) : data(data), next(NULL) {}
};


template <class T> class LinkedList {
    private:
        LinkedListNode<T> head;
        int len;

    public:
        LinkedList() : head(), tail(), len(0) {}

        LinkedListNode* add(T data) {
            LinkedListNode<T>* node = new LinkedListNode<T>(data);
            node->next = head.next;
            head.next = node;
            this->len++;
            return node;
        }

        void remove(LinkedListNode* node) {
            node->prev->next = node->next;
            delete node;
            this->len--;
        }

        inline int length() {
            return this->len;
        }
};
