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



/* queue*/

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



/*DEQUEUE*/

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


/* circular queue */

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




//DEQUEUE USING CIRCULAR QUEUE


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
