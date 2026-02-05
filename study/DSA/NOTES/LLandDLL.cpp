#include  <iostream>

using namespace std;



class Node{  

    public:
        int value;
        Node*next;

        Node(int value){        /* “Anything inside public is accessible from outside, but only functions with the same name as the class are constructors.”A function is a constructor only if:Its name is exactly the same as the class name It has no return type It is inside the class definition*/
            this->value = value;
            next=nullptr;
        }
};



class linkedList{
    private:    //Private members /function  are accessible only inside the same class only the class ma function can acceses it.
        Node *head;
        Node *tail;
        int len =0;

    public:
        linkedList(int value) {
            Node *firstNode=new Node(value);
            head=firstNode;
            tail=firstNode;
            len=1;
        }   

        ~linkedList(){
            
            Node *ptr=head;
            while(ptr){
                head=head->next;
                delete ptr;
                ptr = head;

            }
        };

        void printList(){
            Node *temp=head;
            while(temp !=nullptr){
                if (head == nullptr) {
                    cout << "Empty list\n";
                    return;
                }

                cout << temp->value <<endl;
                temp=temp->next;
            }
            return;
        }


        int getLength(){
            cout<<"length of list:";
            return len;
        }

        void append(int value){
            
            Node *newNode=new Node(value);
            if (len==0){
                tail=newNode;
                head=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
            len ++;
            return;
        };


        void deleteLast(){

            if (head == nullptr) {
                return;
            }

            if (head == tail) {
                //eged case
                delete head;
                head = nullptr;
                tail = nullptr;
                len = 0;
                return;
            }

            Node *temp=head;

            for(int i=0;i<len-2;i++){
                temp=temp->next;
            };

            delete tail;
            tail=temp;
            tail->next=nullptr;
            len--;
        };

        void search(int val) {
            int index = 0;
            Node* temp = head;

            while (temp) {
                if (temp->value == val) {
                    cout << val << " is found in location: " << index << endl;
                    return;
                }
                temp = temp->next;
                index++;
            }

            cout << "Not found in the list" << endl;
        }

        void prepend(int val){
            Node *newNode=new Node(val);

            if (head==nullptr){
                head=tail=newNode;
            }else{
                newNode->next=head;
                head=newNode;
            };
            
            len++;
            return;
        }


        void delectFirst(){

            if (head==nullptr) {
                cout<<"the list is empty no elements to delect "<<endl;
                return;
            }else if (head==tail){
                delete head;
                head = nullptr;
                tail = nullptr;

            }else{
                Node *hold=head;
                head=head->next;
                delete hold;
            }

            len--;
        }


        int getValue (int ind){
            int index=0;
            Node *temp=head;
            if(ind<0 ||ind>=len){
                cout<<"Invalid index"<<endl;
            }else{
                for(int i=0;i<ind;i++){
                    temp=temp->next;
                }
                cout<<temp->value<<endl;
            }
            return 0;
        };


        int set (int ind,int newvalue){
            int index=0;
            Node *temp=head;
            if(ind<0 ||ind>=len){
                cout<<"Invalid index"<<endl;
            }else{
                for(int i=0;i<ind;i++){
                    temp=temp->next;
                }
                temp->value=newvalue;
                return 1;
            };
            return 0;
        };


        void insert(int ind ,int val){
            
            if (ind==0){
                    prepend(val);
                    return;
                };
                

            if (ind==len){
                append(val);
                return;
            };

            Node *newNode=new Node(val);
            Node *temp=head;

            if(ind<0 ||ind>=len){
                cout<<"Invalid index"<<endl;
            }else{
                
                for(int i=0;i<ind-1;i++){
                    temp=temp->next;
                };
                newNode->next=temp->next;
                temp->next=newNode;
            };
            len++;
            return;
        }


        void delectAny(int ind){
            if(ind<0 || ind>len) return;
            if(ind==0) return delectFirst(); // because delectAny and delectFirst have same return type
            if(ind==len-1) return deleteLast();

            Node *hold=head;
            for(int i =0 ;i<ind-1;i++){
                hold=hold->next;
            };
            Node *del=hold->next;
            hold->next=del->next;
            delete del;
            len--;
        };



        void reverse(){

            Node *temp=head;
            head=tail;
            tail=temp;
            Node *before =nullptr;
            for(int i=0;i<len;i++){
                Node *after=temp->next;
                temp->next=before;
                before=temp;
                temp=after;
            }

            return;
        }
    
};




class DNode {
    public :
        int value;
        DNode *next;
        DNode *prev;   
        
