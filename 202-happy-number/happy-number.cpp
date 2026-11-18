class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;

        while(n!= 1){
            if(s.find(n)!= s.end()) return false;
            else s.insert(n);
            int sum = 0;

            while(n>0){
                int temp = n%10;
                sum+= temp*temp;
                n = n/10;
            }

            n = sum;
        }
        return true;
    }
};