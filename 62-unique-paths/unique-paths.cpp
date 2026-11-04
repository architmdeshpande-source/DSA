class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, -1);
        for(int i = 0; i<m; i++){
            vector<int> temp(n, -1);
            for(int j = 0; j<n; j++){
                if(i == 0 || j == 0) temp[j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    up = dp[j];
                    left = temp[j-1];
                    temp[j] = up + left;
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};