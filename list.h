#ifndef MYLIST_H
#define MYLIST_H

#include <stdexcept>

struct ListNode {
    int value;
    ListNode* next;
    ListNode* prev;
};

struct MyList {
    ListNode* head;
    ListNode* tail;
    size_t size;

    MyList();
    ~MyList();
    MyList(const MyList& other);
    MyList& operator=(const MyList& other);
    void clear();
    void swap(MyList& other);
    void assign(size_t count, int value);
    void insert(size_t pos, int value);
    void resize(size_t newSize);
    void erase(size_t pos);
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    int find(int value);

private:
    ListNode* getNodeAt(size_t pos);
};

#endif  // MYLIST_H
