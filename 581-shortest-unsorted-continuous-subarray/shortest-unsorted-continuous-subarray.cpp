class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = INT_MIN;
        int minSoFar = INT_MAX;
        int end = -1, start = 0;

        // Left to right: find the rightmost index that's smaller than some earlier max
        for(int i = 0; i < n; i++){
            maxSoFar = max(maxSoFar, nums[i]);
            if(nums[i] < maxSoFar){
                end = i;
            }
        }

        // Right to left: find the leftmost index that's bigger than some later min
        for(int i = n-1; i >= 0; i--){
            minSoFar = min(minSoFar, nums[i]);
            if(nums[i] > minSoFar){
                start = i;
            }
        }

        return end - start + 1 > 0 ? end - start + 1 : 0;
    }
};
