class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int maxFreq = 0;
        int i = 0, ans = 0;
        int n = s.size();

        for(int j = 0; j < n; j++){
            freq[s[j]-'A']++;
            maxFreq = max(maxFreq, freq[s[j]-'A']);

            if((j-i+1) - maxFreq > k){
                freq[s[i]-'A']--;
                i++;
            }

            ans = max(ans, j-i+1);
        }
        return ans;
    }
};