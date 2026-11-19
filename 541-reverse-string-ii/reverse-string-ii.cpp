class Solution {
public:
    string reverseStr(string s, int k) {
        if(k>=s.size()){
            reverse(s.begin(), s.end());
            return s;
        } 

        for(int i = 0; i<s.size(); i+=2*k){
            int a  = i;
            int b = min(i+k, (int)s.size()) - 1;
            while(b>=a && b<s.size()){
                swap(s[a], s[b]);
                a++;
                b--;
            }
        }
        return s;
    }
};