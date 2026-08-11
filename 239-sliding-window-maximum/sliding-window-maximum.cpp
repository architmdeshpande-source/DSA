class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        int maxNum = INT_MIN;
        int n = nums.size();
        vector<int> ans;

        //first step
        for(int i = 0; i<k; i++){
            while(!d.empty() && nums[i]>= nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }

        ans.push_back(nums[d.front()]);

        //second step
        for(int i = k; i<n; i++){
            //deletion of front element
            while(!d.empty() && nums[i]>= nums[d.back()]){
                d.pop_back();
            }

            while(!d.empty() && i - d.front()>=k){
                d.pop_front();
            }

            // addition of nums
            d.push_back(i);
            ans.push_back(nums[d.front()]);
        }

        return ans;
    }
};