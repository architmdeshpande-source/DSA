class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(int i = 0; i<arr.size(); i++){
            int doubleInt = 2*arr[i];
            if(s.find(doubleInt)!=s.end()) return true;
            if(arr[i]%2 == 0){
                int halfInt = arr[i]/2;
                if(s.find(halfInt) != s.end()) return true;
            }
            s.insert(arr[i]);
        }
        return false;
    }
};