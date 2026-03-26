#include <iostream>
#include <queue>
#include <cmath>
using namespace std;


class node{
    public:

    int value;
    int height=1;
    node* left=nullptr;
    node* right=nullptr;

    node(int value){
        this->value=value;
    };
};


class avltree {

    public:

    node* root=nullptr;

    int getheight(node* n){
        if(n == nullptr) return 0;  // ✅ safe null check
        return n->height;
    };

    node* rotateright(node* y){
        node* x = y->left;
        node* t = x->right;

        x->right=y;
        y->left=t;

        // Update heights/////////////////////
        y->height=1 +max(getheight(y->left),getheight(y->right)); 
        x->height=1 +max( getheight(x->left),getheight(x->right));   

        return x;
    }


    node* rotateleft(node* x){
        node* y = x->right;
        node* t = y->left;
        
        y->left = x;   //////////////////
        x->right = t;  //////////////////
        
        // Update heights/////////////////////
        x->height=1 +max(getheight(x->left),getheight(x->right)); 
        y->height=1 +max( getheight(y->left),getheight(y->right));   

        return y;
    }

    int balance(node* temp){
        if(temp == nullptr) return 0; ///////////////
        return (getheight(temp->left) - getheight(temp->right)); 
    };

    node* minnode(node* temp){
        while(temp->left != nullptr){
            temp = temp->left;
        };
        return temp;
    };


    node* deletenode(node* currentnode,int key){

        if(currentnode == nullptr){
            return nullptr; // node not found, nothing to delete
        }

        // use to drive the direction
        if(key < currentnode->value){
                currentnode->left = deletenode(currentnode->left, key);
        }else if(key > currentnode->value){
                currentnode->right = deletenode(currentnode->right, key);
        }else{
            // node found

            // Case 1: no child
            if(currentnode->left == nullptr && currentnode->right == nullptr){
                delete currentnode;
                return nullptr;
            }
            // Case 2: one child
            else if(currentnode->left == nullptr){
                node* temp = currentnode->right;
                delete currentnode;
                return temp;
            }else if(currentnode->right == nullptr){
                node* temp = currentnode->left;
                delete currentnode;
                return temp;
            }
            // Case 3: two children - get inorder successor (smallest in right subtree)
            else{
                node* temp = minnode(currentnode->right);
                currentnode->value = temp->value;
                currentnode->right = deletenode(currentnode->right, temp->value);
            }
        }

        // Update heights/////////////////////
        currentnode->height = 1 + max(getheight(currentnode->left),getheight(currentnode->right));
        int balacingfactor = balance(currentnode);
        
        //left
        if(balacingfactor >1 && balance(currentnode->left) >= 0){
            return rotateright(currentnode); /////////////
        }
        //left-right
        if(balacingfactor >1 && balance(currentnode->left) < 0){
            currentnode->left = rotateleft(currentnode->left); ////////////////
            return rotateright(currentnode);
        }
        //right
        if(balacingfactor < -1 && balance(currentnode->right) <=0){
            return rotateleft(currentnode);
        }
        //right-left
        if(balacingfactor < -1 && balance(currentnode->right) > 0){
            currentnode->right = rotateright(currentnode->right);
            return rotateleft(currentnode);
        }

        return currentnode;

    };

    void deletenode(int num) {
        root = deletenode(root,num);
    };


    node* insert(node* currentnode,int key){

        if(currentnode == nullptr){
            return new node(key);
        }
        
        if(key < currentnode->value){
            currentnode->left = insert(currentnode->left,key);///////
        }else if(key > currentnode->value){
            currentnode ->right = insert(currentnode->right,key);
        }else{
            return currentnode;////////
        }

        currentnode->height = 1 + max(getheight(currentnode->left),getheight(currentnode->right));//////////////
        int balancingfactor=balance(currentnode);

        //left
        if(balancingfactor > 1 && key < currentnode->left->value){
            return rotateright(currentnode); /////////////
        }
        //right
        if(balancingfactor < -1 && key > currentnode->right->value/**/ ){
            return rotateleft(currentnode);
        }
        //right-left
        if(balancingfactor < -1 && key </*>*/ currentnode->right->value ){
            currentnode->right = rotateright(currentnode->right);
            return rotateleft(currentnode);
        }
        //left-right
        if(balancingfactor > 1 && key >/*<*/ currentnode->left->value){
            currentnode->left = rotateleft(currentnode->left); ////////////////
            return rotateright(currentnode);
        }

        return currentnode;//////

    }

