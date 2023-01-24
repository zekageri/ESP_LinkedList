#ifndef Linked_h
#define Linked_h

#include <Arduino.h>

template <typename T>
class ESP_LinkedList {
   private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int count;

   public:
    ESP_LinkedList() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    ~ESP_LinkedList() {
        clear();
    }

    void add(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void add(int index, T data) {
        if (index < 0 || index > count) {
            return;
        }

        Node* newNode = new Node();
        newNode->data = data;

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        count++;
    }

    void remove(int index) {
        if (index < 0 || index >= count) {
            return;
        }
        Node* current = head;
        if (index == 0) {
            head = head->next;
            delete current;
        } else {
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        count--;
    }

    void clear() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
        count = 0;
    }

    int size() {
        return count;
    }

    T get(int index) {
        if (index < 0 || index >= count) {
            return T();
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    T operator[](int index) {
        return get(index);
    }

    bool contains(T data) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int indexOf(T data) {
        Node* current = head;
        int index =
            0;
        for (; current != NULL; current = current->next, ++index) {
            if (current->data == data) {
                return index;
            }
        }
        return -1;
    }

    void reverse() {
        if (head == NULL || head->next == NULL) {
            return;
        }
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        tail = head;
        head = prev;
    }

    void sort() {
        if (head == NULL || head->next == NULL) {
            return;
        }
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            for (Node* i = head; i != current; i = i->next) {
                if (i->data > current->data) {
                    T temp = i->data;
                    i->data = current->data;
                    current->data = temp;
                }
            }
            current = next;
        }
    }

    void pop_back() {
        if (count == 0) {
            return;
        }
        remove(count - 1);
    }
};

#endif