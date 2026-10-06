class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(auto i : nums) m[i]++; 

        vector<vector<int>> temp(n+1);
        for(auto& [num,f] : m) temp[f].push_back(num);

        vector<int> ans;
        for(int i = n; i>=1 && ans.size()<k; i--){
            for(auto num : temp[i]){
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};