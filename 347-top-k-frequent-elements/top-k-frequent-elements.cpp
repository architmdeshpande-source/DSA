class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            m[nums[i]]++;
        }
        for(int i = 0; i<k; i++){
            auto maximum = max_element(m.begin(), m.end(),[](const auto& a, const auto& b) {
            return a.second < b.second;
        });
            ans.push_back(maximum->first);
            m.erase(maximum);
        }
        return ans;
    }
};