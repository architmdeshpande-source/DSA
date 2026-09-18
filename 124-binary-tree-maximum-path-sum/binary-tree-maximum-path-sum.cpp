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
    int maxPathDown(TreeNode* root, int& maxim){
        if(root == NULL) return 0;
        int leftSum = max(0, maxPathDown(root->left, maxim));
        int rightSum = max(0, maxPathDown(root->right, maxim));

        maxim = max(maxim, leftSum + rightSum + root->val);
        return max(leftSum, rightSum) +  root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxim = INT_MIN;
        maxPathDown(root, maxim);
        return maxim;
    }
};