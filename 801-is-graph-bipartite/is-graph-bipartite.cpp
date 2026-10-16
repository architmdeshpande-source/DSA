class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> visited(nodes, -1);
        queue<int> q;

        // iterate over the visited array and give it alternate colour and push in the queue
        for(int i = 0; i<nodes; i++){
            if(visited[i]!=-1) continue;
            q.push(i);
            if(i == 0) visited[i] = 0;
            else visited[i] = !visited[i-1];
            //general bfs algo
            while(!q.empty()){
                int node = q.front();
                q.pop();
                // traverse thru each node the graph is connected to and check the colour
                for(auto adjNode : graph[node]){
                    // if colour isn't assigned
                    if(visited[adjNode] == -1){
                        q.push(adjNode);
                        visited[adjNode] = !visited[node];
                    // if colour is assigned and is equal to the cuurent node
                    }else if(visited[adjNode] == visited[node]) return false;
                }
            }
        }
        return true;
    }
};