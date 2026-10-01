class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        for(int i = n-1; i>=2; i--){
            int a = 0;
            int b = i-1;

            while(a<b){
                int sum1 = nums[a] + nums[b];
                if(sum1>nums[i]){
                    cnt+=(b-a);
                    b--;
                }else{
                    a++;
                }
            }
        }
        return cnt;
    }
};