class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if(original == color) return image;
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        image[sr][sc] = color;
        q.push({sr,sc});
        while(!q.empty()){
            pair<int, int> t = q.front();
            q.pop();
            int row = t.first;
            int col = t.second;
            for(int d = 0; d<4; d++){
                int nr = row + dr[d];
                int nc = col + dc[d];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == original){
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};