class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       if(n == 1) return nums[0];
       int prev1 = nums[0]; // first and last houses are neighbours so they can't be together
       int prev2 = 0;
       int ans1 = 0; // compute the entire array by isolating the last house
       int ans2 = 0; // compute the entire array by isolating the first house

       for(int i = 1; i<n-1; i++){
        int left = prev1;
        int right = 0;
        if(i>1) right = prev2 + nums[i];
        else right = nums[i];
        int curr = max(left, right);
        prev2 = prev1;
        prev1 = curr;
       }
       ans1 = prev1;
       prev1 = nums[1];
       prev2 = 0;
       for(int i = 2; i<n; i++){
        int left = prev1;
        int right = 0;
        if(i>2) right = prev2 + nums[i];
        else right = nums[i];
        int curr = max(left, right);
        prev2 = prev1;
        prev1 = curr;
       }
       ans2 = prev1;
       return max(ans1, ans2); 
    }
};