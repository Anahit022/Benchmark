#include <iostream>
#include "D:\Security\basic_algorithm\Benchmark\Benchmark\list.h"


MyList::MyList() : head(nullptr), tail(nullptr), size(0) {}

MyList::~MyList() {
        clear();
    }

MyList::MyList(const MyList& other) : MyList() {
        *this = other;
    }

MyList& MyList::operator=(const MyList& other) {
        if (this == &other) {
            return *this;
        }

        clear();

        ListNode* current = other.head;
        while (current) {
            push_back(current->value);
            current = current->next;
        }

        return *this;
    }

    void MyList::clear() {
        ListNode* current = head;
        while (current) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void MyList::swap(MyList& other) {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(size, other.size);
    }

    void MyList::assign(size_t count, int value) {
        clear();

        for (size_t i = 0; i < count; i++) {
            push_back(value);
        }
    }

    void MyList::insert(size_t pos, int value) {
        if (pos > size) {
            throw std::out_of_range("Invalid position");
        }

        if (pos == 0) {
            push_front(value);
            return;
        }

        if (pos == size) {
            push_back(value);
            return;
        }

        ListNode* current = getNodeAt(pos);
        ListNode* newNode = new ListNode{ value, current, current->prev };
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }

    void MyList::resize(size_t newSize) {
        if (newSize == size) {
            return;
        }

        if (newSize < size) {
            while (size > newSize) {
                pop_back();
            }
        }
        else {
            while (size < newSize) {
                push_back(0);
            }
        }
    }

    void MyList::erase(size_t pos) {
        if (pos >= size) {
            throw std::out_of_range("Invalid position");
        }

        if (pos == 0) {
            pop_front();
            return;
        }

        if (pos == size - 1) {
            pop_back();
            return;
        }

        ListNode* current = getNodeAt(pos);
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }

    void MyList::push_front(int value) {
        ListNode* newNode = new ListNode{ value, head, nullptr };
        if (head) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
        size++;
    }

    void MyList::push_back(int value) {
        ListNode* newNode = new ListNode{ value, nullptr, tail };
        if (tail) {
            tail->next = newNode;
        }
        else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    void MyList::pop_front() {
        if (!head) {
            throw std::length_error("List is empty");
        }

        ListNode* oldHead = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete oldHead;
        size--;
    }

    void MyList::pop_back() {
        if (!tail) {
            throw std::length_error("List is empty");
        }

        ListNode* oldTail = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete oldTail;
        size--;
    }

    int MyList::find(int value) {
        ListNode* current = head;
        size_t pos = 0;
        while (current) {
            if (current->value == value) {
                return pos;
            }
            current = current->next;
            pos++;
        }
        return -1;
    }
    ListNode* MyList::getNodeAt(size_t pos) {
        ListNode* current = head;
        for (size_t i = 0; i < pos; i++) {
            current = current->next;
        }
        return current;
    }


/*int main() {
    MyList list1;
    MyList list2;
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);

    std::cout << "list1: ";
    ListNode* current = list1.head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    list2 = list1;

    list2.insert(1, 15);
    list2.push_back(40);

    std::cout << "list2: ";
    current = list2.head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    int index = list2.find(15);
    if (index != -1) {
        std::cout << "Element 15 found at index " << index << " in list2" << std::endl;
    }
    else {
        std::cout << "Element 15 not found in list2" << std::endl;
    }

    list2.resize(4);

    std::cout << "list2 after resizing: ";
    current = list2.head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    list1.clear();
    list2.clear();

    return 0;
}*/