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
    int helper(TreeNode* root, int& sum, int& maxDepth, int currDepth){
        if(!root) return sum;
        if(currDepth > maxDepth){
            maxDepth = currDepth;
            sum = root->val;
        }else if(currDepth == maxDepth){
            sum+=root->val;
        }
        helper(root->left, sum, maxDepth, currDepth+1);
        helper(root->right, sum, maxDepth, currDepth+1);
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0, maxDepth = 0;
        return helper(root, sum, maxDepth, 0);
    }
};