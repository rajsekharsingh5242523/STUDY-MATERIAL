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