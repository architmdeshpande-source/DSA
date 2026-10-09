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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        // check if root falls in our required range of [low, high]
        while(root && (root->val < low || root->val>high)){
            if(root->val < low){
                root = root->right;
            }else{
                root = root->left;
            }
        }

        // now to get other branches in range by checking for lows and highs
        TreeNode* curr = root;
        while(curr){
            while(curr->left && curr->left->val < low){
                curr->left = curr->left->right;
            }
            curr = curr->left;
        }
        curr = root;
        while(curr){
            while(curr->right && curr->right->val > high){
                curr->right = curr->right->left;
            }
            curr = curr->right;
        }
        return root;
    }
};