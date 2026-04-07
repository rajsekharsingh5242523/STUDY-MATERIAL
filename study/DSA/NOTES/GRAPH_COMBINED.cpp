#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

/* =========================
ADJACENCY LIST GRAPH
========================= */
class GraphList {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, char> parent;
    bool directed;                         

public:
    GraphList(bool isDirected = false) : directed(isDirected) {}

    /* ── ADD ─────────────────────────────── */
    void add_vertex(char v){
        v = tolower(v);
        if(adj.count(v) == 0){ 
            adj[v];
            cout << "Vertex '" << v << "' added.\n";
        }else{
            cout << "Vertex already exists.\n";
        };
        return; 
    }

    void add_edge(char u, char v){
        u = tolower(u);
        v = tolower(v);
        if(adj.count(u) !=0 && adj.count(v) != 0){
            adj.at(u).insert(v);
            if(directed == false){
                adj[v].insert(u);
            }   
        }                   
            
        cout << "One or both vertices not found.\n";
        cout << "Edge " << u << (directed?" -> ":" -- ") << v << " added.\n";

        return;

    }

    /* ── REMOVE ──────────────────────────── */

    void remove_edge(char u, char v){
        u = tolower(u); v = tolower(v);
        if(adj.count(u) !=0 && adj.count(v) !=0){
            adj[u].erase(v);
            if(directed == false){
                adj[v].erase(u);
            }
        }else{
            cout << "One or both vertices not found.\n";
        }
        cout << "Edge " << u << " -- " << v << " removed.\n";
        return;
    }

    void remove_vertex(char v){
        v = tolower(v);
        if(adj.count(v) == 0){ 
            cout << "Vertex not found.\n"; 
            return; 
        };

        for(auto neighbour:adj.at(v)){
            adj[neighbour].erase(v);
        }
        adj.erase(v);
        cout << "Vertex '" << v << "' and all its edges removed.\n";
    }

    /* ── DISPLAY ─────────────────────────── */
    void display(){
        if(adj.empty()){ cout << "(empty graph)\n"; return; }
        string gtype = directed ? "Directed" : "Undirected";
        cout << "\nAdjacency List [" << gtype << "]:\n";
        for(auto& k : adj){
            cout << "  " << k.first << " : [ ";
            if(k.second.empty()) cout << "(none)";
            else for(auto n : k.second) cout << n << " ";
            cout << "]\n";
        }
    }

    /* ── DFS ─────────────────────────────── */
    void dfs_util(char v, unordered_set<char>& vis){
        cout << v << " ";
        vis.insert(v);
        for(auto n : adj[v])
            if(vis.count(n) == 0){
                dfs_util(n, vis);
            }   
    }

    void DFS(char s){
        s = tolower(s);
        if(!adj.count(s)){ cout << "Vertex not found.\n"; return; }
        unordered_set<char> vis;
        cout << "DFS from '" << s << "': ";
        dfs_util(s, vis);
        cout << "\n";
    }

    /* ── BFS ─────────────────────────────── */
    void BFS(char s){
        s = tolower(s);
        if(!adj.count(s)){ cout << "Vertex not found.\n"; return; }
        unordered_set<char> vis;
        queue<char> q;
        q.push(s); vis.insert(s);
        cout << "BFS from '" << s << "': ";
        while(!q.empty()){
            char v = q.front(); 
            q.pop();
            cout << v << " ";
            for(auto n : adj[v])
                if(!vis.count(n)){ vis.insert(n); q.push(n); }
        }
        cout << "\n";
    }

    /* ── SEARCH ──────────────────────────── */
    bool search_vertex(char v){ return adj.count(tolower(v)); }

    bool search_edge(char u, char v){
        u = tolower(u); v = tolower(v);
        if(!adj.count(u)) return false;
        return adj[u].count(v);
    }

    /* ── DEGREE ──────────────────────────── */
    int degree(char v){
        v = tolower(v);
        if(adj.count(v)) return adj[v].size();
        return -1;
    }

    /* ── GRAPH PROPERTIES ────────────────── */
    void dfs_conn(char v, unordered_set<char>& vis){
        vis.insert(v);
        for(auto n : adj[v])
            if(!vis.count(n))
                dfs_conn(n, vis);
    }

