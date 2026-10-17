class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto& e : prerequisites) adjList[e[0]].push_back(e[1]);

        vector<int> indegree(numCourses);
        for(int i = 0; i< numCourses; i++){
            for(auto adjNode : adjList[i]){
                indegree[adjNode]++;
            }
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int subject = q.front();
            q.pop();
            cnt++;
            for(auto adjNode : adjList[subject]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }

        return cnt==numCourses;
    }
};