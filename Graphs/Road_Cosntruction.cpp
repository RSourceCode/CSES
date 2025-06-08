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

void Merge(int u, int v, vector<int>& parent, vector<int>& height,vector<int>& size){
    u = Find(u, parent); v = Find(v, parent);

    // cout << size[u] << " " << size[v] << endl;

    if(height[u] < height[v]){
        size[v] += size[u];
        parent[u] = v;
    }  
    else if(height[u] > height[v]){
        size[u] += size[v];
        parent[v] = u; 
    }
    else{
        parent[u] = v; 
        size[v] += size[u];
        height[v]++;
    }
    // cout << size[u] << " " << size[v] << endl;
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
    vector<int> parent(n + 1, 0);
    vector<int> height(n + 1, 0);
    vector<int> size(n + 1, 1);

    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    int max_size = 0;
    int num_com = n;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(Find(u, parent) != Find(v, parent)){
            Merge(u, v, parent, height, size);
            if(size[Find(u, parent)] > max_size) max_size = size[Find(u, parent)];
            if(size[Find(v, parent)] > max_size) max_size = size[Find(v, parent)];
            num_com--;
        }
        cout << num_com << " " << max_size << endl;
    }

    #ifndef ONLINE_JUDGE
        cerr<<fixed<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
    
    return 0;
}