    bool is_connected(){
        if(adj.empty()) return true;
        unordered_set<char> vis;
        dfs_conn(adj.begin()->first, vis);
        return vis.size() == adj.size();
    }

    bool self_loop(){
        for(auto& k : adj)
            if(k.second.count(k.first))
                return true;
        return false;
    }

    /* ── CYCLE DETECTION ─────────────────── */

    // Union-Find cycle (undirected only)
    char uf_find(char v){
        if(parent[v] == v) return v;
        return parent[v] = uf_find(parent[v]);
    }

    void uf_union(char a, char b){
        parent[uf_find(a)] = uf_find(b);
    }

    bool cycle_union(){
        for(auto& k : adj) parent[k.first] = k.first;
        for(auto& k : adj){
            for(auto n : k.second){
                if(k.first < n){
                    char p1 = uf_find(k.first);
                    char p2 = uf_find(n);
                    if(p1 == p2) return true;
                    uf_union(p1, p2);
                }
            }
        }
        return false;
    }

    // Directed cycle detection using recursion stack DFS
    bool cycle_dir_util(char v, unordered_set<char>& vis,
                                unordered_set<char>& recStack){
        vis.insert(v);
        recStack.insert(v);
        for(auto n : adj[v]){
            if(!vis.count(n)){
                if(cycle_dir_util(n, vis, recStack))
                    return true;
            } else if(recStack.count(n)){   // back edge in current path = cycle
                return true;
            }
        }
        recStack.erase(v);
        return false;
    }

    bool cycle_directed(){
        unordered_set<char> vis, recStack;
        for(auto& k : adj)
            if(!vis.count(k.first))
                if(cycle_dir_util(k.first, vis, recStack))
                    return true;
        return false;
    }

    // Unified entry point — picks the right method based on graph type
    void detect_cycle(){
        bool result;
        if(directed){
            result = cycle_directed();
            cout << "Cycle (DFS recStack): " << (result ? "Yes" : "No") << "\n";
        } else {
            result = cycle_union();
            cout << "Cycle (Union-Find): " << (result ? "Yes" : "No") << "\n";
        }
    }
};


/* =========================
WEIGHTED GRAPH
========================= */
class WeightedGraph {
    unordered_map<char, vector<pair<char,int>>> adj;
    bool directed;

public:
    WeightedGraph(bool isDirected = false) : directed(isDirected) {}

    void add_vertex(char v){
        v = tolower(v);
        if(adj.count(v)){ cout << "Vertex already exists.\n"; return; }
        adj[v];
        cout << "Vertex '" << v << "' added.\n";
    }

    void add_edge(char u, char v, int w){
        u = tolower(u); v = tolower(v);
        if(!adj.count(u) || !adj.count(v)){
            cout << "One or both vertices not found.\n"; return;
        }
        adj[u].push_back({v, w});
        if(!directed)
            adj[v].push_back({u, w});
        cout << "Edge " << u << (directed?" -> ":" -- ") << v
            << " (weight=" << w << ") added.\n";
    }

    void display(){
        if(adj.empty()){ cout << "(empty graph)\n"; return; }
        string gtype = directed ? "Directed" : "Undirected";
        cout << "\nWeighted Adjacency List [" << gtype << "]:\n";
        for(auto& k : adj){
            cout << "  " << k.first << " : [ ";
            if(k.second.empty()) cout << "(none)";
            else for(auto& p : k.second)
                cout << "(" << p.first << "," << p.second << ") ";
            cout << "]\n";
        }
    }
};


/* =========================
MATRIX GRAPH
========================= */
class GraphMatrix {
    vector<vector<int>> mat;
    vector<char> ver;
    int n;
    bool directed;

public:
    GraphMatrix(int size, bool isDirected = false)
        : n(size), directed(isDirected),
        mat(size, vector<int>(size, 0)),
        ver(size, '?') {}

    void set_vertex(int i, char v){ ver[i] = tolower(v); }

    int index(char v){
        v = tolower(v);
        for(int i = 0; i < n; i++)
            if(ver[i] == v) return i;
        return -1;
    }

