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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_set<int> s; // to store the components w more than two child nodes
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; // columns start after the very last row so makes sense
            ds.unionBySize(nodeRow, nodeCol); // if stones are in the same row or column we take the union
            s.insert(nodeRow); // once you find that they share a stone in the row or col push them in the set
            s.insert(nodeCol);
        }

        int cnt = 0;
        for(auto it : s){
            if(ds.findUPar(it) == it){
                cnt ++;
            }
        }
        return n-cnt;
    }
};