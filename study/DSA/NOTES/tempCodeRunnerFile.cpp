
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
    mygraph->add_vertex('1');
    mygraph->add_vertex('2'); 
    mygraph->add_vertex('3'); 
    mygraph->add_vertex('4'); 
    mygraph->add_vertex('5'); 
    mygraph->add_vertex('6'); 
    mygraph->add_vertex('7'); 


    mygraph->add_edge('1','2');
    mygraph->add_edge('1','3');
    mygraph->add_edge('1','4');
    mygraph->add_edge('2','3');
    mygraph->add_edge('3','4');
    mygraph->add_edge('3','5');
    mygraph->add_edge('4','1');
    mygraph->add_edge('4','3');
    mygraph->add_edge('5','6');
    mygraph->add_edge('5','7');

    mygraph->display();

    //mygraph->remove_edge('A','D');
    //mygraph->remove_edge('C','D');
    //mygraph->remove_edge('B','D');

    //mygraph->display();
    mygraph->BFS('1');
    mygraph->DFS('1');

    return 0;
}