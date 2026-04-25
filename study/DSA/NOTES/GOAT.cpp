//# =============================================================
/*TOWER OF HANOI */
//# =============================================================


#include <iostream>
using namespace std;

void TOH(int nd, char f ,char t ,char h){

    if(nd > 0){

        TOH(nd-1,f,h,t);
        printf("(%c,%c) ",f,t);
        TOH(nd-1,h,t,f);
    }
}


int main(){
    
    TOH(3,'a','c','b');
    return 0;
}

//----------------------------------------------------------------------------------------------------------------

//# =============================================================
/* stack */
//# =============================================================


#include <stdio.h>
#define MAX_SIZE 5


int top=-1;
int myarr[MAX_SIZE];


void push_stack(int val){
    if(top<MAX_SIZE-1){
        top++;
        myarr[top]=val;
        printf("pushed the value %d into the stack\n",val);
    }else{
        printf("OVERFLOW.cannot the push the value %d\n",val);
    };

    return;
}


void pop_stack(){
    if(top>-1){
        printf("the value deleted:%d\n",myarr[top]);
        top--;
    }else{
        printf("UNDERFLOW\n");
    };
    
    return;
}


void peek(){
    if(top==-1){
        printf("Empty stack\n");
    }else{
        printf("Top of the stack:%d\n",myarr[top]);
    };

    return;
}

int choice,value;

int main () {

    printf(" ======== STACK ==========\n");

    while (1)
    {
        printf("1. push into stack\n");
        printf("2. pop from stack\n");
        printf("3. peek into stack\n");
        
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("enter what value you want to insert into array :");
                scanf("%d", &value);
                push_stack(value);
                break;
        

            case 2:
                pop_stack(); 
                break; 
                
            case 3:
                peek();
                break;
            default:
                break;
        };
    }
    
    return 0;
}


//----------------------------------------------------------------------------------------------

//# =============================================================
/* queue*/
//# =============================================================

#include <stdio.h>
#define MAX 5

int front=-1,rear=-1,value,choice;

int myqueue[MAX];

void Enqueue(int val){
    
    if (rear == (MAX-1)){
        printf("OVERFLOW\n");
        return;
    };

    if(front==-1){
        front=rear=0;
    }else{
        rear++;
    };
    myqueue[rear]=val;
    printf("enqeue the value\n");

    return;
}


void Dequeue(){

    if(front>rear ||front==-1){
        printf("UNDERFLOW\n");
        return;
    };
    printf("value delected:%d\n",myqueue[front]);
    
    if (front==rear){
        front=rear=-1;
        return;
    };

    front++;

    return;
}


void Traverse(){

    if (front==-1 ) {
        printf("Queue is empty \n");  
        return;
    }

    printf("Queue elements:\n");

    for(int i=front;i<MAX;i++){
        printf("%d\n",myqueue[i]);
    };

    return;
}



void Search(int value){
    if (front==-1 ) {
        printf("Queue is empty \n");  
        return;
    }

    for(int i=front;i<(MAX-1);i++){
        if (myqueue[i]==value){
            printf("found in index:%d\n",i);
            return;
        }
        printf("Not Found\n");
    };

    return;

}



int main(){

    printf(" ======== QUEUE  ==========\n");

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Search\n");
        
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("enter what value you want to insert into queue :");
                scanf("%d", &value);
                Enqueue(value);
                break;
        

            case 2:
                Dequeue(); 
                break; 
                
            case 3:
                Traverse();
                break;

            case 4:
                printf("Value to search in the queue :");
                scanf("%d", &value);
                Search(value);
                break;

            default:
                break;
        }
    }
    
    return 0;
    
}

//----------------------------------------------------------------------------------------------------------------


//# =============================================================
/* circular queue */
//# =============================================================

#include <stdio.h> 
#define MAX 5

int front=-1, rear=-1;
int value, choice;
int myarr[MAX];


void enqueue( int value) {
    
    if (front==(rear+1)%MAX) {
        printf("OVERFLOW\n");
        return ;
    }

    if (front == -1) {
        front=0;
    } 

    rear = (rear + 1) % MAX;
    myarr[rear] = value;  
    return ;

}

void dequeue() {
    if (front == -1 ){
        printf("UNDERFLOW\n");
        return;
    }
    int holder=myarr[front];
    printf("the deleted value is : %d\n", holder);
    if (rear == front) {
        front = -1;
        rear = -1;
        return ;
    }else{
        front = (front + 1) % MAX;
    }
    return ;
}