    void add_edge(char u, char v){
        int i = index(u), j = index(v);
        if(i == -1 || j == -1){ cout << "Vertex not found.\n"; return; }
        mat[i][j] = 1;
        if(!directed) mat[j][i] = 1;
        cout << "Edge " << (char)tolower(u)<< (directed?" -> ":" -- ") 
        << (char)tolower(v) << " added.\n";
    }

    void display(){
        cout << "\nAdjacency Matrix:\n    ";
        for(int j = 0; j < n; j++) cout << ver[j] << " ";
        cout << "\n";
        for(int i = 0; i < n; i++){
            cout << "  " << ver[i] << " ";
            for(int j = 0; j < n; j++) cout << mat[i][j] << " ";
            cout << "\n";
        }
    }

    int degree(char v){
        int i = index(v);
        if(i == -1){ cout << "Vertex not found.\n"; return -1; }
        int d = 0;
        for(int j = 0; j < n; j++) if(mat[i][j]) d++;
        return d;
    }

    void dfs_util(int v, vector<bool>& vis){
        vis[v] = true;
        cout << ver[v] << " ";
        for(int i = 0; i < n; i++)
            if(mat[v][i] == 1 && vis[i] == false)
                dfs_util(i, vis);
    }

    void DFS(char s){
        int start = index(s);
        if(start == -1){ cout << "Vertex not found.\n"; return; }
        vector<bool> vis(n, false);
        cout << "DFS from '" << (char)tolower(s) << "': ";
        dfs_util(start, vis);
        cout << "\n";
    }