        DNode(int value){
            this->value=value;
            next=prev=nullptr;
        };
};

class DLL {
    public :
        DNode *head,*tail;
        int len;

        DLL(){
            head=tail=nullptr;
        };

        void append(int val){
             
            DNode *newnode=new DNode(val);
            
            if(len==0){
                head=tail=newnode;
            }else{
                tail->next=newnode;
                newnode->prev=tail;
                tail=newnode;
            }
            len++;
            cout << "appended the value :"<<val<<endl;
            return;
        };

        void prepend(int val){
            DNode *newnode=new DNode(val);
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            len++;
            cout << "pre pended the value :"<<val<<endl;
            return;
        };

        

        DNode* get(int index){
            if(index<0 || index>len) return NULL;
            DNode *temp ;
            if(index<(len/2)){
                temp=head;
                for(int i=0;i<index;i++){
                    temp=temp->next;
                };
            }else{
                temp=tail;
                for (int i=(len-1);i>index;i--) {   // NOTE:see how from back is done
                    temp=temp->prev;
                };
            }

            return temp;
        };


        int LastDelete (){
            if(head==nullptr){
                cout << "Empty d-ll"<<endl;
                return 0;
            }
            DNode *temp=tail;
            int holder =temp->value;
            if(tail==head){
                tail=head=nullptr;
            }else{
                tail=tail->prev;
                tail->next=nullptr;
            };
            delete temp;
            len--;
            return holder;
        };


        int FrontDelete(){
            if(head==nullptr){
                cout << "Empty d-ll"<<endl;
                return -1;
            }
            DNode *temp=head;
            int holder =temp->value;
            if(tail==head){
                tail=head=nullptr;
            }else{
                head=head->next;
                head->prev=nullptr;
            };
            delete temp;
            len--;
            return holder;
        };


        int Delect(int ind){
            if(ind<0 || ind>=len) return 0;
            if(ind==0){
                return FrontDelete();
            }
            if(ind==len-1){
                return LastDelete();
            }
            DNode *del=get(ind);
            DNode *temp=del->prev;
            DNode *after=del->next;
            temp->next=after;
            after->prev=temp;
            int holder =del->value;
            delete del;
            len--;
            return holder;

        };

        void insert(int ind ,int val){
            if(ind<0 || ind>len) return ;
            if(ind==0){
                return append(val);
            }
            if(ind==len-1){
                return prepend(val);
            }
            DNode *temp=get(ind-1);
            DNode *newnode=new DNode(val);
            DNode *after=temp->next;
            temp->next=newnode;
            after->prev=newnode;
            newnode->next=after;
            newnode->prev=temp;
            cout << "inserting the value : "<<val<<"in the index : "<<ind<<endl;
            len++;
        }

        int getLength(){
            cout<<"length of list: "<<len<<endl;
            return len;
        };


        void printList(){
            DNode *temp=head;
            while(temp!=nullptr){
                cout<<temp->value<<endl;
                temp=temp->next;
            };
            return;
        }


        void search(int val) {
            int index = 0;
            DNode* temp = head;

            while (temp) {
                if (temp->value == val) {
                    cout << val << " is found in location: " << index << endl;
                    return;
                }
                temp = temp->next;
                index++;
            }

            cout << "Not found in the list" << endl;
        }

        ~DLL(){
            DNode *ptr=head;
            while(ptr){
                head=head->next;
                delete ptr;
                ptr = head;

            }
        };


