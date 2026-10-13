class Solution {
private: 
    bool hasFreshOranges(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) return true;
            }
        }
        return false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(!hasFreshOranges(grid)) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        queue<pair<int, int>> q;
        int dr[4] = {0,0,-1,1};
        int dc[4] = {1,-1, 0, 0};

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(!q.empty()){
                    int sz = q.size();
                    time++;
                    for(int k = 0; k<sz; k++){
                        pair<int, int> t = q.front();
                        q.pop();
                        int r = t.first;
                        int c = t.second;
                        for(int d = 0; d<4; d++){
                            int nr = r + dr[d];
                            int nc = c + dc[d];
                            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                                grid[nr][nc] = 2;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
        if(hasFreshOranges(grid)) return -1;
        return time-1;
    }
};