void Traverse() {
    if (front == -1) {
        printf("Empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d\n", myarr[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}


void Search(int val) {
    if (front == -1) {
        printf("Empty\n");
        return;
    }

    int i = front;
    while (1) {
        if (myarr[i] == val) {
            printf("Found\n");
            return;
        }
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("Not found\n");
}



int main() { 

    printf(" ======== circular queue  ==========\n");

    while (1)
    {
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. Traverse\n");
        printf("4. Search\n");

        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("enter what value you want to insert into array :");
                scanf("%d", &value);
                enqueue(value);
                break;
        

            case 2:
                dequeue(); 
                break;  
                
            case 3:
                Traverse();
                break;

            case 4:
                printf("Value to search in the queue :");
                scanf("%d", &value);
                Search(value);
                break;

            default:
                break;
        };
    };
    
    return 0; 
};

//----------------------------------------------------------------------------------------------

//# =============================================================
//DOUBLE ENDED QUEUE USING CIRCULAR QUEUE
//# =============================================================


#include <stdio.h>
#include <stdbool.h>

#define cap 5

int mydqueue[cap];
int front = 0, dq_size  = 0, rear = cap - 1;

bool isfull() {
    return dq_size  == cap;
}

bool isempty() {
    return dq_size  == 0;
}

void insert_rear(int val){
    if(isfull()){
        printf("OVERLOW\n");
        return;
    };
    rear=(rear+1)%cap;
    mydqueue[rear]=val;
    printf("insertng in %d value: %d\n",rear,val);
    dq_size ++;
    return;
}

void delect_front (){
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    int holder=mydqueue[front];
    printf("Element delect:%d\n",holder);
    front=(front+1)%cap;
    dq_size --;
    return;
}

void insert_front(int val){
    if(isfull()){
        printf("OVERLOW\n");
        return;
    };
    front=(front-1+cap)%cap;
    mydqueue[front]=val;
    printf("insertng in %d value: %d\n",front,val);
    dq_size ++;
    return;
}

void delect_rear(){
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    int holder=mydqueue[rear];
    printf("Element delect:%d\n",holder);
    rear=(rear-1+cap)%cap;
    dq_size --;
    return;
}

int getFront() {
    if (isempty()) return -1;
    return mydqueue[front];
}

int getRear() {
    if (isempty()) return -1;
    return mydqueue[rear];
}

void Traverse(){
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    for (int count = 0; count < dq_size ; count++) {
        printf("%d\n", mydqueue[i]);
        i = (i + 1) % cap;
    }
}

void Search(int val){
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    for (int count = 0; count < dq_size ; count++) {
        if (mydqueue[i] == val) {
            printf("Found\n");
            return;
        }
        i = (i + 1) % cap;
    }
    printf("Not found\n");
}

int main (){

    int value,choice;

    printf(" ======== DEQUEUE  ==========\n");

    while (1)
    {
        printf("1. insert_rear\n");
        printf("2. delect_front\n");
        printf("3. insert_front\n");
        printf("4. delect_rear\n");
        printf("5. Traverse\n");
        printf("6. Search\n");
        
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("enter what value you want to insert into dequeue :");
                scanf("%d", &value);
                insert_rear(value);
                break;
        

            case 2:
                delect_front(); 
                break; 
                
            case 3:
                printf("enter what value you want to insert into dequeue :");
                scanf("%d", &value);
                insert_front(value);
                break;

            case 4:
                delect_rear(); 
                break; 

            case 5:
                Traverse();
                break;
            case 6:
                printf("Value to search in the queue :");
                scanf("%d", &value);
                Search(value);
                break;

            default:
                break;
        }
    }


    return 0;
}

//----------------------------------------------------------------------------------------------

//# =============================================================
/*  LL AND DLL */
//# =============================================================



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



//-------------------------------------------------------------------------------------------------


//# =============================================================
/* POLYNOMIAL USING LINKED LIST   */
//# =============================================================




#include <stdio.h>
#include <stdlib.h>

/* structure */
struct node {
    int coeff;
    int power;
    struct node *next;
};

/* create new node */
struct node* createNode(int c, int p) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = c;
    temp->power = p;
    temp->next = NULL;
    return temp;
}

/* insert term in sorted order */
struct node* insert(struct node *head, int c, int p) {
    struct node *temp = createNode(c, p);

    if (head == NULL || head->power < p) {
        temp->next = head;
        return temp;
    }

    struct node *cur = head;
    while (cur->next != NULL && cur->next->power > p)
        cur = cur->next;

    if (cur->next != NULL && cur->next->power == p) {
        cur->next->coeff += c;
        free(temp);
    } else {
        temp->next = cur->next;
        cur->next = temp;
    }

    return head;
}

/* create polynomial */
struct node* createPoly() {
    struct node *head = NULL;
    int n, c, p;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &c, &p);
        head = insert(head, c, p);
    }
    return head;
}

