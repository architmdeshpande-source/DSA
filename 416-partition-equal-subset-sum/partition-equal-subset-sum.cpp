class Solution {
private:
    bool helper(int n, int sum, vector<int>& arr){
        vector<int> prev(sum+1, 0);
        vector<int> curr(sum+1, 0);
        curr[0] = prev[0] = true;
        if(arr[0]<=sum) prev[arr[0]] = true;

        for(int i = 1; i<n; i++){
            for(int j = 1; j<=sum; j++){
                bool notTake = prev[j];
                bool take = false;
                if(arr[i]<=j) take = prev[j - arr[i]];
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2 == 1) return false;
        else return helper(n, sum/2, nums);
    }
};