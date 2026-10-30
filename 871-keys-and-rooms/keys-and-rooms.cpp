class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(visited[node]) continue;
            visited[node] = 1;
            for(auto it : rooms[node]){
                if(!visited[it]) q.push(it);
            }
        }
        for(int i = 0; i<rooms.size(); i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};