class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        if(n == 0) return ans;
        //empty graph edge case
        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);
        for(int i = 0; i<n; i++){ // i represents curr node and j represents adjNode
            for(auto j : graph[i]){
                adjList[j].push_back(i); // here we reverse the edges and solve
                indegree[i]++; // indegree once graph is reverse
            }
        }
        //here we reverse the graph and apply kahn's algo since we know that the ending node will always be terminating

        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){ // once q is empty we detect a cycle which means that further nodes are not safe nodes 
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto adjNode : adjList[node]){
                if(--indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        sort(ans.begin(), ans.end()); // since we reversed the graph we have to sort it
        return ans;
    }
};