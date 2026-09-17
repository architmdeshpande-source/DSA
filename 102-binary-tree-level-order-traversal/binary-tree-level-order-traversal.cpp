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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            for(int i = 0; i< sz; i++){
                TreeNode* ptr = q.front();
                q.pop();
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
                level.push_back(ptr->val);
            }
            ans.push_back(level);
        }

        return ans;
    }
};