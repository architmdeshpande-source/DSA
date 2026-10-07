class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(int i = 0; i<strs.size(); i++){
            string newStr = strs[i];
            sort(newStr.begin(), newStr.end());
            m[newStr].push_back(strs[i]);
        }
        for(auto i : m){
            ans.push_back(i.second);
        }
        return ans;
    }
};