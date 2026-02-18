#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1; // new node initially added at leaf
    }
};

class AVLTree {
private:

    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x; // new root
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y; // new root
    }

public:
    Node* insert(Node* node, int key) {

        // 1️⃣ Perform normal BST insertion
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // duplicate keys not allowed

        // 2️⃣ Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 3️⃣ Get balance factor
        int balance = getBalance(node);

        // 4️⃣ Balance the tree

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* temp){
            if(temp->left!=nullptr){
                inorder(temp->left);
            }

            cout <<temp->key<<" ";

            if(temp->right!=nullptr){
                inorder(temp->right);
            }

            return ;      
    }
};

int main() {
    AVLTree tree;
    Node* root = nullptr;

    root = tree.insert(root, 40);
    root = tree.insert(root, 20);
    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 10);
    root = tree.insert(root, 60);
    root = tree.insert(root, 5);
    root = tree.insert(root, 25);
    root = tree.insert(root, 35);
    root = tree.insert(root, 27);



    cout << "Inorder traversal of AVL tree:\n";
    tree.inorder(root);

    return 0;
}
