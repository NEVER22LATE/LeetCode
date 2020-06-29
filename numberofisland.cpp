
class Solution {
public:
    bool vis[1001][1001];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m; 
    bool isValid(int x, int y ) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        //cout << i <<" "<< j << endl; 
        vis[i][j] = true; 
        for(int k = 0; k < 4; k++) {
            int next_x = i + dx[k];
            int next_y = j + dy[k];
            if(!isValid(next_x, next_y)) continue;
            if(grid[next_x][next_y] == '1' && vis[next_x][next_y] == false) {
                dfs(grid, next_x, next_y); 
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size(); 
        if(n != 0)
        m = grid[0].size(); 
        int cnt = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && vis[i][j] == false) {
                    dfs(grid, i, j); 
                    cnt++; 
                }
            }
        }
        return cnt; 
    }
};
