class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);

        for(int i = 0; i<n; i++){
            dp[i] = triangle[n-1][i]; // copy the bottom row as it is 
        }

        for(int i = n-2; i>=0; i--){
            vector<int> temp(n, 0);
            for(int j = i; j>=0; j--){
                int adj1 = dp[j]+triangle[i][j]; // adj one is the one below or the right adj one
                int adj2 = dp[j+1]+triangle[i][j];
                temp[j] = min(adj1, adj2); // take the min sum of below or adj
            }
            dp = temp;
        }
        return dp[0];
    }
};