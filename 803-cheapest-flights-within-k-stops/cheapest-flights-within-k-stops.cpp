class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& e : flights){
            adj[e[0]].push_back({e[1], e[2]});
        }
        const int INF = 1e9;
        vector<int> cost(n, INF);
        cost[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, 0}});

        while(!q.empty()){
            pair<int, pair<int, int>> t = q.front();
            q.pop();
            int node = t.first;
            auto [price, stops] = t.second;

            if(stops > k) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(price + wt < cost[adjNode]){
                    cost[adjNode] = price + wt;
                    q.push({adjNode, {price + wt, stops + 1}});
                }
            }
        }
        return cost[dst] == INF ? -1 : cost[dst];
    }
};