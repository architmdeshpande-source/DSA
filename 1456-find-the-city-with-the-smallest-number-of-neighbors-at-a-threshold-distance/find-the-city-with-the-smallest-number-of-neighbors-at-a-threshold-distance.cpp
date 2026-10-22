class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        for(auto& e : edges){
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }
        for(int i = 0; i < n; i++) adj[i][i] = 0;

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(adj[i][k] == INT_MAX || adj[k][j] == INT_MAX) continue;
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        int temp = INT_MAX;
        int ans2 = -1;
        for(int i = 0; i < n; i++){
            int ans = 0;
            for(int j = 0; j < n; j++){
                if(adj[i][j] <= distanceThreshold) ans++;
            }
            if(ans <= temp){
                temp = ans;
                ans2 = i;
            }
        }
        return ans2;
    }
};