    void BFS(char s){
        int start = index(s);
        if(start == -1){ cout << "Vertex not found.\n"; return; }
        vector<bool> vis(n, false);
        queue<int> q;
        vis[start] = true;
        q.push(start);
        cout << "BFS from '" << (char)tolower(s) << "': ";
        while(!q.empty()){
            int u = q.front(); q.pop();
            cout << ver[u] << " ";
            for(int i = 0; i < n; i++)
                if(mat[u][i] == 1 && !vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
        }
        cout << "\n";
    }
};



const string SEP = string(42, '-');

void printMainMenu(){
    cout << "\n" << SEP
        << "\n 1. List Graph"
        << "\n 2. Matrix Graph"
        << "\n 3. Weighted Graph"
        << "\n 0. Exit"
        << "\n" << SEP
        << "\nChoice: ";
}

bool askDirected(){
    int t;
    cout << " 1. Undirected\n 2. Directed\nType: ";
    cin >> t;
    return (t == 2);
}

void listMenu(){ cout
    << "\n" << SEP
    << "\n 1.  Add Vertex"
    << "\n 2.  Add Edge"
    << "\n 3.  Remove Edge"        // FIX 2
    << "\n 4.  Remove Vertex"      // FIX 3
    << "\n 5.  Display"
    << "\n 6.  DFS"
    << "\n 7.  BFS"
    << "\n 8.  Search Vertex"
    << "\n 9.  Search Edge"
    << "\n 10. Degree"
    << "\n 11. Connected?"
    << "\n 12. Self Loop?"
    << "\n 13. Detect Cycle"       // FIX 4
    << "\n 0.  Back"
    << "\n" << SEP
    << "\nChoice: ";
}

void matrixMenu(){ cout
    << "\n" << SEP
    << "\n 1. Add Edge"
    << "\n 2. Display"
    << "\n 3. Degree"
    << "\n 4. DFS"                 // FIX 5
    << "\n 5. BFS"                 // FIX 5
    << "\n 0. Back"
    << "\n" << SEP
    << "\nChoice: ";
}

void weightedMenu(){ cout
    << "\n" << SEP
    << "\n 1. Add Vertex"
    << "\n 2. Add Edge (with weight)"
    << "\n 3. Display"
    << "\n 0. Back"
    << "\n" << SEP
    << "\nChoice: ";
}


/* =========================
MAIN
========================= */
int main(){
    int choice;
    while(true){
        printMainMenu();
        cin >> choice;
        if(choice == 0) break;

        /* ── LIST GRAPH ─────────────────── */
        if(choice == 1){
            bool dir = askDirected();
            GraphList g(dir);
            cout << "\nList Graph (" << (dir?"Directed":"Undirected") << ") created.\n";

            int ch; char u, v;
            while(true){
                listMenu();
                cin >> ch;
                if(ch == 0) break;
                switch(ch){
                    case 1:
                        cout << "Vertex: "; cin >> u;
                        g.add_vertex(u);
                        break;
                    case 2:
                        cout << "Edge (u v): "; cin >> u >> v;
                        g.add_edge(u, v);
                        break;
                    case 3:                         // FIX 2
                        cout << "Remove edge (u v): "; cin >> u >> v;
                        g.remove_edge(u, v);
                        break;
                    case 4:                         // FIX 3
                        cout << "Remove vertex: "; cin >> u;
                        g.remove_vertex(u);
                        break;
                    case 5:  g.display();           break;
                    case 6:
                        cout << "Start: "; cin >> u;
                        g.DFS(u);
                        break;
                    case 7:
                        cout << "Start: "; cin >> u;
                        g.BFS(u);
                        break;
                    case 8:
                        cout << "Vertex: "; cin >> u;
                        cout << (g.search_vertex(u) ? "Found\n" : "Not Found\n");
                        break;
                    case 9:
                        cout << "Edge (u v): "; cin >> u >> v;
                        cout << (g.search_edge(u,v) ? "Edge exists\n" : "No such edge\n");
                        break;
                    case 10:
                        cout << "Vertex: "; cin >> u;
                        cout << "Degree: " << g.degree(u) << "\n";
                        break;
                    case 11:
                        cout << (g.is_connected() ? "Connected\n" : "Not Connected\n");
                        break;
                    case 12:
                        cout << (g.self_loop() ? "Self loop exists\n" : "No self loop\n");
                        break;
                    case 13:                        // FIX 4
                        g.detect_cycle();
                        break;
                    default: cout << "Invalid option.\n";
                }
            }
        }

        /* ── MATRIX GRAPH ───────────────── */
        else if(choice == 2){
            int sz;
            cout << "Number of vertices: "; cin >> sz;
            bool dir = askDirected();
            GraphMatrix g(sz, dir);

            cout << "Enter " << sz << " vertex labels:\n";
            for(int i = 0; i < sz; i++){
                char x; cin >> x;
                g.set_vertex(i, x);
            }
            cout << "\nMatrix Graph (" << (dir?"Directed":"Undirected") << ") created.\n";

            int ch; char u, v;
            while(true){
                matrixMenu();
                cin >> ch;
                if(ch == 0) break;
                switch(ch){
                    case 1:
                        cout << "Edge (u v): "; cin >> u >> v;
                        g.add_edge(u, v);
                        break;
                    case 2: g.display();             break;
                    case 3:
                        cout << "Vertex: "; cin >> u;
                        cout << "Degree: " << g.degree(u) << "\n";
                        break;
                    case 4:                          // FIX 5
                        cout << "Start: "; cin >> u;
                        g.DFS(u);
                        break;
                    case 5:                          // FIX 5
                        cout << "Start: "; cin >> u;
                        g.BFS(u);
                        break;
                    default: cout << "Invalid option.\n";
                }
            }
        }

        /* ── WEIGHTED GRAPH ─────────────── */
        else if(choice == 3){
            bool dir = askDirected();
            WeightedGraph g(dir);
            cout << "\nWeighted Graph (" << (dir?"Directed":"Undirected") << ") created.\n";

            int ch, w; char u, v;
            while(true){
                weightedMenu();
                cin >> ch;
                if(ch == 0) break;
                switch(ch){
                    case 1:
                        cout << "Vertex: "; cin >> u;
                        g.add_vertex(u);
                        break;
                    case 2:
                        cout << "Edge (u v weight): "; cin >> u >> v >> w;
                        g.add_edge(u, v, w);
                        break;
                    case 3: g.display();              break;
                    default: cout << "Invalid option.\n";
                }
            }
        }

        else { cout << "Invalid choice.\n"; }
    }

    cout << "\nGoodbye!\n";
    return 0;
}