class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};
        queue<pair<int, int>> q;

        //push all the zeroes
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0) q.push({i,j});
                else mat[i][j] = -1; //replace the 1s with -1
            }
        }

        while(!q.empty()){
            pair<int, int> t = q.front();
            int r = t.first;
            int c = t.second;
            q.pop();

            for(int d = 0; d<4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nc>=0 && nc<m && nr>=0 && nr<n && mat[nr][nc] == -1){
                    mat[nr][nc] = mat[r][c] + 1; // if -1 is found it is overwritten to mat[nr][nc] + 1
                    q.push({nr, nc});
                }
            }
        }

        return mat;
    }
};