//Implementing Tree ADT using Binary Search Tree
#include <iostream>
using namespace std;

// Node class for BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;
    Node* insertHelper(Node* root, int value);
    void preorderHelper(Node* root);
    void inorderHelper(Node* root);
    void postorderHelper(Node* root);
    bool searchHelper(Node* root, int value);

public:
    BST() {
        root = nullptr;
    }

    void insert(int value);
    void preorder();
    void inorder();
    void postorder();
    bool search(int value);
};
int main() {
    BST bst;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                bst.preorder();
                break;
            case 3:
                bst.inorder();
                break;
            case 4:
                bst.postorder();
                break;
            case 5:
                cout << "Enter the value to search: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << "Element " << value << " found in the tree.\n";
                } else {
                    cout << "Element " << value << " not found in the tree.\n";
                }
                break;
            case 6:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}



Node* BST::insertHelper(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insertHelper(root->left, value);
    } else if (value > root->data) {
        root->right = insertHelper(root->right, value);
    }
    return root;
}

void BST::insert(int value) {
    root = insertHelper(root, value);
    cout << "Element " << value << " inserted successfully.\n";
}

// Preorder traversal
void BST::preorderHelper(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderHelper(root->left);
    preorderHelper(root->right);
}

void BST::preorder() {
    cout << "Preorder Traversal: ";
    preorderHelper(root);
    cout << endl;
}

// Inorder traversal
void BST::inorderHelper(Node* root) {
    if (root == nullptr) return;
    inorderHelper(root->left);
    cout << root->data << " ";
    inorderHelper(root->right);
}

void BST::inorder() {
    cout << "Inorder Traversal: ";
    inorderHelper(root);
    cout << endl;
}

// Postorder traversal
void BST::postorderHelper(Node* root) {
    if (root == nullptr) return;
    postorderHelper(root->left);
    postorderHelper(root->right);
    cout << root->data << " ";
}

void BST::postorder() {
    cout << "Postorder Traversal: ";
    postorderHelper(root);
    cout << endl;
}

// Search for a value in the BST
bool BST::searchHelper(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data) return searchHelper(root->left, value);
    return searchHelper(root->right, value);
}

bool BST::search(int value) {
    return searchHelper(root, value);
}