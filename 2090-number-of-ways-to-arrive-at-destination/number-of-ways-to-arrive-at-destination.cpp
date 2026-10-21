class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        const long long INF = LLONG_MAX;
        const int mod = 1e9+7;
        vector<long long> dest(n, INF);
        vector<int> ways(n, 0);
        ways[0] = 1;
        dest[0] = 0;
        q.push({0,0});
        while(!q.empty()){
            long long dis = q.top().first;
            int node = q.top().second;
            q.pop();
            if(dis>dest[node]) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < dest[adjNode]){
                    dest[adjNode] = dis + wt;
                    q.push({dest[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }else if(dis + wt == dest[adjNode]){
                    ways[adjNode] = (ways[node]+ways[adjNode])%mod;
                }
            }
        }
        return ways[n-1];
    }
};