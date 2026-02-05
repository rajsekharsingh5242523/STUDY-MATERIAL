#include <iostream>
#include <vector>

using namespace std;

class heap{
    private:
        vector<int>storage={-1};

    public:
        
        void swap(int *x,int *y){
            int temp=*x;
            *x=*y;
            *y=temp;
            return;
        }

        void insert(int vertex){
            storage.push_back(vertex);

            cout<<"vertex: "<<vertex<<endl;
            int child_index=storage.size()-1;
            cout<<"child: "<<child_index<<endl;
            
            int parent_index=(child_index)/2;
            cout<<"parent: "<<parent_index<<endl;

            while(child_index > 1 && vertex>storage[parent_index]){
                swap(&storage[child_index],&storage[parent_index]);
                child_index=parent_index;
                parent_index=(child_index) / 2;
                cout <<"changed"<<endl;

            };
            cout<<"no changes"<<endl;
            return;
        }

        void display(){
            for(auto i :storage){
                cout << i <<' ';
            }
            cout << endl;
            return ;

        }

};      



int main(){


    heap *myheap=new heap();

    myheap->insert(99);
    myheap->insert(72);
    myheap->insert(58);
    myheap->insert(61);
    myheap->insert(100);

    myheap->display();


    return 0;
}