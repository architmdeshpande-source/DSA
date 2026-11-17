class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> m;
        m[1] = 'I';
        m[5] = 'V';
        m[10] = 'X';
        m[50] = 'L';
        m[100] = 'C';
        m[500] = 'D';
        m[1000] = 'M';

        string number = to_string(num);
        int n = number.size();
        string ans = "";

        for(int i = 0; i<n; i++){
            int d = number[i] - '0';
            int p = 1;
            for(int k = 0; k < n-i-1; k++) p *= 10;
            if(d == 4) ans+= m[p] + m[5 * p];
            else if(d == 9) ans+= m[p] + m[10*p];
            else{
               if(d >= 5){
                    ans += m[5*p];
                    d -= 5;
                }
                for(int k = 0; k < d; k++) ans += m[p];
            }
        }
        return ans;
    }
};