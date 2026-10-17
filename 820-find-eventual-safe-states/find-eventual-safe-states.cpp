class Solution {
private:
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& graph, vector<int>& ans){
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto adjNode : graph[node]){
            if(!visited[adjNode]){
                if(dfs(adjNode, visited, pathVisited, graph, ans)) return true;
            }else if(pathVisited[adjNode]) return true;
        }
        ans.push_back(node);
        pathVisited[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        if(n==0) return ans;
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, pathVisited, graph, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};