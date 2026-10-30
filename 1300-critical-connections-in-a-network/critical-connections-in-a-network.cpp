class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited, vector<int>& timeInit, vector<int>& low, vector<vector<int>>& bridges){
        visited[node] = 1;
        timeInit[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!visited[it]){
                dfs(it, node, adj, visited, timeInit, low, bridges);
                if(low[it]>timeInit[node]){
                    bridges.push_back({it, node});
                }
            }
            low[node] = min(low[it], low[node]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(n, 0);
        vector<int> timeInit(n); // time of insertion
        vector<int> low(n); // lowest node in its cycle
        vector<vector<int>> bridges;
        dfs(0, -1, adj, visited, timeInit, low, bridges);
        return bridges;
    }
};