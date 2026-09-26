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
    int leftHeight(TreeNode* root){
        if(!root) return 0;
        int ht = 0;
        while(root!=NULL){
            ht++;
            root = root->left;
        }
        return ht;
    }
    int rightHeight(TreeNode* root){
        if(!root) return 0;
        int ht = 0;
        while(root!=NULL){
            ht++;
            root = root->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left = leftHeight(root);
        int right = rightHeight(root);

        if(left == right) return pow(2,left) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};