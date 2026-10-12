class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int row = 0;
        int direction = 1;

        if(numRows == 1) return s;

        for(int i = 0; i<s.size(); i++){
            if(row == 0) direction = 1;
            if(row == numRows-1) direction = -1;
            rows[row] += s[i];
            row+=direction;
        }

        string ans = "";

        for(auto it : rows){
            ans+= it;
        }
        return ans;
    }
};