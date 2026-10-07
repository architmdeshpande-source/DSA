class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(const string& s : strs){
            //create a freq arr and store all the chars freq in it
            int cnt[26] = {0};
            for(char ch : s) cnt[ch-'a']++;
            //create a key for each anagram by converting the freq arr into a str. Each anagram will hv the same key
            string key = "";
            for(int i = 0; i<26; i++){
                key+= '#';
                key+= to_string(cnt[i]);
            }
            // if the key matches push the string in the vector
            m[key].push_back(s);
        }

        for(auto i : m){
            ans.push_back(i.second);
        }
        return ans;
    }
};