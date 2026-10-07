class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (const string& s : strs) {
            int cnt[26] = {0};
            for (char c : s) cnt[c - 'a']++;

            string key;
            for (int i = 0; i < 26; i++) {
                key += '#';
                key += to_string(cnt[i]);
            }
            m[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& p : m) ans.push_back(p.second);
        return ans;
    }
};