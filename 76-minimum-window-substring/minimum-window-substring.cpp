class Solution {
public:
    bool isValid(int freq1[], int freq2[] ){
        for(int i = 0; i<128; i++){
            if(freq1[i]>freq2[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int freq1[128] = {0};
        int freq2[128] = {0};
        int i = 0;
        int j = 0;
        int minimum = INT_MAX, bestStart = 0;

        for(int k = 0; k<m; k++){
            freq1[t[k]-'A']++;
        }

        while(j<n){
            freq2[s[j]-'A']++;
            while(isValid(freq1, freq2)){
                if(j-i+1 < minimum){
                    minimum = j-i+1;
                    bestStart = i;
                }
                freq2[s[i]-'A']--;
                i++;
            }
            j++;
        }
        return minimum == INT_MAX? "": s.substr(bestStart, minimum);
    }
};