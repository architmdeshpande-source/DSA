class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,1,-1};
        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] != '1') continue;

                grid[i][j] = '0';
                cnt++;
                queue<pair<int, int>> q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int, int> t = q.front();
                    q.pop();
                    int row = t.first;
                    int col = t.second;
                    for(int d = 0; d<4; d++){
                        int newRow = row + dr[d];
                        int newCol = col + dc[d];

                        if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol] == '1'){
                            q.push({newRow, newCol});
                            grid[newRow][newCol] = '0';
                        }
                    }
                }
            }
        }
        return cnt;
    }
};