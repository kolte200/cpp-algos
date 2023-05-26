#pragma once

#include "common.h"


template <typename T> class DoubleLinkedListNode {
    public:
        T data;
        DoubleLinkedListNode<T>* next;
        DoubleLinkedListNode<T>* prev;

        DoubleLinkedListNode() : next(NULL), prev(NULL) {}
        DoubleLinkedListNode(T data) : data(data), next(NULL), prev(NULL) {}
};


template <class T> class DoubleLinkedList {
    private:
        DoubleLinkedListNode<T> head;
        DoubleLinkedListNode<T> tail;
        int len;

    public:
        DoubleLinkedList() : head(), tail(), len(0) {}

        DoubleLinkedListNode* addFirst(T data) {
            DoubleLinkedListNode<T>* node = new DoubleLinkedListNode<T>(data);
            node->prev = &head;
            node->next = head.next;
            head.next->prev = node;
            head.next = node;
            this->len++;
            return node;
        }

        DoubleLinkedListNode* addLast(T data) {
            DoubleLinkedListNode<T>* node = new DoubleLinkedListNode<T>(data);
            node->next = &tail;
            node->prev = tail.prev;
            tail.prev->next = node;
            tail.prev = node;
            this->len++;
            return node;
        }

        void remove(DoubleLinkedListNode* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            this->len--;
        }

        inline int length() {
            return this->len;
        }
};
