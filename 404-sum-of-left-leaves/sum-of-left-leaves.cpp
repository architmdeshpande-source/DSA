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
    bool isChild(TreeNode* root){
        if(!root->left && !root->right) return true;
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            if(frontNode->left && isChild(frontNode->left)){
                sum+= frontNode->left->val;
            }
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
        }
        return sum;
    }
};