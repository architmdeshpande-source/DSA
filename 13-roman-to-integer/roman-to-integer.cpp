class Solution {
public:
    int romanToInt(string s) {
       map<char, int> m;
       m['I'] = 1;
       m['V'] = 5;
       m['X'] = 10;
       m['L'] = 50;
       m['C'] = 100;
       m['D'] = 500;
       m['M'] = 1000;
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