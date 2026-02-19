#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node *left=nullptr;
        Node *right=nullptr;

        Node(int num){
            value=num;
        }
};

class BinarySearchTree{

    private:
        Node * StorageQueue[20];
        int head=-1;
        int rear=-1;
        int len=0;

    public:

        Node *root=nullptr;
        
        void insert(int user){
            if(root == nullptr){
                root=new Node(user);
            }
            Node *temp=root;
            while (true){

                if(temp->value==user) return;
                Node *newnode=new Node(user);
                if(user<(temp->value)){
                    if(temp->left==nullptr){
                        temp->left=newnode;
                        return;
                    };
                    temp=temp->left;
                }else if(user>(temp->value)){
                    if(temp->right==nullptr){
                        temp->right=newnode;
                        return;
                    };
                    temp=temp->right;
                }
            }

            return;
        }
        

        void push(Node *value){
            if(head==-1){
                head=0;
            }
            rear++;
            StorageQueue[rear]=value;
            len++;
            return;
        }

        void pop(){
            cout <<StorageQueue[head]->value<<" ";
            if(len==0) return;
            head++;
            len--;
            return;
        }


        Node *search(int value){
            Node *temp=root;
            while(temp!=nullptr){
                if(value==(temp->value)){
                    return temp;
                }else if(value<(temp->value)){
                    temp=temp->left;
                }else{
                    temp=temp->right;
                }
            }
            return nullptr;
        }



        void BFS(){
            if(root == nullptr) return;
            push(root);
            while(len >0){
                Node *temp=StorageQueue[head];
                pop();
                if(temp->left!=nullptr){
                    push(temp->left);
                }
                if(temp->right!=nullptr){
                    push(temp->right);
                }
            } 
            return;
        }


        void DFSPreOrder(Node *currentNode){
            cout <<currentNode->value<<" ";
            if(currentNode->left!=nullptr){
                DFSPreOrder(currentNode->left);
            }
            if(currentNode->right!=nullptr){
                DFSPreOrder(currentNode->right);
            }

        }


        void DFSPostOrder(Node *currentNode){
            if(currentNode->left!=nullptr){
                DFSPostOrder(currentNode->left);
            }
            if(currentNode->right!=nullptr){
                DFSPostOrder(currentNode->right);
            }
            cout <<currentNode->value<<" ";

        }

        void DFSInOrder(Node *currentNode){
            if(currentNode->left!=nullptr){
                DFSInOrder(currentNode->left);
            }
            cout <<currentNode->value<<" ";
            if(currentNode->right!=nullptr){
                DFSInOrder(currentNode->right);
            }

        }

        int  Successor(Node *main){
            while(main->left!=nullptr){
                main=main->left;
            }
            return main->value;
            
        };

        int  Predecessor(Node *main){

            while(main->right!=nullptr){
                main=main->right;
            }
            return main->value;
        };
        

        Node* RemoveNode(Node *currtemp,int key){

            if(currtemp==nullptr){//think of null root case
                return nullptr;
            }
            //think of key not in the tree
            if(key<currtemp->value){
                currtemp->left = RemoveNode(currtemp->left,key);
            }else if(key > currtemp->value){
                currtemp->right = RemoveNode(currtemp->right,key);
            }else{
                if(currtemp->left == nullptr && currtemp->right == nullptr){
                    delete currtemp;
                    return nullptr;
                }else if(currtemp->left == nullptr && currtemp->right != nullptr){
                    Node *temp=currtemp->right;
                    delete currtemp;
                    return temp;
                }else if(currtemp->right ==nullptr && currtemp->left != nullptr){
                    Node *temp=currtemp->left;
                    delete currtemp;
                    return temp;
                }else{
                    int minValue = Successor(currtemp->right);
                    currtemp->value = minValue;
                    currtemp->right = RemoveNode(currtemp->right,minValue);
                }
            }

            return currtemp;

        }


        void RemoveNode(int delvalue){
            root = RemoveNode(root,delvalue);
        };






















};



int main(){

    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(40);
    myBST->insert(50);
    myBST->insert(45);
    myBST->insert(55);

    cout << "Breadth First Search:\n";
    myBST->BFS();
    cout <<endl;

    myBST->RemoveNode(50);
    


    cout << "Breadth First Search:\n";
    myBST->BFS();
    cout <<endl;

    cout << "DFS PreOrder:\n";
    myBST->DFSPreOrder(myBST->root);
    cout <<endl;

    cout << "DFS PostOrder:\n";
    myBST->DFSPostOrder(myBST->root);
    cout <<endl;

    cout << "DFS InOrder:\n";
    myBST->DFSInOrder(myBST->root);

    return 0;
}