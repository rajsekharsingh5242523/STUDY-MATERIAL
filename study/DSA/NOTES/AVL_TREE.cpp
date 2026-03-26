#include <iostream>

using namespace std;

class Node {
    public:
        int value; 
        Node* left;
        Node* right;
        int height;

        Node(int val) {
            value = val;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
};


class AVLTree {
    
    public:

        int getheight(Node *temp){
            if(temp==nullptr) return 0;//////////////////
            return temp->height;////////////////////////
        }


        int balanceCal(Node *temp){
            if(temp == nullptr) return 0; ///////////////
            return getheight(temp->left) - getheight(temp->right); 
        }


        Node * rotateleft(Node *x){
            Node *y= x->right;
            Node *t= y->left;

            y->left=x;
            x->right=t;
            // Update heights/////////////////////

            x->height = 1 + max(getheight(x->left), getheight(x->right));
            y->height = 1 + max(getheight(y->left), getheight(y->right));

            return y;
        }


        Node * rotateright(Node *y){
            Node *x=y->left;
            Node *t=x->right;

            x->right=y;
            y->left=t;

            // Update heights/////////////////////
            y->height = 1 + max(getheight(y->left), getheight(y->right));
            x->height = 1 + max(getheight(x->left), getheight(x->right));

            return x;
        }


        Node* insert(Node *currtemp,int key){
            
            if(currtemp==nullptr){
                return new Node(key);
            }
            
            if(key < currtemp->value){
                currtemp->left = insert(currtemp->left,key);///////
            }else if(key > currtemp->value){
                currtemp->right = insert(currtemp->right,key);
            }else{
                return currtemp;////////
            }

            currtemp->height = 1 + max(getheight(currtemp->left),getheight(currtemp->right));//////////////
            int balancingfactor = balanceCal(currtemp);
            
            //right
            if(balancingfactor < -1 &&  key > currtemp->right->value/**/){
                return rotateleft(currtemp);
            }
            //left
            if(balancingfactor > 1 && key < currtemp->left->value){
                return rotateright(currtemp); /////////////
            }
            //right-left
            if(balancingfactor < -1 && key </*>*/ currtemp->right->value){
                currtemp->right = rotateright(currtemp->right);
                return rotateleft(currtemp);
            }
            //left-righ
            if(balancingfactor >1 && key >/*<*/ currtemp->left->value){
                currtemp->left = rotateleft(currtemp->left); ////////////////
                return rotateright(currtemp);
            }
        
            return currtemp;//////
        }


        // find the smallest node in a subtree (used during delete)
        Node* minNode(Node* temp){
            while(temp->left != nullptr){
                temp = temp->left;
            }
            return temp;
        }


        Node* deleteNode(Node* currtemp, int key){

            if(currtemp == nullptr) return nullptr; // node not found, nothing to delete

            if(key < currtemp->value){
                currtemp->left = deleteNode(currtemp->left, key);
            }else if(key > currtemp->value){
                currtemp->right = deleteNode(currtemp->right, key);
            }else{
                // node found
                if(currtemp->left == nullptr || currtemp->right == nullptr){
                    // one child or no child
                    Node* temp = currtemp->left ? currtemp->left : currtemp->right;
                    if(temp == nullptr){
                        // no child case
                        temp = currtemp;
                        currtemp = nullptr;
                    }else{
                        // one child case - copy child into current
                        *currtemp = *temp;
                    }
                    delete temp;
                }else{
                    // two children - get inorder successor (smallest in right subtree)
                    Node* temp = minNode(currtemp->right);
                    currtemp->value = temp->value;
                    currtemp->right = deleteNode(currtemp->right, temp->value);
                }
            }

            if(currtemp == nullptr) return nullptr; // tree had only one node

            // Update heights/////////////////////
            currtemp->height = 1 + max(getheight(currtemp->left), getheight(currtemp->right));
            int balancingfactor = balanceCal(currtemp);

            //left
            if(balancingfactor > 1 && balanceCal(currtemp->left) >= 0){
                return rotateright(currtemp); /////////////
            }
            //left-right
            if(balancingfactor > 1 && balanceCal(currtemp->left) < 0){
                currtemp->left = rotateleft(currtemp->left); ////////////////
                return rotateright(currtemp);
            }
            //right
            if(balancingfactor < -1 && balanceCal(currtemp->right) <= 0){
                return rotateleft(currtemp);
            }
            //right-left
            if(balancingfactor < -1 && balanceCal(currtemp->right) > 0){
                currtemp->right = rotateright(currtemp->right);
                return rotateleft(currtemp);
            }

            return currtemp;//////
        }


        void inorder(Node* temp){
            if(temp->left!=nullptr){
                inorder(temp->left);
            }

            cout <<temp->value<<" ";

            if(temp->right!=nullptr){
                inorder(temp->right);
            }

            return ;
        }

};


// ─── Helper to print the menu ───────────────────────────────────────────────
void printMenu(){
    cout << "\n======== AVL Tree Menu ========\n";
    cout << " 1. Insert\n";
    cout << " 2. Delete\n";
    cout << " 3. Inorder Traversal\n";
    cout << " 4. Exit\n";
    cout << "===============================\n";
    cout << "Enter your choice: ";
}


int main() {

    AVLTree tree;
    Node* root = nullptr;
    int choice, value;

    do {
        printMenu();
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = tree.insert(root, value);
                cout << value << " inserted.\n";
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = tree.deleteNode(root, value);
                cout << value << " deleted (if it existed).\n";
                break;

            case 3:
                if(root == nullptr){
                    cout << "Tree is empty.\n";
                }else{
                    cout << "Inorder: ";
                    tree.inorder(root);
                    cout << endl;
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please enter 1-4.\n";
        }

    } while(choice != 4);

    return 0;
}