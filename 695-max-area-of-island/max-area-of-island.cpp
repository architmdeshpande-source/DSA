class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int dr[4] = {0,0,-1,1};
        int dc[4] = {1,-1,0,0};
        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0) continue;
                q.push({i, j});
                grid[i][j] = 0;
                int cnt = 1;
                while(!q.empty()){
                    auto [r, c] = q.front();
                    q.pop();
                    for(int d = 0; d<4; d++){
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                            q.push({nr, nc});
                            grid[nr][nc] = 0;
                            cnt++;
                        }
                    }
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};