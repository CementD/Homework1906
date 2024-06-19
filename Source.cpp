#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(int data) {
        Node* newNode = nullptr;
        try {
            newNode = new Node(data);
        }
        catch (...) {
            cout << "Error! Memory allocation failed!" << endl;
            throw - 1;
        }

        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeLast() {
        if (tail == nullptr) {
            cout << "Error! Operation cannot be performed on an empty list!" << endl;
            throw - 1;
        }

        Node* temp = tail;
        if (tail->prev != nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            head = tail = nullptr;
        }
        delete temp;
    }

    void printList() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    try {
        DoublyLinkedList list;
        list.append(10);
        list.append(20);
        list.printList();
        list.removeLast();
        list.printList();
        list.removeLast();
        list.printList();
        list.removeLast();
    }
    catch (...) {
        cerr << "Error!" << endl;
    }

    return 0;
}
