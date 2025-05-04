#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class HashTable {
private:
    static const int SIZE = 10;
    Node* table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        // Insert at beginning for simplicity
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Inserted " << key << " at index " << index << endl;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Deleted " << key << " from index " << index << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Key " << key << " not found!" << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->data == key) {
                cout << "Found " << key << " at index " << index << endl;
                return;
            }
            current = current->next;
        }

        cout << "Key " << key << " not found!" << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable hashTable;
    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                hashTable.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                hashTable.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                hashTable.search(key);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

        hashTable.display();

    } while (choice != 4);

    return 0;
}
