/* INTERVIE QUESTION */  

/*AS O(N*2) TO O(N) FOR SERCH COMMON ELEMENT IN THE TWO GIVEN ARRAY*/


#include <iostream>
using namespace std;

class Node{
    public:
        int key;
        int value;
        Node *next;

        Node(int user,int val){
            key=user;
            value=val;
            next=nullptr;
        }
};




class hash_table{
    private:
        static const int SIZE=10;
        Node *storage[SIZE];

    public:

        hash_table(){           /*So each element contains random garbage memory.Even though you assign when inserting, the other buckets still contain junk pointers.*/
            for(int i=0;i<SIZE;i++){
                storage[i] = nullptr;
            }
        }

        int hash_function(int key){
            return (key%SIZE);
        }

        void set(int key,int value){
            int index=hash_function(key);
            Node *newnode=new Node(key,value);
            Node *temp=storage[index];  /*temp is sometimes not NULL → so while(temp!=nullptr) runs → random memory → eventually matches garbage key → returns value → FOUND.*/
            if(storage[index] == nullptr){
                storage[index] = newnode;
            }else{
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                temp->next=newnode;
            }
        }


        int get(int check){
            int index=hash_function(check);
            Node *temp=storage[index];
            while(temp!=nullptr){
                if(temp->key==check){
                   return temp->value;
                }else{
                    temp=temp->next;
                }
            }
            return 0;
        };

};




int main(){

    int max;
    cout <<"that size of array : ";
    cin>>max;
    int arr1[max],arr2[max];

    int user;
    for(int i=0;i<max;i++){
        cout <<"what is value for arr1 :";
        cin >>arr1[i];
        cout <<"what is value for arr2 :";
        cin >>arr2[i];
    }

    hash_table *myhashtable=new hash_table();
    for(int i=0;i<max;i++){
        myhashtable->set(arr1[i],1);
    }

    int search;
    for(int i=0;i<max;i++){
        int holder=arr2[i];
        if(myhashtable->get(holder)){
            cout <<"FOUND"<<endl;
        }else{
            cout << "NOT FOUND "<<endl;
        };
    }

    return 0;

};


/* REVERSE A LINKED LIST*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode *curr=head;
            ListNode *prev=nullptr;
            while(curr!=nullptr){
                ListNode *ahead=curr->next;
                curr->next=prev;
                prev=curr;
                curr=ahead;
            };
            head=prev;
            
            cout <<prev->val<<endl;
            return head;
        };
};


/* LINKED LIST CYCLE*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // 1 step
            fast = fast->next->next;    // 2 steps

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
