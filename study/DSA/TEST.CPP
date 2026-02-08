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



int main(){

    linkedList *mylist=new linkedList(1);
    mylist->append(2);
    mylist->append(3);
    mylist->append(4);
    mylist->append(5);
    mylist->printList();

    cout <<mylist->findmiddle();


    return 0;
}


