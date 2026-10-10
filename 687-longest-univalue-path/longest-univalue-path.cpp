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
    int helper(TreeNode* root, int& count){
        if(!root) return count;
        int l = helper(root->left, count);
        int r = helper(root->right, count);

        int leftChain = 0, rightChain = 0;
        if (root->left && root->left->val == root->val) leftChain = l + 1;
        if (root->right && root->right->val == root->val) rightChain = r + 1;

        count = max(count, leftChain + rightChain);
        return max(leftChain, rightChain);
    }
    int longestUnivaluePath(TreeNode* root) {
        int cnt = 0;
        helper(root, cnt);
        return cnt;
    }
};