#include<iostream>
#include<vector>

using namespace std;

void DFS(int start, vector<vector<int>>& adj, vector<int>& visited, vector<int>& parent, bool& back_edge_found){
    visited[start] = 1;
    for(auto c : adj[start]){
        
        if(!visited[c]){
            parent[c] = start;
            visited[c] = 1;
            DFS(c, adj, visited, parent, back_edge_found);
            continue;
        }
        if(back_edge_found){
            return;
        }

        if(parent[start] != c && visited[c]){
            // Back Edge detected
            back_edge_found = 1;
            parent[c] = start;
            int temp = parent[c];
            int cycle_length = 0;
            while(temp != c){
                cycle_length++;
                temp = parent[temp];
            }
            cout << cycle_length + 2 << endl;

            temp = parent[c];

            cout << c + 1;

            while(temp != c){
                cout << " " << temp  + 1 ;
                temp = parent[temp];
            }
            cout << " " << c + 1;

            return;
        }
    }    

}

int main(){

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n ,m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n, vector<int>(0, 0));

    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vector<int> visited(n, 0);
    vector<int> parent(n, -1);
    bool back_edge_found = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(i, adj, visited, parent, back_edge_found);
        }
    }
    if(!back_edge_found){
        cout << "IMPOSSIBLE";
    }
    
    return 0;
}