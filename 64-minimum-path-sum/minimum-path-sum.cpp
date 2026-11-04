class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m, 0);
        prev[0] = grid[0][0];
        for(int j = 1; j < m; j++){
            prev[j] = prev[j-1] + grid[0][j];
        }

        for(int i = 1; i<n; i++){
            vector<int> temp(m, 0);
            for(int j = 0; j<m; j++){
                int up = 0;
                int left = 0;
                up = prev[j]+grid[i][j];
                if(j>0) left = temp[j-1]+grid[i][j];
                else left = prev[0]+grid[i][0];
                temp[j] = min(up, left);
            }
            prev = temp;
        }
        return prev[m-1];
    }
};