/* display polynomial */
void display(struct node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

/* addition */
struct node* add(struct node *p1, struct node *p2) {
    struct node *res = NULL;

    while (p1 && p2) {
        if (p1->power > p2->power) {
            res = insert(res, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p2->power > p1->power) {
            res = insert(res, p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            res = insert(res, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        res = insert(res, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2) {
        res = insert(res, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return res;
}

/* subtraction */
struct node* subtract(struct node *p1, struct node *p2) {
    struct node *res = NULL;

    while (p2) {
        res = insert(res, -p2->coeff, p2->power);
        p2 = p2->next;
    }

    while (p1) {
        res = insert(res, p1->coeff, p1->power);
        p1 = p1->next;
    }

    return res;
}

/* multiplication */
struct node* multiply(struct node *p1, struct node *p2) {
    struct node *res = NULL;

    for (struct node *i = p1; i != NULL; i = i->next) {
        for (struct node *j = p2; j != NULL; j = j->next) {
            res = insert(res,
                         i->coeff * j->coeff,
                         i->power + j->power);
        }
    }
    return res;
}

int main() {

    struct node *p1 = NULL, *p2 = NULL, *result = NULL;
    int choice;

    printf("===== POLYNOMIAL USING LINKED LIST =====\n");

    while (1) {
        printf("\n1. Create Polynomial 1");
        printf("\n2. Create Polynomial 2");
        printf("\n3. Display Polynomials");
        printf("\n4. Addition");
        printf("\n5. Subtraction (P1 - P2)");
        printf("\n6. Multiplication");
        printf("\n7. Exit");
        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                p1 = createPoly();
                break;

            case 2:
                p2 = createPoly();
                break;

            case 3:
                printf("Polynomial 1: ");
                display(p1);
                printf("Polynomial 2: ");
                display(p2);
                break;

            case 4:
                result = add(p1, p2);
                printf("Addition Result: ");
                display(result);
                break;

            case 5:
                result = subtract(p1, p2);
                printf("Subtraction Result: ");
                display(result);
                break;

            case 6:
                result = multiply(p1, p2);
                printf("Multiplication Result: ");
                display(result);
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}






//----------------------------------------------------------------------------------------------

//# =============================================================
//STACK USING LINK LIST
//# =============================================================







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


//----------------------------------------------------------------------------------------------

//# =============================================================
/* CIRCULAR LINKED LIST */
//# =============================================================




#include  <iostream>

using namespace std;


class Node{
    public:
        int value;
        Node *next;

        Node(int value){
            this->value=value;
            next=nullptr;
        }

};

Node *head=nullptr;
Node *rear=nullptr;


void append(int val){
    Node *newnode=new Node(val);
    if(head==nullptr){
        head=rear=newnode;
    }else{
        rear->next=newnode;
        rear=rear->next;
    }
    rear->next=head;
    return;
};


void prepend(int val){
    Node *newnode = new Node(val);

    if(head == nullptr){
        head = rear = newnode;
        rear->next = head;
    } else {
        newnode->next = head;
        head = newnode;
        rear->next = head;
    }
};



void display(){
    Node *temp=head;
    if(head==nullptr) return;
    do{
        cout << temp->value << endl;
        temp = temp->next;
    } while(temp != head);
};


int delete_last(){
    int remove=rear->value;
    if(head == rear){
        delete rear;
        head = rear = nullptr;
    }
    Node *temp=head;
    while(temp->next!=rear){
        temp=temp->next;
    };
    temp->next=head;
    delete rear;
    rear=temp;
    return remove;
};


int delete_front(){
    if (head==nullptr) return -1;
    int remove=head->value;
    Node *temp=head->next;
    rear->next=temp;
    delete head;
    head=temp;
    return remove;
}

int main(){

    int choice;

    cout << "1. Append value\n";
    cout << "2. Prepend value\n";
    cout << "3. Delete last node\n";
    cout << "4. Print list\n";
    cout << "5. Delect First\n";
    cout << "6. Get Value\n";
    cout << "7. Set Value\n";
    cout << "8. Insert Any\n";
    cout << "9. Delect Any\n";
    cout << "10. Reverse\n";
    cout << "11. Exit LL\n";

    while(1){
        int user;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                
                cout << "what is the value you want to append:";
                cin >> user;
                append(user);
                break;

            case 2:
               
                cout << "what is the value you want to append:";
                cin >> user;
                prepend(user);
                cout << "Value prepended successfully\n";
                break;

            case 3:
                cout <<"Delected value:";
                cout <<delete_last()<<endl;
                break;

            case 5:
                cout <<"Delected value:";
                cout <<delete_front()<<endl;
                break;

                
            case 4:
                cout << "values are \n";
                display();
                break;

            case 11:
                cout << "Exiting Linked List...\n";
                return 0;


        }
    }
    
    return 0;
};


//--------------------------------------------------------------------------------------------------------

//# =============================================================
/*  Binary Search Tree   */
//# =============================================================







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

            if(currtemp==nullptr){
                return nullptr;
            }
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


// ─── Helper to print the menu ───────────────────────────────────────────────
void printMenu(){
    cout << "\n====== Binary Search Tree Menu ======\n";
    cout << " 1. Insert\n";
    cout << " 2. Search\n";
    cout << " 3. Remove\n";
    cout << " 4. BFS (Level Order)\n";
    cout << " 5. DFS Pre-Order\n";
    cout << " 6. DFS Post-Order\n";
    cout << " 7. DFS In-Order\n";
    cout << " 8. Exit\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}


int main(){

    BinarySearchTree* myBST = new BinarySearchTree();
    int choice, value;

    do {
        printMenu();
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                myBST->insert(value);
                cout << value << " inserted.\n";
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if(myBST->search(value) != nullptr){
                    cout << value << " found in the tree.\n";
                } else {
                    cout << value << " not found in the tree.\n";
                }
                break;

            case 3:
                cout << "Enter value to remove: ";
                cin >> value;
                myBST->RemoveNode(value);
                cout << value << " removed (if it existed).\n";
                break;

            case 4:
                if(myBST->root == nullptr){
                    cout << "Tree is empty.\n";
                } else {
                    cout << "BFS (Level Order): ";
                    myBST->BFS();
                    cout << endl;
                }
                break;

            case 5:
                if(myBST->root == nullptr){
                    cout << "Tree is empty.\n";
                } else {
                    cout << "DFS Pre-Order: ";
                    myBST->DFSPreOrder(myBST->root);
                    cout << endl;
                }
                break;

            case 6:
                if(myBST->root == nullptr){
                    cout << "Tree is empty.\n";
                } else {
                    cout << "DFS Post-Order: ";
                    myBST->DFSPostOrder(myBST->root);
                    cout << endl;
                }
                break;

            case 7:
                if(myBST->root == nullptr){
                    cout << "Tree is empty.\n";
                } else {
                    cout << "DFS In-Order: ";
                    myBST->DFSInOrder(myBST->root);
                    cout << endl;
                }
                break;

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please enter 1-8.\n";
        }

    } while(choice != 8);

    delete myBST;
    return 0;
}



//------------------------------------------------------------------------------------------------------------

//# =============================================================
/* AVL Tree  */
//# =============================================================




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



//--------------------------------------------------------------------------------------------------

//# =============================================================
/*  graphs  */
//# =============================================================





#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class graph{
    private:
        unordered_map<char,unordered_set<char>>adjlist;

    public:

        void display(){
            for(auto keys:adjlist){
                cout <<keys.first<<" : [ ";
                for(auto neighbours:keys.second){
                    cout << neighbours<<" ";
                };            
                cout <<"]"<<endl;  
            }
        }

        int add_vertex(char vertex){
            if(adjlist.count(tolower(vertex))==0){
                adjlist[tolower(vertex)];
                return 1;
            };
            return 0;
        }


        int  add_edge(char v1,char v2){
            if(adjlist.count(tolower(v1))!= 0 && adjlist.count(tolower(v2))!= 0){
                adjlist[tolower(v1)].insert(tolower(v2)); //here adjlist[v1] returns the unordered_set of v1 then as we git the set then we are using the property of set to insert v2 in the set of v1 and same for v2
                adjlist[tolower(v2)].insert(tolower(v1));
                return 1;
            };
            return 0;
        }


        int remove_edge(char v1,char v2){
            if(adjlist.count(tolower(v1))!= 0 && adjlist.count(tolower(v2))!= 0){
                adjlist[tolower(v1)].erase(tolower(v2)); //here adjlist[v1] returns the unordered_set of v1 then as we git the set then we are using the property of set to erase v2 in the set of v1 and same for v2
                adjlist[tolower(v2)].erase(tolower(v1));
                return 1;
            };
            return 0;
        } 
        
        int remove_vertex(char vertex){
            if(adjlist.count(tolower(vertex)) !=0){
                adjlist.erase(tolower(vertex));
                return 1;
        }
        return 0;
        }

        int remove_edge(char vertex){
            if (adjlist.count(tolower(vertex)) !=0){
                for(auto neighbour:adjlist.at(tolower(vertex))){
                    adjlist[neighbour].erase(tolower(vertex));
                }
                adjlist.erase(tolower(vertex));
                return 1;
        }
        return 0;
        }

        unordered_set <char> answer;

        void DFS(char startchar){
            cout << "DFS: ";
            startchar = tolower(startchar);
            cout << startchar<<" ";
            answer.insert(startchar);
            for(auto right : adjlist.at(startchar)){
                if(answer.count(right) == 0){
                    DFS(right);
                }
            }
            
        }


        void BFS(char startchar){
            startchar = tolower(startchar);
            cout <<"BFS: ";
            unordered_set <char> bfsanswer;
            queue <char>q;
            q.push(startchar);
            bfsanswer.insert(startchar);
            while(!q.empty() ){
                char current = q.front();
                q.pop();
                cout << current << " ";
                for(auto right : adjlist.at(current)){
                    if( bfsanswer.count(right) == 0){
                        q.push(right);
                        bfsanswer.insert(right);
                    }
                    
                }
            }

        }




};



int main (){
    cout <<"hello world"<<endl;

    graph *mygraph = new graph();
    mygraph->add_vertex('A');
    mygraph->add_vertex('B'); 
    mygraph->add_vertex('C'); 
    mygraph->add_vertex('D'); 
    mygraph->add_vertex('E'); 
    mygraph->add_vertex('F'); 
    mygraph->add_vertex('G'); 


    mygraph->add_edge('A','B');
    mygraph->add_edge('A','C');
    mygraph->add_edge('A','D');
    mygraph->add_edge('B','C');
    mygraph->add_edge('C','B');
    mygraph->add_edge('C','E');
    mygraph->add_edge('D','E');
    mygraph->add_edge('E','F');
    mygraph->add_edge('E','G');


    mygraph->display();

    //mygraph->remove_edge('A','D');
    //mygraph->remove_edge('C','D');
    //mygraph->remove_edge('B','D');

    //mygraph->display();
    mygraph->BFS('A');
    mygraph->DFS('A');

    return 0;
}

//-------------------------------------------------------------------------------------

//# =============================================================
/* MATRIX GRAPHS */
//# =============================================================






#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GraphMatrix {
    vector<vector<int>> mat;
    vector<char> ver;
    int n;
    bool directed;

public:
    GraphMatrix(int size, bool isDirected = false)
        : n(size), directed(isDirected),
          mat(size, vector<int>(size, 0)),
          ver(size, '?') {}

    void set_vertex(int i, char v){ ver[i] = tolower(v); }

    int index(char v){
        v = tolower(v);
        for(int i = 0; i < n; i++)
            if(ver[i] == v) return i;
        return -1;
    }

    void add_edge(char u, char v){
        int i = index(u), j = index(v);
        if(i == -1 || j == -1){ cout << "Vertex not found.\n"; return; }
        mat[i][j] = 1;
        if(!directed) mat[j][i] = 1;
        cout << "Edge " << (char)tolower(u)
             << (directed?" -> ":" -- ")
             << (char)tolower(v) << " added.\n";
    }

    void display(){
        cout << "\nAdjacency Matrix:\n    ";
        for(int j = 0; j < n; j++) cout << ver[j] << " ";
        cout << "\n";
        for(int i = 0; i < n; i++){
            cout << "  " << ver[i] << " ";
            for(int j = 0; j < n; j++) cout << mat[i][j] << " ";
            cout << "\n";
        }
    }

    int degree(char v){
        int i = index(v);
        if(i == -1){ cout << "Vertex not found.\n"; return -1; }
        int d = 0;
        for(int j = 0; j < n; j++) if(mat[i][j]) d++;
        return d;
    }

    void dfs_util(int v, vector<bool>& vis){
        vis[v] = true;
        cout << ver[v] << " ";
        for(int i = 0; i < n; i++)
            if(mat[v][i] == 1 && vis[i] == false)
                dfs_util(i, vis);
    }

    void DFS(char s){
        int start = index(s);
        if(start == -1){ cout << "Vertex not found.\n"; return; }
        vector<bool> vis(n, false);
        cout << "DFS from '" << (char)tolower(s) << "': ";
        dfs_util(start, vis);
        cout << "\n";
    }

    void BFS(char s){
        int start = index(s);
        if(start == -1){ cout << "Vertex not found.\n"; return; }
        vector<bool> vis(n, false);
        queue<int> q;
        vis[start] = true;
        q.push(start);
        cout << "BFS from '" << (char)tolower(s) << "': ";
        while(!q.empty()){
            int u = q.front(); q.pop();
            cout << ver[u] << " ";
            for(int i = 0; i < n; i++)
                if(mat[u][i] == 1 && !vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
        }
        cout << "\n";
    }
};

// ── helpers ──────────────────────────────────────────────────
const string SEP = string(40, '-');

bool askDirected(){
    int t;
    cout << "  1. Undirected\n  2. Directed\n  Type: ";
    cin >> t;
    return (t == 2);
}

void matrixMenu(){
    cout << "\n" << SEP
         << "\n  1. Add Edge"
         << "\n  2. Display"
         << "\n  3. Degree"
         << "\n  4. DFS"
         << "\n  5. BFS"
         << "\n  0. Exit"
         << "\n" << SEP
         << "\n  Choice: ";
}

// ── main ─────────────────────────────────────────────────────
int main(){
    int sz;
    cout << "Number of vertices: ";
    cin >> sz;

    bool dir = askDirected();
    GraphMatrix g(sz, dir);

    cout << "Enter " << sz << " vertex labels:\n  ";
    for(int i = 0; i < sz; i++){
        char x; cin >> x;
        g.set_vertex(i, x);
    }
    cout << "\nMatrix Graph (" << (dir ? "Directed" : "Undirected") << ") created.\n";

    int ch; char u, v;
    while(true){
        matrixMenu();
        cin >> ch;
        if(ch == 0){ cout << "\nGoodbye!\n"; break; }
        switch(ch){
            case 1:
                cout << "  Edge (u v): "; cin >> u >> v;
                g.add_edge(u, v);
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout << "  Vertex: "; cin >> u;
                cout << "  Degree: " << g.degree(u) << "\n";
                break;
            case 4:
                cout << "  Start: "; cin >> u;
                g.DFS(u);
                break;
            case 5:
                cout << "  Start: "; cin >> u;
                g.BFS(u);
                break;
            default:
                cout << "  Invalid option.\n";
        }
    }
    return 0;
}



//------------------------------------------------------------------------------------------

//# =============================================================
/*   GRPAH  COMBINED */
//# =============================================================




#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

/* =========================
ADJACENCY LIST GRAPH
========================= */
class GraphList {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, char> parent;
    bool directed;                         

public:
    GraphList(bool isDirected = false) : directed(isDirected) {}

    /* ── ADD ─────────────────────────────── */
    void add_vertex(char v){
        v = tolower(v);
        if(adj.count(v) == 0){ 
            adj[v];
            cout << "Vertex '" << v << "' added.\n";
        }else{
            cout << "Vertex already exists.\n";
        };
        return; 
    }

    void add_edge(char u, char v){
        u = tolower(u);
        v = tolower(v);
        if(adj.count(u) !=0 && adj.count(v) != 0){
            adj.at(u).insert(v);
            if(directed == false){
                adj[v].insert(u);
            }   
        }                   
            
        cout << "One or both vertices not found.\n";
        cout << "Edge " << u << (directed?" -> ":" -- ") << v << " added.\n";

        return;

    }

    /* ── REMOVE ──────────────────────────── */

    void remove_edge(char u, char v){
        u = tolower(u); v = tolower(v);
        if(adj.count(u) !=0 && adj.count(v) !=0){
            adj[u].erase(v);
            if(directed == false){
                adj[v].erase(u);
            }
        }else{
            cout << "One or both vertices not found.\n";
        }
        cout << "Edge " << u << " -- " << v << " removed.\n";
        return;
    }

    void remove_vertex(char v){
        v = tolower(v);
        if(adj.count(v) == 0){ 
            cout << "Vertex not found.\n"; 
            return; 
        };

        for(auto neighbour:adj.at(v)){
            adj[neighbour].erase(v);
        }
        adj.erase(v);
        cout << "Vertex '" << v << "' and all its edges removed.\n";
    }

    /* ── DISPLAY ─────────────────────────── */
    void display(){
        if(adj.empty()){ cout << "(empty graph)\n"; return; }
        string gtype = directed ? "Directed" : "Undirected";
        cout << "\nAdjacency List [" << gtype << "]:\n";
        for(auto& k : adj){
            cout << "  " << k.first << " : [ ";
            if(k.second.empty()) cout << "(none)";
            else for(auto n : k.second) cout << n << " ";
            cout << "]\n";
        }
    }

    /* ── DFS ─────────────────────────────── */
    void dfs_util(char v, unordered_set<char>& vis){
        cout << v << " ";
        vis.insert(v);
        for(auto n : adj[v])
            if(vis.count(n) == 0){
                dfs_util(n, vis);
            }   
    }

    void DFS(char s){
        s = tolower(s);
        if(!adj.count(s)){ cout << "Vertex not found.\n"; return; }
        unordered_set<char> vis;
        cout << "DFS from '" << s << "': ";
        dfs_util(s, vis);
        cout << "\n";
    }

    /* ── BFS ─────────────────────────────── */
    void BFS(char s){
        s = tolower(s);
        if(!adj.count(s)){ cout << "Vertex not found.\n"; return; }
        unordered_set<char> vis;
        queue<char> q;
        q.push(s); vis.insert(s);
        cout << "BFS from '" << s << "': ";
        while(!q.empty()){
            char v = q.front(); 
            q.pop();
            cout << v << " ";
            for(auto n : adj[v])
                if(!vis.count(n)){ vis.insert(n); q.push(n); }
        }
        cout << "\n";
    }

    /* ── SEARCH ──────────────────────────── */
    bool search_vertex(char v){ return adj.count(tolower(v)); }

    bool search_edge(char u, char v){
        u = tolower(u); v = tolower(v);
        if(!adj.count(u)) return false;
        return adj[u].count(v);
    }

    /* ── DEGREE ──────────────────────────── */
    int degree(char v){
        v = tolower(v);
        if(adj.count(v)) return adj[v].size();
        return -1;
    }

    /* ── GRAPH PROPERTIES ────────────────── */
    void dfs_conn(char v, unordered_set<char>& vis){
        vis.insert(v);
        for(auto n : adj[v])
            if(!vis.count(n))
                dfs_conn(n, vis);
    }

    bool is_connected(){
        if(adj.empty()) return true;
        unordered_set<char> vis;
        dfs_conn(adj.begin()->first, vis);
        return vis.size() == adj.size();
    }

    bool self_loop(){
        for(auto& k : adj)
            if(k.second.count(k.first))
                return true;
        return false;
    }

    /* ── CYCLE DETECTION ─────────────────── */

    // Union-Find cycle (undirected only)
    char uf_find(char v){
        if(parent[v] == v) return v;
        return parent[v] = uf_find(parent[v]);
    }

    void uf_union(char a, char b){
        parent[uf_find(a)] = uf_find(b);
    }

    bool cycle_union(){
        for(auto& k : adj) parent[k.first] = k.first;
        for(auto& k : adj){
            for(auto n : k.second){
                if(k.first < n){
                    char p1 = uf_find(k.first);
                    char p2 = uf_find(n);
                    if(p1 == p2) return true;
                    uf_union(p1, p2);
                }
            }
        }
        return false;
    }

    // Directed cycle detection using recursion stack DFS
    bool cycle_dir_util(char v, unordered_set<char>& vis,
                                unordered_set<char>& recStack){
        vis.insert(v);
        recStack.insert(v);
        for(auto n : adj[v]){
            if(!vis.count(n)){
                if(cycle_dir_util(n, vis, recStack))
                    return true;
            } else if(recStack.count(n)){   // back edge in current path = cycle
                return true;
            }
        }
        recStack.erase(v);
        return false;
    }

    bool cycle_directed(){
        unordered_set<char> vis, recStack;
        for(auto& k : adj)
            if(!vis.count(k.first))
                if(cycle_dir_util(k.first, vis, recStack))
                    return true;
        return false;
    }

    // Unified entry point — picks the right method based on graph type
    void detect_cycle(){
        bool result;
        if(directed){
            result = cycle_directed();
            cout << "Cycle (DFS recStack): " << (result ? "Yes" : "No") << "\n";
        } else {
            result = cycle_union();
            cout << "Cycle (Union-Find): " << (result ? "Yes" : "No") << "\n";
        }
    }
};


/* =========================
WEIGHTED GRAPH
========================= */
class WeightedGraph {
    unordered_map<char, vector<pair<char,int>>> adj;
    bool directed;

public:
    WeightedGraph(bool isDirected = false) : directed(isDirected) {}

    void add_vertex(char v){
        v = tolower(v);
        if(adj.count(v)){ cout << "Vertex already exists.\n"; return; }
        adj[v];
        cout << "Vertex '" << v << "' added.\n";
    }

    void add_edge(char u, char v, int w){
        u = tolower(u); v = tolower(v);
        if(!adj.count(u) || !adj.count(v)){
            cout << "One or both vertices not found.\n"; return;
        }
        adj[u].push_back({v, w});
        if(!directed)
            adj[v].push_back({u, w});
        cout << "Edge " << u << (directed?" -> ":" -- ") << v
            << " (weight=" << w << ") added.\n";
    }

    void display(){
        if(adj.empty()){ cout << "(empty graph)\n"; return; }
        string gtype = directed ? "Directed" : "Undirected";
        cout << "\nWeighted Adjacency List [" << gtype << "]:\n";
        for(auto& k : adj){
            cout << "  " << k.first << " : [ ";
            if(k.second.empty()) cout << "(none)";
            else for(auto& p : k.second)
                cout << "(" << p.first << "," << p.second << ") ";
            cout << "]\n";
        }
    }
};


/* =========================
MATRIX GRAPH
========================= */
class GraphMatrix {
    vector<vector<int>> mat;
    vector<char> ver;
    int n;
    bool directed;

public:
    GraphMatrix(int size, bool isDirected = false)
        : n(size), directed(isDirected),
        mat(size, vector<int>(size, 0)),
        ver(size, '?') {}

    void set_vertex(int i, char v){ ver[i] = tolower(v); }

    int index(char v){
        v = tolower(v);
        for(int i = 0; i < n; i++)
            if(ver[i] == v) return i;
        return -1;
    }

    void add_edge(char u, char v){
        int i = index(u), j = index(v);
        if(i == -1 || j == -1){ cout << "Vertex not found.\n"; return; }
        mat[i][j] = 1;
        if(!directed) mat[j][i] = 1;
        cout << "Edge " << (char)tolower(u)<< (directed?" -> ":" -- ") 
        << (char)tolower(v) << " added.\n";
    }

    void display(){
        cout << "\nAdjacency Matrix:\n    ";
        for(int j = 0; j < n; j++) cout << ver[j] << " ";
        cout << "\n";
        for(int i = 0; i < n; i++){
            cout << "  " << ver[i] << " ";
            for(int j = 0; j < n; j++) cout << mat[i][j] << " ";
            cout << "\n";
        }
    }

    int degree(char v){
        int i = index(v);
        if(i == -1){ cout << "Vertex not found.\n"; return -1; }
        int d = 0;
        for(int j = 0; j < n; j++) if(mat[i][j]) d++;
        return d;
    }

    void dfs_util(int v, vector<bool>& vis){
        vis[v] = true;
        cout << ver[v] << " ";
        for(int i = 0; i < n; i++)
            if(mat[v][i] == 1 && vis[i] == false)
                dfs_util(i, vis);
    }

    void DFS(char s){
        int start = index(s);
        if(start == -1){ cout << "Vertex not found.\n"; return; }
        vector<bool> vis(n, false);
        cout << "DFS from '" << (char)tolower(s) << "': ";
        dfs_util(start, vis);
        cout << "\n";
    }

    void BFS(char s){
        int start = index(s);
        if(start == -1){ cout << "Vertex not found.\n"; return; }
        vector<bool> vis(n, false);
        queue<int> q;
        vis[start] = true;
        q.push(start);
        cout << "BFS from '" << (char)tolower(s) << "': ";
        while(!q.empty()){
            int u = q.front(); q.pop();
            cout << ver[u] << " ";
            for(int i = 0; i < n; i++)
                if(mat[u][i] == 1 && !vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
        }
        cout << "\n";
    }
};



const string SEP = string(42, '-');

void printMainMenu(){
    cout << "\n" << SEP
        << "\n 1. List Graph"
        << "\n 2. Matrix Graph"
        << "\n 3. Weighted Graph"
        << "\n 0. Exit"
        << "\n" << SEP
        << "\nChoice: ";
}

bool askDirected(){
    int t;
    cout << " 1. Undirected\n 2. Directed\nType: ";
    cin >> t;
    return (t == 2);
}

void listMenu(){ cout
    << "\n" << SEP
    << "\n 1.  Add Vertex"
    << "\n 2.  Add Edge"
    << "\n 3.  Remove Edge"        
    << "\n 4.  Remove Vertex"      
    << "\n 5.  Display"
    << "\n 6.  DFS"
    << "\n 7.  BFS"
    << "\n 8.  Search Vertex"
    << "\n 9.  Search Edge"
    << "\n 10. Degree"
    << "\n 11. Connected?"
    << "\n 12. Self Loop?"
    << "\n 13. Detect Cycle"       
    << "\n 0.  Back"
    << "\n" << SEP
    << "\nChoice: ";
}

void matrixMenu(){ cout
    << "\n" << SEP
    << "\n 1. Add Edge"
    << "\n 2. Display"
    << "\n 3. Degree"
    << "\n 4. DFS"                 // FIX 5
    << "\n 5. BFS"                 // FIX 5
    << "\n 0. Back"
    << "\n" << SEP
    << "\nChoice: ";
}

void weightedMenu(){ cout
    << "\n" << SEP
    << "\n 1. Add Vertex"
    << "\n 2. Add Edge (with weight)"
    << "\n 3. Display"
    << "\n 0. Back"
    << "\n" << SEP
    << "\nChoice: ";
}


/* =========================
MAIN
========================= */
int main(){
    int choice;
    while(true){
        printMainMenu();
        cin >> choice;
        if(choice == 0) break;

        /* ── LIST GRAPH ─────────────────── */
        if(choice == 1){
            bool dir = askDirected();
            GraphList g(dir);
            cout << "\nList Graph (" << (dir?"Directed":"Undirected") << ") created.\n";

            int ch; char u, v;
            while(true){
                listMenu();
                cin >> ch;
                if(ch == 0) break;
                switch(ch){
                    case 1:
                        cout << "Vertex: "; cin >> u;
                        g.add_vertex(u);
                        break;
                    case 2:
                        cout << "Edge (u v): "; cin >> u >> v;
                        g.add_edge(u, v);
                        break;
                    case 3:                         // FIX 2
                        cout << "Remove edge (u v): "; cin >> u >> v;
                        g.remove_edge(u, v);
                        break;
                    case 4:                         // FIX 3
                        cout << "Remove vertex: "; cin >> u;
                        g.remove_vertex(u);
                        break;
                    case 5:  g.display();           break;
                    case 6:
                        cout << "Start: "; cin >> u;
                        g.DFS(u);
                        break;
                    case 7:
                        cout << "Start: "; cin >> u;
                        g.BFS(u);
                        break;
                    case 8:
                        cout << "Vertex: "; cin >> u;
                        cout << (g.search_vertex(u) ? "Found\n" : "Not Found\n");
                        break;
                    case 9:
                        cout << "Edge (u v): "; cin >> u >> v;
                        cout << (g.search_edge(u,v) ? "Edge exists\n" : "No such edge\n");
                        break;
                    case 10:
                        cout << "Vertex: "; cin >> u;
                        cout << "Degree: " << g.degree(u) << "\n";
                        break;
                    case 11:
                        cout << (g.is_connected() ? "Connected\n" : "Not Connected\n");
                        break;
                    case 12:
                        cout << (g.self_loop() ? "Self loop exists\n" : "No self loop\n");
                        break;
                    case 13:                        // FIX 4
                        g.detect_cycle();
                        break;
                    default: cout << "Invalid option.\n";
                }
            }
        }

        /* ── MATRIX GRAPH ───────────────── */
        else if(choice == 2){
            int sz;
            cout << "Number of vertices: "; cin >> sz;
            bool dir = askDirected();
            GraphMatrix g(sz, dir);

            cout << "Enter " << sz << " vertex labels:\n";
            for(int i = 0; i < sz; i++){
                char x; cin >> x;
                g.set_vertex(i, x);
            }
            cout << "\nMatrix Graph (" << (dir?"Directed":"Undirected") << ") created.\n";

            int ch; char u, v;
            while(true){
                matrixMenu();
                cin >> ch;
                if(ch == 0) break;
                switch(ch){
                    case 1:
                        cout << "Edge (u v): "; cin >> u >> v;
                        g.add_edge(u, v);
                        break;
                    case 2: g.display();             break;
                    case 3:
                        cout << "Vertex: "; cin >> u;
                        cout << "Degree: " << g.degree(u) << "\n";
                        break;
                    case 4:                          // FIX 5
                        cout << "Start: "; cin >> u;
                        g.DFS(u);
                        break;
                    case 5:                          // FIX 5
                        cout << "Start: "; cin >> u;
                        g.BFS(u);
                        break;
                    default: cout << "Invalid option.\n";
                }
            }
        }

        /* ── WEIGHTED GRAPH ─────────────── */
        else if(choice == 3){
            bool dir = askDirected();
            WeightedGraph g(dir);
            cout << "\nWeighted Graph (" << (dir?"Directed":"Undirected") << ") created.\n";

            int ch, w; char u, v;
            while(true){
                weightedMenu();
                cin >> ch;
                if(ch == 0) break;
                switch(ch){
                    case 1:     
                        cout << "Vertex: "; cin >> u;
                        g.add_vertex(u);
                        break;
                    case 2:
                        cout << "Edge (u v weight): "; cin >> u >> v >> w;
                        g.add_edge(u, v, w);
                        break;
                    case 3: g.display();              break;
                    default: cout << "Invalid option.\n";
                }
            }
        }

        else { cout << "Invalid choice.\n"; }
    }

    cout << "\nGoodbye!\n";
    return 0;
}


//------------------------------------------------------------------------------------------------

//# =============================================================
/* HashTable  */
//# =============================================================






    #include <iostream>
    #include <vector>
    using namespace std;

    class Node{
        public:
            int value;
            string key;
            Node *next;


            Node(string key ,int value){
                this->value=value;
                this->key=key;
                next=nullptr;
            }

    };


    class HashTable{
        private:
            static const int SIZE=7;
            Node *storage[SIZE];
        public:
            
            int hash_function(string key){
                int hash =0;
                for(int i = 0;i<key.length();i++){
                    int asiivalue = int(key[i]);
                    hash=(hash +asiivalue*32)%SIZE;
                }
                return hash;
            };


            void set(string key,int value){
                int index=hash_function(key);
                Node *newnode=new Node(key,value);
                if (storage[index]==nullptr){
                    storage[index]=newnode;
                }else{
                    Node *temp=storage[index];
                    while(temp->next!=nullptr){
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }

            }

            void printTable(){
                for(int i=0;i<SIZE;i++){
                    Node *temp=storage[i];
                    cout<<i<<':'<<endl;
                    while (temp!=nullptr){
                        cout <<'{'<< temp->key<<':'<< temp->value<<'}'<<endl;
                        temp=temp->next;
                    }
                }
            }


            int get(string check){

                int index=hash_function(check);
                Node *temp=storage[index];
                while (temp!=nullptr){
                    if(temp->key==check){
                    return temp->value;
                    }else{
                        temp=temp->next;
                    }
                }
                return -1;
            }

            vector<string> keys(){
                vector<string> allkeys;
                for (int i=0;i<7;i++){
                    Node *temp=storage[i];
                    while(temp){
                        allkeys.push_back(temp->key);
                        temp=temp->next;
                    }
                }
                return allkeys;
            }



    };


    int main(){

        HashTable*myhashtable=new HashTable();

        myhashtable->set("eat",4);

        myhashtable->set("tea",5);

        myhashtable->printTable();


        myhashtable->set("lumber",6);

        myhashtable->printTable();

        cout << myhashtable->get("nails")<< endl;

        cout << myhashtable->get("bolt")<< endl;
    }


//----------------------------------------------------------------------------------------------

//# =============================================================
/*  heap TREE */
//# =============================================================





#include <iostream>
#include <vector>

using namespace std;

class heap{
    private:
        vector<int>storage;

    public:
        
        void swap(int *x,int *y){
            int temp=*x;
            *x=*y;
            *y=temp;
            return;
        }

        void insert(int vertex){
            storage.push_back(vertex);

            int child_index=storage.size()-1;
           
            int parent_index=(child_index-1)/2;
            while(child_index > 0 && vertex>storage[parent_index]){
                swap(&storage[child_index],&storage[parent_index]);
                child_index=parent_index;
                parent_index=(child_index-1)/2;
            };
            return;
        }

        void display(){
            for(auto i :storage){
                cout << i <<' ';
            }
            cout << endl;
            return ;

        }


        int delect() {
            if(storage.empty()){
                cout << "heap is empty" << endl;
                return -1;
            }

            int max_val = storage[0];
            swap(&storage[0],&storage[storage.size()-1]);
            storage.pop_back();

            int parent = 0;

            while(true) {
                int left = 2*parent + 1;
                int right = 2*parent + 2;
                int largest = parent;

                if(left < storage.size() && storage[left] > storage[largest])
                    largest = left;

                if(right < storage.size() && storage[right] > storage[largest])
                    largest = right;

                if(largest != parent) {
                    swap(&storage[parent], &storage[largest]);
                    parent = largest;
                } else {
                    break; 
                }
            }

            return max_val;
        }
};     


int main(){


    heap *myheap=new heap();

    myheap->insert(95);
    myheap->insert(75);
    myheap->insert(80);
    myheap->insert(55);
    myheap->insert(60);
    myheap->insert(50);
    myheap->insert(65);

    myheap->display();

    myheap->delect();

    myheap->display();

    myheap->delect();

    myheap->display();

    return 0;
}


//-------------------------------------------------------------------------------------------------

//# =============================================================
/*  heapify */
//# =============================================================





// To heapify a subtree rooted 
function heapify(arr, n, i) {
    let largest = i;
    let l = 2 * i + 1; 
    let r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest !== i) {
        [arr[i], arr[largest]] = [arr[largest], arr[i]];

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from the given array
function buildHeap(arr) {
    const n = arr.length;
    
    // Index of last non-leaf node
    let startIdx = Math.floor(n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (let i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Driver Code
// Binary Tree Representation of input array
//             1
//           /    \
//         3        5
//       /  \     /  \
//     4      6  13  10
//    / \    / \
//   9   8  15 17
const arr = [1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17];
const n = arr.length;

// Build Max Heap
buildHeap(arr);

for (let i = 0; i < n; i++)
    process.stdout.write(arr[i] + " ");
console.log("\n");

// Final Heap Representation
//              17
//            /    \
//          15      13
//         /  \     / \
//        9     6  5   10
//       / \   / \
//      4   8 3   1



//-------------------------------------------------------------------------



//# =============================================================
/* QUICK SORT */
//# =============================================================





#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int arr[] = {5,2,8,1,9};
    int n = 5;

    quickSort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}


//--------------------------------------------------------------------------------------


//# =============================================================
/* MERGE SORT */
//# =============================================================





#include <stdio.h>

void merge(int arr[], int l, int m, int r){
    int i=l, j=m+1, k=0;
    int temp[100];

    while(i<=m && j<=r){
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=m) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];

    for(i=l, k=0; i<=r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int arr[] = {5,2,8,1,9};
    int n = 5;

    mergeSort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}


//-----------------------------------------------------------------------------------------------------------------------------

//# =============================================================
/* MERGE SORT */
//# =============================================================

#include <stdio.h>

void merge(int arr[], int l, int m, int r){
    int i=l, j=m+1, k=0;
    int temp[100];

    while(i<=m && j<=r){
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=m) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];

    for(i=l, k=0; i<=r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int arr[] = {5,2,8,1,9};
    int n = 5;

    mergeSort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}

//---------------------------------------------------------------------------------

//# =============================================================
/* N-QUEENS */
//# =============================================================





#include <stdio.h>
#define N 4

int board[N];

int isSafe(int row, int col){
    for(int i=0;i<row;i++)
        if(board[i] == col) return 0;

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        if(board[i]==j) return 0;

    for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++)
        if(board[i]==j) return 0;

    return 1;
}

void solve(int row){
    if(row == N){
        for(int i=0;i<N;i++)
            printf("%d ", board[i]);
        printf("\n");
        return;
    }

    for(int col=0;col<N;col++){
        if(isSafe(row,col)){
            board[row] = col;
            solve(row+1);
        }
    }
}

int main(){
    solve(0);
    return 0;
}



//-----------------------------------------------------------------------------------------------------------------------

//# =============================================================
/* DIJKSTRA */
//# =============================================================





#include <stdio.h>
#include <limits.h>

#define V 5

int minDist(int dist[], int visited[]){
    int min = INT_MAX, index;

    for(int i=0;i<V;i++){
        if(!visited[i] && dist[i] <= min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[V][V], int src){
    int dist[V], visited[V];

    for(int i=0;i<V;i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int count=0; count<V-1; count++){
        int u = minDist(dist, visited);
        visited[u] = 1;

        for(int v=0; v<V; v++){
            if(!visited[v] && graph[u][v] && dist[u]!=INT_MAX
               && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex   Distance\n");
    for(int i=0;i<V;i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main(){
    int graph[V][V] = {
        {0,10,0,0,5},
        {0,0,1,0,2},
        {0,0,0,4,0},
        {7,0,6,0,0},
        {0,3,9,2,0}
    };

    dijkstra(graph, 0);
    return 0;
}



//----------------------------------------------------------------------------------------------------

//# =============================================================
/* MATRIX CHAIN MULTIPLICATION */
//# =============================================================





#include <stdio.h>
#include <limits.h>

int main(){
    int p[] = {10, 20, 30, 40};
    int n = 3;

    int m[10][10];

    for(int i=1;i<=n;i++)
        m[i][i] = 0;

    for(int L=2; L<=n; L++){
        for(int i=1; i<=n-L+1; i++){
            int j = i+L-1;
            m[i][j] = INT_MAX;

            for(int k=i; k<j; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    printf("Minimum multiplications: %d", m[1][n]);
    return 0;
}


//---------------------------------------------------------------------------------------------------

//# =============================================================
/* KARATSUBA MULTIPLICATION */
//# =============================================================




#include <stdio.h>
#include <math.h>

long long karatsuba(long long x, long long y){
    if(x < 10 || y < 10)
        return x * y;

    int n = fmax(log10(x)+1, log10(y)+1);
    int m = n / 2;

    long long power = pow(10, m);

    long long x1 = x / power;
    long long x0 = x % power;
    long long y1 = y / power;
    long long y0 = y % power;

    long long z0 = karatsuba(x0, y0);
    long long z2 = karatsuba(x1, y1);
    long long z1 = karatsuba(x0 + x1, y0 + y1);

    return z2 * pow(power,2) + (z1 - z2 - z0) * power + z0;
}

int main(){
    long long x = 1234, y = 5678;

    printf("Result: %lld\n", karatsuba(x,y));
    return 0;
}



//---------------------------------------------------------------------------------------------------------------------------

//# =============================================================
/* GRAPH COLORING */
//# =============================================================





#include <stdio.h>

#define V 4

int isSafe(int graph[V][V], int color[], int v, int c){
    for(int i=0;i<V;i++){
        if(graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int solve(int graph[V][V], int m, int color[], int v){
    if(v == V) return 1;

    for(int c=1;c<=m;c++){
        if(isSafe(graph, color, v, c)){
            color[v] = c;
            if(solve(graph, m, color, v+1))
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main(){
    int graph[V][V] = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    int color[V] = {0};
    int m = 3;

    if(solve(graph, m, color, 0)){
        for(int i=0;i<V;i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
    } else {
        printf("No solution\n");
    }

    return 0;
}


//--------------------------------------------------------------------------------

//# =============================================================
/* 0/1 KNAPSACK (BACKTRACKING) */
//# =============================================================




#include <stdio.h>

int maxVal = 0;

void knapsack(int wt[], int val[], int n, int cap, int idx, int currW, int currV){
    if(currW > cap) return;

    if(currV > maxVal)
        maxVal = currV;

    if(idx == n) return;

    knapsack(wt, val, n, cap, idx+1, currW + wt[idx], currV + val[idx]);
    knapsack(wt, val, n, cap, idx+1, currW, currV);
}

int main(){
    int wt[] = {2,3,4,5};
    int val[] = {3,4,5,6};
    int n = 4, cap = 5;

    knapsack(wt, val, n, cap, 0, 0, 0);

    printf("Maximum value: %d\n", maxVal);
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------

//# =============================================================
/* HUFFMAN CODING */
//# =============================================================




#include <stdio.h>
#include <stdlib.h>

struct Node{
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* newNode(char ch, int freq){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

/* NOTE: Full heap implementation is long,
   so simplified demonstration below */

void printCodes(struct Node* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }

    if(root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }

    if(!root->left && !root->right){
        printf("%c: ", root->ch);
        for(int i=0;i<top;i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main(){
    struct Node* root = newNode('*',5);
    root->left = newNode('A',2);
    root->right = newNode('B',3);

    int arr[10];
    printCodes(root, arr, 0);

    return 0;
}



//-------------------------------------------------------------------------------------------------------------

//# =============================================================
/* PRIM'S MST */
//# =============================================================



#include <stdio.h>
#include <limits.h>

#define V 5

int minKey(int key[], int mst[]){
    int min = INT_MAX, index;

    for(int i=0;i<V;i++){
        if(!mst[i] && key[i] < min){
            min = key[i];
            index = i;
        }
    }
    return index;
}

void prim(int graph[V][V]){
    int parent[V], key[V], mst[V];

    for(int i=0;i<V;i++){
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i=0;i<V-1;i++){
        int u = minKey(key, mst);
        mst[u] = 1;

        for(int v=0;v<V;v++){
            if(graph[u][v] && !mst[v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for(int i=1;i<V;i++)
        printf("%d - %d\n", parent[i], i);
}

int main(){
    int graph[V][V] = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    prim(graph);
    return 0;
}



//------------------------------------------------------------------------------------------------------------------

//# =============================================================
/* KRUSKAL'S MST */
//# =============================================================




#include <stdio.h>
#include <stdlib.h>

struct Edge{
    int u,v,w;
};

int parent[10];

int find(int i){
    while(parent[i])
        i = parent[i];
    return i;
}

void unionSet(int a, int b){
    parent[a] = b;
}

int compare(const void* a, const void* b){
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int main(){
    struct Edge edges[] = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    int n = 4, e = 5;
    qsort(edges, e, sizeof(edges[0]), compare);

    for(int i=0;i<e;i++){
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if(u != v){
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            unionSet(u,v);
        }
    }

    return 0;
}



//-------------------------------------------------------------------------------------------------------------------------

//# =============================================================
/* LONGEST COMMON SUBSEQUENCE */
//# =============================================================




#include <stdio.h>
#include <string.h>

int max(int a, int b){
    return (a>b)?a:b;
}

int main(){
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";

    int m = strlen(X);
    int n = strlen(Y);

    int dp[20][20];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    printf("LCS Length: %d\n", dp[m][n]);
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------
