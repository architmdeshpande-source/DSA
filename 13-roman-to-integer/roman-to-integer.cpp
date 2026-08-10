class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char, int> m = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
       int num = 0; 
       int i = 0;
       int n = s.size();

       while(i<n){
            if(i<n-1 && m[s[i]]<m[s[i+1]]){
                num+= m[s[i+1]] - m[s[i]];
                i++;
            }else{
                num+= m[s[i]];
        }
        i++;
       }

       return num;
    }
};