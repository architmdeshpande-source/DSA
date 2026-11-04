class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n =  arr.size();
        int m = arr[0].size();
        vector<int> prev(m, 0);
        for(int j = 0; j<m; j++){
            if(arr[0][j] == 1) break;
            else prev[j] = 1;
        }
        for(int i = 1; i<n; i++){
            vector<int> temp(m, 0);
            for(int j = 0; j<m; j++){
                if(arr[i][j] == 1){
                    temp[j] = 0;
                    continue;
                }
                int up = 0;
                int left = 0;
                up = prev[j];
                if(j>0) left = temp[j-1];
                temp[j] = up + left;
            }
            prev = temp;
        }
        return prev[m-1];
    }
};