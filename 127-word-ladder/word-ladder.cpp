class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& st) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> s(st.begin(), st.end());
        s.erase(beginWord);
        while(!q.empty()){
            pair<string, int> t = q.front();
            q.pop();
            string temp = t.first;
            int distance = t.second;
            if(temp == endWord) return distance;

            for(int i = 0; i<temp.size(); i++){
                char original = temp[i];
                for(char ch = 'a'; ch <='z'; ch++){
                    temp[i] = ch;
                    if(s.find(temp) != s.end()){
                        s.erase(temp);
                        q.push({temp, distance+1});
                    }
                }
                temp[i] = original;
            }
        }
        return 0;
    }
};