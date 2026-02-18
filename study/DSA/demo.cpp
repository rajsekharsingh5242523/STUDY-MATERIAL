#include <iostream>
using namespace std;

class Node {
    private:
        int value; 
        Node* left;
        Node* right;
        int height;

    public:
        Node(int val) {
            value = val;
            left = nullptr;
            right = nullptr;
            height =0;
        }
}


class AVLTree {
    private:
        Node* root=nullptr;

    public:

        int getheight(Node *temp){
            if(temp==nullptr) return 0;
            if(temp->left==nullptr && temp->right==nullptr){
                return 0;
            }
            return 1+max(getheight temp->left,getheight temp->right);
        }


        int balanceit(Node *temp){
            int holder=(temp->left->height)-(temp->right->height);
            return holder;
        }


        void insert(Node *temp,int key){
            Node *newnode =new Node(key);
            if (root==nullptr){
                root=newnode;
                return;
            }
            
            if(temp==nullptr){
                return newnode;
            }
            
            if(key < temp->value){
                temp->left = insert(temp->left,key);
            }else if(key > temp->value){
                temp->right = insert(temp->right,key);
            }

            node->height = getheight(temp);

            int balanceval = balanceit(temp);
            
            
            



        }




}



int main() {
    




    return 0;
}