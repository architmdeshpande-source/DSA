class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int land = 0;
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    land++;
                    if (i == 0 || j == 0 || i == n-1 || j == m-1) {
                        q.push({i, j});
                        grid[i][j] = 0;
                    }
                }
            }
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            land--;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
        return land;
    }
};