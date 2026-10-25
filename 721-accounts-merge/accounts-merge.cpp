class DisjointSet {
    vector<int> parent, size;
public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> m;

        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(m.find(mail) == m.end()) m[mail] = i; // if mail is new with no existing parent....this means if there are two same mails on node 1 & 3 and three will also have diff mails then diff nodes will have 3 marked as their parent and 3 will have 1 as its parent after union by concatenating all will have 1 as its original parents
                else ds.unionBySize(i, m[mail]); // if mail exists then we take a union and mark curr nodes parent as the node which was the mails initial parent
            }
        }

        vector<vector<string>> mergeNode(n);
        for(auto it : m){
            string str = it.first;
            int node = ds.findUPar(it.second);
            mergeNode[node].push_back(str); // we pushback the mail ids after the union was done and mails were organised
        }

        vector<vector<string>> ans;
        for(int i = 0; i<n; i++){
            if(mergeNode[i].size() == 0) continue;
            sort(mergeNode[i].begin(), mergeNode[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeNode[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};