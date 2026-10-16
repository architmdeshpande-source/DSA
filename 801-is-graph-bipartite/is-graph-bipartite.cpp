class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        queue<int> q;
        vector<int> visited(nodes, -1);

        for(int i = 0; i<nodes; i++){
            if(visited[i] == -1){
                q.push(i);
                if(i == 0) visited[i] = 0;
                else visited[i] = !visited[i-1];
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto adjNode : graph[node]){
                    if(visited[adjNode] == -1){
                        if(visited[node] == 0){
                            visited[adjNode] = 1;
                        }else{
                            visited[adjNode] = 0;
                        }
                        q.push(adjNode);
                    }else if(visited[adjNode] == visited[node]) return false;
                }
            }
        }
        return true;
    }
};