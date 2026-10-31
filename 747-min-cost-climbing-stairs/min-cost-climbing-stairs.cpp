class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = 0;
        int prev2 = 0;
        for(int i = 2; i<cost.size()+1; i++){
            int left = prev2 + cost[i-1];
            int right = prev1 + cost[i-2];
            int curr = min(left, right);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};