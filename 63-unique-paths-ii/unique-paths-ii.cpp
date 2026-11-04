class Solution {
private:
    int f(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(i < 0 || j<0) return 0; // -ve idx edge case
        if(arr[i][j] == 1) return 0; // obstacle at the start or any where
        if(i == 0 && j == 0) return 1; // generic base case
        if(dp[i][j]!=-1) return dp[i][j]; 
        int up = f(i-1, j, arr, dp);
        int left = f(i, j-1, arr, dp);
        return dp[i][j] = up + left;
        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, obstacleGrid, dp);
    }
};