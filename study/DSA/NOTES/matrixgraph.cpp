#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
        cout << "Edge " << (char)tolower(u)
             << (directed?" -> ":" -- ")
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

// ── helpers ──────────────────────────────────────────────────
const string SEP = string(40, '-');

bool askDirected(){
    int t;
    cout << "  1. Undirected\n  2. Directed\n  Type: ";
    cin >> t;
    return (t == 2);
}

void matrixMenu(){
    cout << "\n" << SEP
         << "\n  1. Add Edge"
         << "\n  2. Display"
         << "\n  3. Degree"
         << "\n  4. DFS"
         << "\n  5. BFS"
         << "\n  0. Exit"
         << "\n" << SEP
         << "\n  Choice: ";
}

// ── main ─────────────────────────────────────────────────────
int main(){
    int sz;
    cout << "Number of vertices: ";
    cin >> sz;

    bool dir = askDirected();
    GraphMatrix g(sz, dir);

    cout << "Enter " << sz << " vertex labels:\n  ";
    for(int i = 0; i < sz; i++){
        char x; cin >> x;
        g.set_vertex(i, x);
    }
    cout << "\nMatrix Graph (" << (dir ? "Directed" : "Undirected") << ") created.\n";

    int ch; char u, v;
    while(true){
        matrixMenu();
        cin >> ch;
        if(ch == 0){ cout << "\nGoodbye!\n"; break; }
        switch(ch){
            case 1:
                cout << "  Edge (u v): "; cin >> u >> v;
                g.add_edge(u, v);
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout << "  Vertex: "; cin >> u;
                cout << "  Degree: " << g.degree(u) << "\n";
                break;
            case 4:
                cout << "  Start: "; cin >> u;
                g.DFS(u);
                break;
            case 5:
                cout << "  Start: "; cin >> u;
                g.BFS(u);
                break;
            default:
                cout << "  Invalid option.\n";
        }
    }
    return 0;
}