    void insert(int num) {
        root = insert(root,num);
    };

    void inorder(node* temp){
        if(temp->left!=nullptr){
            inorder(temp->left);
        }

        cout <<temp->value<<" ";

        if(temp->right!=nullptr){
            inorder(temp->right);
        }

        return ;
    };


    // find the smallest node in a subtree (used during delete)
    int height(node* root) {
        if (!root) return 0;//////////////////
        return 1 + max(height(root->left), height(root->right));
    }

    void printLevel(vector<node*> nodes, int level, int maxLevel) {
        if (nodes.empty()) return;

        int floor = maxLevel - level;
        int edgeLines = pow(2, max(floor - 1, 0));
        int firstSpaces = pow(2, floor) - 1;
        int betweenSpaces = pow(2, floor + 1) - 1;

        // Print node values
        for (int i = 0; i < firstSpaces; i++) cout << " ";

        vector<node*> newNodes;
        for (node* n : nodes) {
            if (n) {
                cout << n->value;
                newNodes.push_back(n->left);
                newNodes.push_back(n->right);
            } else {
                cout << " ";
                newNodes.push_back(nullptr);
                newNodes.push_back(nullptr);
            }

            for (int i = 0; i < betweenSpaces; i++) cout << " ";
        }
        cout << "\n";

        // Print edges (/ and \)
        for (int i = 1; i <= edgeLines; i++) {
            for (int j = 0; j < nodes.size(); j++) {
                for (int k = 0; k < firstSpaces - i; k++) cout << " ";

                if (nodes[j] == nullptr) {
                    for (int k = 0; k < edgeLines * 2 + i + 1; k++) cout << " ";
                    continue;
                }

                if (nodes[j]->left) cout << "/";
                else cout << " ";

                for (int k = 0; k < i * 2 - 1; k++) cout << " ";

                if (nodes[j]->right) cout << "\\";
                else cout << " ";

                for (int k = 0; k < edgeLines * 2 - i; k++) cout << " ";
            }
            cout << "\n";
        }

        printLevel(newNodes, level + 1, maxLevel);
    }

    void printPrettyTree(node* root) {
        int h = height(root);
        vector<node*> nodes = {root};
        printLevel(nodes, 1, h);
    }

};


// ─── Helper to print the menu ───────────────────────────────────────────────
void printMenu(){
    cout << "\n======== AVL Tree Menu ========\n";
    cout << " 1. Insert\n";
    cout << " 2. Delete\n";
    cout << " 3. Inorder Traversal\n";
    cout << " 4. Print Tree\n";
    cout << " 5. Exit\n";
    cout << "===============================\n";
    cout << "Enter your choice: ";
}


int main(){

    avltree tree;
    int choice, value;

    do {
        printMenu();
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                cout << value << " inserted.\n";
                break;

            case 2:
                if(tree.root == nullptr){
                    cout << "Tree is empty.\n";
                }else{
                    cout << "Enter value to delete: ";
                    cin >> value;
                    tree.deletenode(value);
                    cout << value << " deleted (if it existed).\n";
                }
                break;

            case 3:
                if(tree.root == nullptr){
                    cout << "Tree is empty.\n";
                }else{
                    cout << "Inorder: ";
                    tree.inorder(tree.root);
                    cout << endl;
                }
                break;

            case 4:
                if(tree.root == nullptr){
                    cout << "Tree is empty.\n";
                }else{
                    cout << "\n";
                    tree.printPrettyTree(tree.root);
                }
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please enter 1-5.\n";
        }

    } while(choice != 5);

    return 0;
};