#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

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

};



int main (){
    cout <<"hello world"<<endl;

    graph *mygraph = new graph();
    mygraph->add_vertex('A');
    mygraph->add_vertex('B'); 
    mygraph->add_vertex('C'); 
    mygraph->add_vertex('D'); 

    mygraph->add_edge('A','B');
    mygraph->add_edge('A','C');
    mygraph->add_edge('A','D');
    mygraph->add_edge('B','D');
    mygraph->add_edge('C','D');

    mygraph->display();

    mygraph->remove_edge('A','D');
    mygraph->remove_edge('C','D');
    mygraph->remove_edge('B','D');

    mygraph->display();

    return 0;
}

