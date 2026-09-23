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
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> m;
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while(!q.empty()){
            pair<TreeNode*, int> t = q.front();
            TreeNode* frontNode = t.first;
            q.pop();
            int lvl = t.second;
            m[lvl] = frontNode->val;

            if(frontNode->left){
                q.push(make_pair(frontNode->left, lvl + 1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, lvl + 1));
            }
        }

        for(auto i : m){
            ans.push_back(i.second);
        }

        return ans;
    }
};