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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        queue<pair<TreeNode*, string>> q;
        q.push({root, ""});
        while(!q.empty()){
            pair<TreeNode*, string> t = q.front();
            q.pop();
            TreeNode* frontNode = t.first;
            string newStr = t.second;
            newStr+= to_string(frontNode->val);
            if(frontNode->left){
                q.push({frontNode->left, newStr+"->"});
            }
            if(frontNode->right){
                q.push({frontNode->right, newStr+"->"});
            }
            if(!frontNode->left && !frontNode->right){
                ans.push_back(newStr);
            }
        }
        return ans;
    }
};