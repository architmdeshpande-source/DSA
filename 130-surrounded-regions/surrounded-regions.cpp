class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& visited, vector<vector<char>>& board){
        visited[r][c] = 1; // update the visited array
        int n = board.size();
        int m = board[0].size();
        // check for the neighbouring cells and not diagonal cells
        if(r < n-1 && board[r+1][c] == 'O' && visited[r+1][c] == 0){
            dfs(r+1,c,visited,board);
        }
        if(r>0 && board[r-1][c] == 'O' && visited[r-1][c] == 0){
            dfs(r-1,c,visited,board);
        }
        if(c<m-1 && board[r][c+1] == 'O' && visited[r][c+1] == 0){
            dfs(r,c+1,visited,board);
        }
        if(c>0 && board[r][c-1] == 'O' && visited[r][c-1] == 0){
            dfs(r,c-1,visited,board);
        }

        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        if(m == 0) return;
        vector<vector<int>> visited(n , vector<int>(m,0));

        // search for 'O's in the end cells i.e (i = 0 || n-1) || (j = 0 || m-1)
        int i = 0;
        for(int j = 0; j<m; j++){
            if(board[i][j] == 'O'){
                dfs(i,j,visited,board);
            }
        }
        i = n-1;
        for(int j = 0; j<m; j++){
            if(board[i][j] == 'O'){
                dfs(i,j,visited,board);
            }
        }
        int j = 0;
        for(int k = 0; k<n; k++){
            if(board[k][j] == 'O'){
                dfs(k,j,visited,board);
            }
        }
        j = m-1;
        for(int k = 0; k<n; k++){
            if(board[k][j] == 'O'){
                dfs(k,j,visited,board);
            }
        }

        // if the cell is not visited and consists of an 'O' then replace it w a 'X'
        for(int a = 0; a<n; a++){
            for(int b = 0; b<m; b++){
                if(board[a][b] == 'O' && visited[a][b] == 0){
                    board[a][b] = 'X';
                }
            }
        }
    }
};