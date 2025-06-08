#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Print_Path(pair<int, int> start, vector<vector<pair<int, int>>>& parents){
    string path = "";
    pair<int, int> vert = start;
    while(vert.first != 0 && vert.first != parents.size() - 1 && vert.second != 0 && vert.second != parents[0].size() - 1){
        int y = parents[vert.first][vert.second].first - vert.first;
        int x = parents[vert.first][vert.second].second - vert.second;
        if(x == 1){
            path += "R";
        }
        else if(x == -1){
            path += "L";
        }
        else if(y ==1){
            path += "D";
        }
        else{
            path += "U";
        }
        vert = parents[vert.first][vert.second];
    }       
    cout << path;
}

bool BFS(pair<int, int> start, vector<vector<char>> grid, vector<vector<pair<int, int>>> parents){
    queue<pair<int ,int>> vertices;
    queue<int> nums;

    vertices. push(start);
    nums.push(0);
    while(!vertices.empty()){
        pair<int, int> v = vertices.front();
        int n = nums.front();
        vertices.pop();
        nums.pop();
        int y = v.first;
        int x = v.second;
        grid[y][x] = '#';
        vector<pair<int, int>> moves = {{y - 1, x}, {y + 1, x}, {y, x - 1}, {y, x + 1}};
        for(auto p : moves){
            int _y = p.first;
            int _x = p.second;
            if(_y >= 0 && _y < grid.size() && _x >= 0 && _x < grid[0].size() && grid[_y][_x] != '#'){
                if(grid[_y][_x] == '.'){
                    grid[_y][_x] = '#';
                    vertices.push(p);
                    nums.push(n + 1);
                    parents[_y][_x] = v;
                    continue;
                }
                else if(grid[_y][_x] == 'M'){
                    return false;
                }
                else if(grid[_y][_x] == 'A'){
                    for(auto pa : moves){
                        if(pa.first >= 0 && pa.first < grid.size() && pa.second >= 0 && pa.second < grid[0].size() && grid[pa.first][pa.second] == 'M'){
                            return false;
                        }
                    }
                    cout <<"YES"<< endl;
                    cout << n + 1 << endl;
                    parents[_y][_x] = v;
                    Print_Path({_y, _x}, parents);
                    return true;
                }
            }
        }
    }


    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n, m;
    int s_x, s_y;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m ,0));
    vector<pair<int, int>> boundaries;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                if(grid[i][j] == '.'){
                    boundaries.push_back({i, j});
                }
                if(grid[i][j] == 'A'){
                    s_x = j;
                    s_y = i;
                }
            }
        }
    }

    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m, {-1, -1}));
    bool found = 0;
    
    for(auto s : boundaries){
        if(found){
            break;
        }
        else{
            found = BFS(s, grid, parents);
        }
    }
    if(s_x == 0 || s_x == n - 1 || s_y == 0 || s_y == m - 1){
        cout << "YES" << endl << 0;
        found = 1;
    }
    if(!found){
        cout << "NO";
    }

    return 0;
}