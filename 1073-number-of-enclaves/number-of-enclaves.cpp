class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        grid[r][c] = 0;

        if(r+1 < n-1 && grid[r+1][c] == 1) dfs(r+1, c, grid);
        if(r-1 > 0 && grid[r-1][c] == 1) dfs(r-1, c, grid);
        if(c+1 < m-1 && grid[r][c+1] == 1) dfs(r, c+1, grid);
        if(c-1 > 0 && grid[r][c-1] == 1) dfs(r, c-1, grid);

        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int a = 0;
        for(int j = 0; j<m; j++){
            if(grid[a][j] == 1){
                dfs(a,j,grid);
            }
        }

        a = n-1;
        for(int j = 0; j<m; j++){
            if(grid[a][j] == 1){
                dfs(a,j,grid);
            }
        }

        int b = 0;
        for(int j = 0; j<n; j++){
            if(grid[j][b] == 1){
                dfs(j,b,grid);
            }
        }

        b = m-1;
        for(int j = 0; j<n; j++){
            if(grid[j][b] == 1){
                dfs(j,b,grid);
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};