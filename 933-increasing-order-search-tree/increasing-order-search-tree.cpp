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
    vector<int> inorder(TreeNode* root, vector<int>& nums){
        if(!root) return nums;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
        return nums;
    }

    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int> inorderTrav;
        inorder(root, inorderTrav);
        TreeNode* newRoot = new TreeNode(inorderTrav[0]);
        TreeNode* curr = newRoot;
        for(int i = 1; i<inorderTrav.size(); i++){
            curr->right = new TreeNode(inorderTrav[i]);
            curr = curr->right;
        }

        return newRoot;
    }
};