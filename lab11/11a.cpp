#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable{
    private:
        int table[TABLE_SIZE];
    public:
        HashTable(){
            for(int i = 0; i< TABLE_SIZE; i++){
                table[i] = EMPTY;
            }
        }
        int hashfunction(int key){
            return key % TABLE_SIZE;
        }

    void insert(int key){
        int index = hashfunction(key);
        int start = index;
        int i=0;

        do{
            if (table[index] == EMPTY || table[index] == DELETED){
                table[index] = key;
                cout << "Inserted" << key << "at index" << index << endl;
                return;
            }
            index = (index + i) % TABLE_SIZE;
        }while (index!= start);
        cout << "Hash Table is full.Cant insert" << key << endl;
    }

    void remove(int key){
        int index = hashfunction(key);
        int start = index;
        int i=0;

        do{
            if (table[index] == key){
                table[index] = DELETED;
                cout << "Deleted" << key << "from index" << index << endl;
                return;
            }
            index = (index + i) % TABLE_SIZE;
        }while (table[index]!= EMPTY && index!= start);
        cout << "Key" << key << "not found in hash table." << endl;
    }

    void search(int key){
        int index = hashfunction(key);
        int start = index;
        int i=0;

        do{
            if (table[index] == key){
                cout << "Key" << key << "found at index" << index << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }while (table[index]!= EMPTY && index!= start);
        cout << "Key" << key << "not found in hash table." << endl;
    }

    void display(){
        cout << "\nHashTable:\n";
        for(int i = 0; i< TABLE_SIZE; i++){
            if (table[i] == EMPTY){
                cout << i << ":EMPTY\n";
            } else if (table[i] == DELETED){
                cout << i << ":DELETED\n";
            } else {
                cout << i << ":" << table[i] << endl;
            }
        }
    }
};

int main(){
    HashTable ht;
    int choice, key;

    do{
        cout << "HASH TABLE MENU\n";
        cout << "1.INSERT:\n";
        cout << "2.REMOVE:\n";
        cout << "3.SEARCH:\n";
        cout << "4.DISPLAY:\n";
        cout << "5.EXIT\n";
        cout << "Enter the choice:";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter key to insert";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to remove";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting...";
            default:
                printf("Invalid choice! Try again.\n");
        }
    }while (choice!= 5);
    return 0;
}