        void reverse(){
            DNode *temp=tail;
            while(temp!=nullptr){
                cout<<temp->value<<endl;
                temp=temp->prev;
            };
            return;            
        }

};




int main() {

    int mainChoice;

    while (true) {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Singly Linked List (LL)\n";
        cout << "2. Doubly Linked List (DLL)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        /* ===================== SINGLY LINKED LIST ===================== */
        if (mainChoice == 1) {

            int choice;
            int value;

            cout << "Enter initial value for linked list: ";
            cin >> value;

            linkedList* mylinkedList = new linkedList(value);

            while (true) {

                cout << "\n1. Append value\n";
                cout << "2. Prepend value\n";
                cout << "3. Delete last node\n";
                cout << "4. Search value\n";
                cout << "5. Print list\n";
                cout << "6. Get length\n";
                cout << "7. Delect First\n";
                cout << "8. Get Value\n";
                cout << "9. Set Value\n";
                cout << "10. Insert Any\n";
                cout << "11. Delect Any\n";
                cout << "12. Reverse\n";
                cout << "13. Exit LL\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {

                    case 1:
                        cout <<"enter the value:";
                        cin >> value;
                        mylinkedList->append(value);
                        break;

                    case 2:
                        cout <<"enter the value:";
                        cin >> value;
                        mylinkedList->prepend(value);
                        break;

                    case 3:
                        mylinkedList->deleteLast();
                        break;

                    case 4:
                        cout <<"enter the value:";
                        cin >> value;
                        mylinkedList->search(value);
                        break;

                    case 5:
                        mylinkedList->printList();
                        break;

                    case 6:
                        cout << mylinkedList->getLength() << endl;
                        break;

                    case 7:
                        mylinkedList->delectFirst();
                        break;

                    case 8:
                        cout <<"enter the value:";
                        cin >> value;
                        mylinkedList->getValue(value);
                        break;

                    case 9: {
                        int ind, change;
                        cout <<"enter the index:";
                        cin >> ind;
                        cout <<"enter the value:";
                        cin>> change;
                        mylinkedList->set(ind, change);
                        break;
                    }

                    case 10: {
                        int val, index;
                        cout <<"enter the index:";
                        cin >> index;
                        cout <<"enter the value:";
                        cin>> val;
                        mylinkedList->insert(index, val);
                        break;
                    }

                    case 11:
                        cout <<"enter the value:";
                        cin >> value;
                        mylinkedList->delectAny(value);
                        break;

                    case 12:
                        mylinkedList->reverse();
                        break;

                    case 13:
                        delete mylinkedList;
                        goto MAIN_MENU;

                    default:
                        cout << "Invalid choice\n";
                }
            }
        }

        /* ===================== DOUBLY LINKED LIST ===================== */
        else if (mainChoice == 2) {

            DLL* mydll = new DLL();
            int choice, value;

            while (true) {

                cout << "\n1. Append\n";
                cout << "2. Prepend\n";
                cout << "3. Delete Last\n";
                cout << "4. Search\n";
                cout << "5. Print\n";
                cout << "6. Length\n";
                cout << "7. Delete Front\n";
                cout << "8. Get\n";
                cout << "9. Insert\n";
                cout << "10. Delete Any\n";
                cout << "11. Reverse\n";
                cout << "12. Exit DLL\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {

                    case 1:
                        cout <<"enter the value:";
                        cin >> value;
                        mydll->append(value);
                        break;

                    case 2:
                        cout <<"enter the value:";
                        cin >> value;
                        mydll->prepend(value);
                        break;

                    case 3:
                        cout << mydll->LastDelete() << endl;
                        break;

                    case 4:
                        cout <<"enter the value:";
                        cin >> value;
                        mydll->search(value);
                        break;

                    case 5:
                        mydll->printList();
                        break;

                    case 6:
                        mydll->getLength();
                        break;

                    case 7:
                        cout << mydll->FrontDelete() << endl;
                        break;

                    case 8: {
                        int idx;
                        cout <<"enter the index:";
                        cin >> idx;
                        DNode* res = mydll->get(idx);
                        if (res) cout << res->value << endl;
                        break;
                    }

                    case 9: {
                        int idx, val;
                        cout <<"enter the index:";
                        cin >> idx;
                        cout <<"enter the value:";
                        cin>> val;
                        mydll->insert(idx, val);
                        break;
                    }

                    case 10: {
                        int idx;
                        cout <<"enter the index:";
                        cin >> idx;
                        cout << mydll->Delect(idx) << endl;
                        break;
                    }

                    case 11:
                        mydll->reverse();
                        break;

                    case 12:
                        delete mydll;
                        goto MAIN_MENU;

                    default:
                        cout << "Invalid choice\n";
                }
            }
        }

        else if (mainChoice == 3) {
            cout << "Exiting program\n";
            return 0;
        }

        else {
            cout << "Invalid option\n";
        }

        MAIN_MENU:;
    }
}






//STACK USING LINK LIST


