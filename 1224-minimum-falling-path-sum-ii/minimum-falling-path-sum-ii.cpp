class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
       int prevMin1 = 0, prevMin2 = 0, prevIdx1 = -1;

        for(int i = 0; i<n; i++){
            vector<int> cur(n);
            for(int j = 0; j < n; j++){
                cur[j] = grid[i][j] + (j == prevIdx1 ? prevMin2 : prevMin1);
            }
            int min1 = INT_MAX;
            int idx1 = 0;
            int min2 = INT_MAX;
            int idx2 = 0;
            for(int j = 0; j<n; j++){
                if(min1>cur[j]){
                    min1 = cur[j];
                    idx1 = j;
                }
            }
            for(int j = 0; j<n; j++){
                if(j!=idx1 && min2>cur[j]){
                    min2 = cur[j];
                    idx2 = j;
                }
            }
            prevMin1 = min1;
            prevMin2 = min2;
            prevIdx1 = idx1;
        }
        return prevMin1;
    }
};