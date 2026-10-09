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
    TreeNode* head = NULL;
    TreeNode* prev = NULL;
public:
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);

        root->left = NULL;
        if(prev){
            prev->right = root;
        }else{
            head = root;
        }
        prev = root;

        helper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);
        return head;
    }
};