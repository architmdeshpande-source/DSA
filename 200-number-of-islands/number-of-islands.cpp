class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            pair<int, int> vis = q.front();
            q.pop();
            int newRow = vis.first;
            int newCol = vis.second;

            for(int i = -1; i<=1; i++){
                int drow = newRow + i;
                if(drow>=0 && drow<n && grid[drow][newCol] == '1' && !visited[drow][newCol]){
                    visited[drow][newCol] = 1;
                    q.push({drow, newCol});
                }
            }

            for(int j = -1; j<=1; j++){
                int dcol = newCol + j;
                if(dcol>=0 && dcol<m && grid[newRow][dcol] == '1' && !visited[newRow][dcol]){
                    visited[newRow][dcol] = 1;
                    q.push({newRow, dcol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return cnt;
    }
};