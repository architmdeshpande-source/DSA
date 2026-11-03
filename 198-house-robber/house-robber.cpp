class Solution {
private:
    int f(int n, vector<int>& nums, vector<int>& dp){
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[0], nums[1]);
        if(dp[n]!=-1) return dp[n];
        // now we got two options:-
        // compute d[n-1] and d[n-2]+nums[n] if second is greater than we skip the first one and vice versa and   update the current idx i.e d[n] to the max one so while chosing next time the neighbour is not the adjacent one either way if we chose (n-1) or (n & n-2)
        return dp[n] = max(f(n-1, nums, dp), f(n-2, nums, dp)+nums[n]);
    }
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n, -1);
      return f(n-1, nums, dp);  
    }
};