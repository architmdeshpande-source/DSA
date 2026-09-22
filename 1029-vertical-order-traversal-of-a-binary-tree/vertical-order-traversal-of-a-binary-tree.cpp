/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int, vector<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push(make_pair(root, make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> t = q.front();
            q.pop();
            TreeNode* frontNode = t.first;
            int hd = t.second.first;
            int lvl = t.second.second;
            m[hd][lvl].push_back(frontNode->val);
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1,lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
            }
        }

        for(auto i : m){
            vector<int> temp;
            for(auto j : i.second){
                vector<int>levels = j.second;
                sort(levels.begin(), levels.end());
                for(auto k : levels){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};