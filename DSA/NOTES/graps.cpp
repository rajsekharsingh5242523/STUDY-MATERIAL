#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class graph{
    private:
        unordered_map<char,unordered_set<char>>adjlist;

    public:

        void add_vertex(char vertex){
            if(adjlist.count(vertex)==0){
                adjlist.insert({vertex})
                return 1;
            };
            return 0;
        }


        void 




}


int main (){


    return 0;
}