#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LL_Stack {
private:
    int maxSize;
    int count;
    Node* top;

public:
    LL_Stack(int maxSize) {
        this->maxSize = maxSize;
        count = 0;
        top = nullptr;
    }

    bool overflow() {
        if (count == maxSize) {
            cout << "Overflow: Stack is full\n";
            return true;
        }
        return false;
    }

    bool underflow() {
        if (count == 0) {
            cout << "Underflow: Stack is empty\n";
            return true;
        }
        return false;
    }

    void push(int value) {
        if (overflow()) return;

        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }

    int pop() {
        if (underflow()) return -1;

        Node* temp = top;
        int value = temp->value;
        top = top->next;
        delete temp;
        count--;
        return value;
    }

    int peek() {
        if (underflow()) return -1;
        return top->value;
    }

    void display() {
        if (underflow()) return;

        Node* temp = top;
        cout << "Stack elements:\n";
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getLength() {
        cout << "Stack size: " << count << endl;
    }

    void reverse () {
        
        Node *holder=top;
        for(int i=0;i<count-1;i++){
            holder=holder->next;
        };
        top=holder;

        Node *temp=top;
        Node*before = nullptr;
        for(int i=0;i<count;i++){
            Node *after=temp->next;
            temp->next=before;
            before=temp;
            temp=after;
        }
        return ;
    };

    ~LL_Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    int maxSize;
    cout << "Enter stack size: ";
    cin >> maxSize;

    LL_Stack* my_LL_Stack = new LL_Stack(maxSize);

    int choice, value;

    printf(" ======== LL_Stack  ==========\n");

    while (true) {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Stack Size\n";
        cout << "6. reverse\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                my_LL_Stack->push(value);
                break;

            case 2:
                value = my_LL_Stack->pop();
                if (value != -1)
                    cout << "Popped: " << value << endl;
                break;

            case 3:
                value = my_LL_Stack->peek();
                if (value != -1)
                    cout << "Top element: " << value << endl;
                break;

            case 4:
                my_LL_Stack->display();
                break;

            case 5:
                my_LL_Stack->getLength();
                break;
            case 6:
                my_LL_Stack->reverse();
                break;
            case 7:
                cout << "Exiting program\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}




// Binary Search Trees
#include <iostream>
using namespace std;

class TNode{
    public:
        int value;
        TNode *left;
        TNode *right;

        TNode(int value){
            this->value=value;
            left=right=nullptr;
        }
};

class Binary_Tree{
    public:
        TNode *root;

        Binary_Tree(){
            root=nullptr;
        };

        bool append(int val){
            TNode *newnode=new TNode(val);
            if(root==nullptr){
                root=newnode;
                return true;
            }else{
                TNode *temp=root;
                while(true){
                    int current=temp->value;
                    if(current==val)return false;
                    if(val>current){
                        if(temp->right==nullptr){
                            temp->right=newnode;
                            return true;
                        };
                        temp=temp->right;
                    }else{
                        if(temp->left==nullptr){
                            temp->left=newnode;
                            return true;
                        };
                        temp=temp->left;
                    } 
                }
                return false;
            }
        }

        bool search(int val){
            if(root==nullptr)return false;

            TNode *temp=root;
            while(temp != nullptr){
                int holder=temp->value;
                if(holder==val){
                    return true;
                }else{
                    if(val>holder){
                        temp=temp->right;
                    }else{
                        temp=temp->left;
                    }
                }
            }
            return false;
        }

        int root_value(){
            if(root == nullptr){
                cout << "Tree is empty\n";
                return -1;   // or throw exception
            }
            return root->value;
        }
};




int main(){

    int choice,value;
    
    Binary_Tree *myBT = new Binary_Tree();
    
    cout << "======== Binary Search Trees ========"<<endl;


    while (true) {
        cout << "\n1. Append\n";
        cout << "2. Search\n";
        cout << "3. rootValue\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1:
                cout <<"enter the value:";
                cin >> value;
                cout << (myBT->append(value) ? "Inserted\n" : "Duplicate\n");
                break;
            
            case 2:
                cout <<"enter the value:";
                cin >> value;
                cout << (myBT->search(value) ? "Found\n" : "Not Found\n");  
                break;

            case 3:
                value=myBT->root_value();
                cout <<value<<endl;
                break;

            default:
                return 0;
        }
    }
}
