#include <iostream>
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

    myhashtable->set("nails",4);

    myhashtable->set("tile",5);

    myhashtable->set("lumber",6);

    myhashtable->printTable();

    cout << myhashtable->get("nails")<< endl;

    cout << myhashtable->get("bolt")<< endl;
}


