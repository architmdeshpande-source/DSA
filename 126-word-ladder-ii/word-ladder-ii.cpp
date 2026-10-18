class Solution {
private:
    unordered_map<string, int> level;
    vector<vector<string>> ans;
    string begin;

    void dfs(const string& word, vector<string>& path){
        if(word == begin){
            ans.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        int lv = level[word];
        string w = word;
        for(int i = 0; i < w.size(); i++){
            char original = w[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                w[i] = ch;
                auto it = level.find(w);
                if(it != level.end() && it->second == lv - 1){
                    path.push_back(w);
                    dfs(w, path);
                    path.pop_back();
                }
            }
            w[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord)) return {};

        begin = beginWord;
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 1;
        s.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            q.pop();
            int lv = level[word];
            if(word == endWord) break;

            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(s.count(word)){
                        s.erase(word);
                        level[word] = lv + 1;
                        q.push(word);
                    }
                }
                word[i] = original;
            }
        }

        if(!level.count(endWord)) return {};

        vector<string> path = {endWord};
        dfs(endWord, path);
        return ans;
    }
};