#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

string BFS(pair<int, int> start, vector<vector<char>>& grid){
    queue<pair<int, int>> q;
    queue<int> n;
    grid[start.first][start.second] = '#';
    q.push(start);
    n.push(0);

    string path = "";
    vector<vector<pair<int, int>>> parent(grid.size(), vector<pair<int, int>>(grid[0].size(), {0,0}));

    while(!q.empty()){
        pair<int, int> vert = q.front();
        int num = n.front();
        q.pop();
        n.pop();
        int x = vert.first;
        int y = vert.second;
        grid[x][y] = '#';

        vector<tuple<int ,int, char>> children = {{x + 1, y, 'D'}, {x - 1, y, 'U'}, {x, y + 1, 'R'}, {x, y - 1, 'L'}};
        for(auto child : children){
            int _x = get<0>(child);
            int _y = get<1>(child);

            if(0 <= _x && _x < grid.size() && 0 <= _y && _y < grid[0].size() && grid[_x][_y] != '#'){
                if(grid[_x][_y] == 'B'){
                    grid[_x][_y] = '#';
                    cout << "YES" << endl << num + 1 << endl;
                    parent[_x][_y] = {x, y};
                    path += get<2>(child);
                    pair<int, int> temp = parent[_x][_y];
                    while(temp != start){
                        int temp_x = temp.first - parent[temp.first][temp.second].first;
                        int temp_y = temp.second - parent[temp.first][temp.second].second;
                        if(temp_x == 0){
                            if(temp_y == 1){
                                path += 'R';
                            }
                            else{
                                path += 'L';
                            }
                        }
                        else if(temp_y == 0){
                            if(temp_x == 1){
                                path += 'D';
                            }
                            else{
                                path += 'U';
                            }
                        }
                        temp = parent[temp.first][temp.second];
                    }
                    break;
                }
                else if(grid[_x][_y] == '.'){
                    q.push({_x, _y});
                    parent[_x][_y] = {x, y};
                    grid[_x][_y] = '#';
                    n.push(num + 1);
                }
            }
        }
    }

    return path;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m, 0));
    pair<int ,int> start;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start.first = i;
                start.second = j;
            }
        }
    }

    string path = BFS(start, grid);
    if(path == ""){
        cout << "NO";
    }
    else{
        for(int i = path.length() - 1; i >= 0; i--){
            cout << path[i];
        }
    }

    return 0;
}