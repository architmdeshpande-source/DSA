class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> s;

        for(int i = 0; i<tokens.size(); i++){
            string num = tokens[i];
            if(num == "+"){
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                s.push(num1+num2);
            }else if(num == "-"){
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                s.push(num1-num2);
            }else if(num == "/"){
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                s.push(num1/num2);
            }else if(num == "*"){
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                s.push(num1*num2);
            }else{
                s.push(stoi(tokens[i]));
            }
            
        }
        ans = s.top();
        s.pop();
        return ans;
    }
};