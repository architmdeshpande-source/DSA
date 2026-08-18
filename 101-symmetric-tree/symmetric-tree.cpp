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
    bool check(TreeNode* n1, TreeNode* n2){
        if(n1 == NULL && n2 == NULL) return true;
        if((n1 != NULL && n2 == NULL) || (n1 == NULL && n2 != NULL)) return false;
        if(n1->val == n2->val){
            return check(n1->left, n2->right) && check(n1->right, n2->left);    
        }else{
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};