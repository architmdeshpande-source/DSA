class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int INF = 1e9;
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INF));
        int dr[4] = {0,0,-1,1};
        int dc[4] = {1,-1,0,0};
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0, 0}});

        while(!q.empty()){
            pair<int, pair<int, int>> t = q.top();
            q.pop();
            int absDiff = t.first;
            auto [r, c] = t.second;

            for(int i = 0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size()){
                      int diff = max(absDiff, abs(heights[nr][nc] - heights[r][c]));
                      if(diff<dist[nr][nc]){
                        dist[nr][nc] = diff;
                        q.push({dist[nr][nc],{nr, nc}});
                    } 
                }
            }
        }
        return dist[heights.size()-1][heights[0].size()-1];
    }
};