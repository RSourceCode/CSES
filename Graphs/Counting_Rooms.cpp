#include<iostream>
#include<vector>

using namespace std;

void DFS(pair<int, int> start, vector<vector<char>> &grid){
    int x = start.first;
    int y = start.second;
    grid[x][y] = '#';
    vector<pair<int, int>> children = {{x + 1, y}, {x - 1, y}, {x, y - 1}, {x, y + 1}};
    for(auto child : children){
        if(0 <= child.first && child.first <  grid.size() && 0 <= child.second && child.second <  grid[0].size() && grid[child.first][child.second] == '.'){
            grid[child.first][child.second] = '#';
            DFS(child, grid);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int num_rooms = 0;
    vector<vector<char>> grid(n, vector<char>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                DFS({i, j}, grid);
                num_rooms ++;
            }
        }
    }

    cout << num_rooms;

    return 0;
}