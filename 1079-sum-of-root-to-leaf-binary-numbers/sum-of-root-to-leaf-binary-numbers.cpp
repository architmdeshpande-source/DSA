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
    void dfs(TreeNode* root, int num, vector<int>& nums){
        if(root == NULL) return;
        num = num*2 + root->val;   // building in binary directly, no need for binToDec at all
        if(!root->left && !root->right){
            nums.push_back(num);
            return;
        }
        dfs(root->left, num, nums);
        dfs(root->right, num, nums);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> nums;
        dfs(root, 0, nums);
        int sum = 0;
        for(int n : nums) sum += n;
        return sum;
    }
};