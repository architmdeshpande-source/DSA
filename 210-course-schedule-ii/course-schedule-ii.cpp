class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto& e : prerequisites){
            adjList[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int subject = q.front();
            q.pop();
            ans.push_back(subject);

            for(auto adjNode : adjList[subject]){
                if(--indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};