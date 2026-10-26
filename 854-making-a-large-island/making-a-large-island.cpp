class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);   // path compression
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return;                       // already connected

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int maxSize = INT_MIN;

        //step 1 where you connect all the existing islands to the universal parents 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0) continue;
                int dr[4] = {-1,1,0,0};
                int dc[4] = {0,0,1,-1};
                for(int d = 0; d<4; d++){
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                        int newNode = (i*n)+j;
                        int adjNode = (nr*n)+nc;
                        ds.unionBySize(newNode, adjNode);
                    }
                }
            }
        }

        //step 2
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) continue;
                int dr[4] = {0,0,-1,1};
                int dc[4] = {1,-1,0,0};
                unordered_set<int> s; // to store the universal parents so that when we go to nodes hvn same UP we don't double count
                for(int d = 0; d<4; d++){
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                        s.insert(ds.findUPar((nr*n)+nc));
                    }
                }
                int currSize = 1;
                for(auto it : s){
                    currSize+=ds.size[it];
                }
                maxSize = max(maxSize, currSize);
            }
        }
        for(int cellNo = 0; cellNo<n*n; cellNo++){
            maxSize = max(maxSize, ds.size[ds.findUPar(cellNo)]);
        }
        return maxSize;
    }
};