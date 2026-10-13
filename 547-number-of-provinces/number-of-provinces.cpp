class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited){
        visited[node] = 1;
        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it, adjList, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                }
            }
        }
        vector<int> visited(n, 0);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, adjList, visited);
            }
        }
        return cnt;
    }
};