class Solution {
private:
    bool dfs(int node, int color, vector<int>& visited, vector<vector<int>>& graph){
    // update the current nodes color
    visited[node] = color;
    //traverse thru the adj nodes of the curr node
    for(auto adjNode : graph[node]){
        //if the adj node is not visited then give a recurssive call
        if(visited[adjNode] == -1){
            if(!dfs(adjNode, !color, visited, graph)) return false;
        }else if(visited[adjNode] == color) return false;
    }
    return true;
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> visited(nodes, -1);

        // traverse thru the visited array and check for the unvisited nodes
        for(int i = 0; i<nodes; i++){
            if(visited[i] == -1){
            //general dfs
                if(!dfs(i, 0, visited, graph)) return false;
            }
        }
        return true;
    }
};