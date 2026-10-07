class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int freq1[128] = {0};
        int freq2[128] = {0};
        for(int i = 0; i<s.size(); i++){
            freq1[s[i] - 'a']++;
            freq2[t[i]- 'a']++;
        }
        for(int i = 0; i<128; i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
};