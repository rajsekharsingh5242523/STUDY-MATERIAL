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