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
    pair<int, bool> check(TreeNode* root){
        if(root == NULL) return {0, true};
        auto left = check(root->left);
        auto right = check(root->right);
        
        int height = max(left.first, right.first) + 1;
        
        bool balanced = left.second && right.second && abs(left.first-right.first)<=1;
        
        return {height, balanced};
        
        
    }
    bool isBalanced(TreeNode* root) {
        pair<int, bool> ans = check(root);
        return ans.second;
    }
};