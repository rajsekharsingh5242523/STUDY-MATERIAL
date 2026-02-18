#include <iostream>
#include <algorithm>//

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
            height =1;
        }
};


class AVLTree {
    
    public:

        int getheight(Node *temp){
            if(temp==nullptr) return 0;//
            return temp->height;//

        }


        int balanceCal(Node *temp){
            if(temp == nullptr) return 0; //
            return getheight(temp->left) - getheight(temp->right); //
        }


        Node * rotateleft(Node *x){
            Node *y= x->right;
            Node *t= y->left;

            y->left=x;
            x->right=t;

            x->height = 1 + max(getheight(x->left), getheight(x->right));
            y->height = 1 + max(getheight(y->left), getheight(y->right));

            return y;
        }


        Node * rotateright(Node *y){
            Node *x=y->left;
            Node *t=x->right;

            x->right=y;
            y->left=t;

            // Update heights
            y->height = 1 + max(getheight(y->left), getheight(y->right));
            x->height = 1 + max(getheight(x->left), getheight(x->right));

            return x;
        }


        Node* insert(Node *currtemp,int key){

            Node *newnode =new Node(key);
            
            if(currtemp==nullptr){
                return newnode;
            }
            
            if(key < currtemp->value){
                currtemp->left = insert(currtemp->left,key);//
            }else if(key > currtemp->value){
                currtemp->right = insert(currtemp->right,key);
            }else{
                return currtemp;//
            }

            currtemp->height = 1 + max(getheight(currtemp->left),getheight(currtemp->right));//


            int balancingfactor = balanceCal(currtemp);

            //right
            if(balancingfactor < -1 &&  key > currtemp->right->value/**/){
                return rotateleft(currtemp);
            }
            //left
            if(balancingfactor > 1 && key < currtemp->left->value){
                return rotateright(currtemp); //
            }
            //right-left
            if(balancingfactor < -1 && key < currtemp->right->value){
                currtemp->right = rotateright(currtemp->right);
                return rotateleft(currtemp);
            }
            //left-right
            if(balancingfactor >1 && key > currtemp->left->value){
                currtemp->left = rotateleft(currtemp->left); //
                return rotateright(currtemp);
            }
        
            return currtemp;
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


    tree.inorder(root);

    return 0;
}