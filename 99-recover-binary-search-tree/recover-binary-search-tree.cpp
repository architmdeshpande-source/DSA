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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev && root->val<prev->val){
            // if first is NULL
            if(!first){
                first = prev;
                middle = root;
            }else{ // first violation is there
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = prev = middle = last = NULL;
        inorder(root);
        if(!last){
            swap(first->val, middle->val);
        }else{
            swap(first->val, last->val);
        }
    }
};