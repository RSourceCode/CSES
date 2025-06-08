#include<iostream>
#include<chrono>
#include<vector> 
#include<algorithm>

using namespace std;

int Find(int u, vector<int>& parent){
    int temp = u;
    while(parent[temp] != temp) temp = parent[temp];
    return temp;
}

void Merge(int u, int v, vector<int>& height, vector<int>& parent){
    u = Find(u, parent); v = Find(v, parent);
    if(height[u] < height[v]) parent[u] = v;
    else if(height[u] > height[v]) parent[v] = u;
    else{
        parent[u] = v;
        height[v]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m + 1, vector<int>(3));
    for(int i = 1; i <= m; i++){
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }

    sort(edges.begin(), edges.end());
    vector<int> parent(n + 1);
    vector<int> height(n + 1, 0);

    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    long long ans = 0;
    int count = 0;
    for(auto edge : edges){
        int u = edge[1];
        int v = edge[2];
        if(Find(u, parent) !=  Find(v, parent)){
            Merge(u, v, height, parent);
            ans += edge[0];
            count++;
            if(count == n - 1){
                break;
            }
        }
    }
    if(count >= n - 1){
        cout << ans;
    }
    else{
        cout << "IMPOSSIBLE";
    }

    #ifndef ONLINE_JUDGE
        cerr<<fixed<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
    
    return 0;
}