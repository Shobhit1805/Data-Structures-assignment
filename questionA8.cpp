#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char name[100]; 
    Node* next;
};
class LinkedList {
private:
    Node* head;

public:    LinkedList() {
        head = nullptr;
    }
    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }
    void addAtBeg(const char* name) {
        Node* newNode = new Node();
        strcpy(newNode->name, name);
        newNode->next = head;
        head = newNode;
    }
    void append(const char* name) {
        Node* newNode = new Node();
        strcpy(newNode->name, name);
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void addAtPOS(const char* name, int pos) {
        if (pos < 1 || pos > getLength() + 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 1) {
            addAtBeg(name);
            return;
        }

        Node* newNode = new Node();
        strcpy(newNode->name, name);

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void displayMORE() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Node Address: " << temp << ", Name: " << temp->name << ", Next Address: " << temp->next << endl;
            temp = temp->next;
        }
    }
    void removeFirst() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void removeLast() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }
    void removePOS(int pos) {
        if (pos < 1 || pos > getLength()) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 1) {
            removeFirst();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.addAtBeg("Alice");
    list.addAtBeg("Bob");
    list.addAtBeg("Charlie");
    list.append("David");
    list.append("Eve");
    list.addAtPOS("Zara", 3);

    cout << "Linked List: ";
    list.display();

    cout << "Linked List Details: " << endl;
    list.displayMORE();

    cout << "Length of the list: " << list.getLength() << endl;

    list.removeFirst();
    cout << "After removing the first element: ";
    list.display();

    list.removeLast();
    cout << "After removing the last element: ";
    list.display();

    list.removePOS(2);
    cout << "After removing the element at position 2: ";
    list.display();

    return 0;
}
