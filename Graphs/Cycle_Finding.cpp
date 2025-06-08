// TLE
#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

void printPathRecur(int og, int u, vector<int>& parent){
    if(parent[u] != og){
        printPathRecur(og, parent[u], parent);
        cout << u + 1 << " ";
    }
    else{
        cout << u + 1 << " ";
    }
}

void Print_Path(int u, vector<int>& parent){
    int temp = parent[u];
    // vector<int> path;
    
    cout << u + 1 << " ";
    // if(u != parent[u]){
    //     while (temp != u){
    //         path.push_back(temp + 1);
    //         temp = parent[temp];
    //     }
    // }
    if(u != parent[u]){
        printPathRecur(u, parent[u], parent);
    }
    // for(int i = path.size() - 1; i >= 0; i--){
    //     cout << path[i] << " ";
    // }

    cout << u + 1 << " ";
}

int Bellman_Ford(int start,int n, vector<long long>& d, vector<vector<long long>>& edges){
        vector<int> parent(n, -1);
        d[start] = 0;
        bool has_changed = false;
        for(int i = 0; i < n; i++){
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                long long w = edge[2];
                if(d[u] != LLONG_MAX){
                    if(d[v] > d[u] + w){
                        has_changed = true;
                        d[v] = d[u] + w;
                        parent[v] = u;
                        if(i == n - 1){
                            cout << "YES" << endl;
                            Print_Path(u, parent);
                            return 1;
                        }
                    }
                }
            }
            if(!has_changed){
                return -1;
            }
            else{
                has_changed = 0;
            }
        }
    return -1;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> edges(m, vector<long long>(3, 0));
    for(int i = 0; i < m; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a - 1, b - 1, c};
    }
    
    int neg_cycle = 0;
    vector<long long> d(n, LLONG_MAX);
    for(int i = 0; i < n; i++){
        if(d[i] == LLONG_MAX){
            int temp = Bellman_Ford(i, n, d, edges);
            if(temp == 1){
                neg_cycle = 1;
                break;
            }
        }
    }
    if(!neg_cycle){
        cout << "NO";
    }

    return 0;
}