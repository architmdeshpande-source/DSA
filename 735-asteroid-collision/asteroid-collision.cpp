class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        int negative = 0;
        
        for(int i = 0; i<asteroids.size(); i++){
            if(asteroids[i]<0) negative = asteroids[i];
            while(!s.empty() && negative!=0 && s.top()>0){
                if(abs(negative) == abs(s.top())){
                    s.pop();
                    negative = 0;
                }else if(abs(negative) > abs(s.top())){
                    s.pop();
                }else{
                    negative = 0;
                }
            }
            if(negative!=0) s.push(negative);
            negative = 0;
            if(asteroids[i]>=0) s.push(asteroids[i]);
        }
        while(!s.empty()){
            int num = s.top();
            s.pop();
            ans.push_back(num);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};