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
    TreeNode* findLastRight(TreeNode*root){
        if(root->right == NULL) return root;
        return findLastRight(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(root->right == NULL){
            return root->left;
        }else if(root->left == NULL){
            return root->right;
        }
        TreeNode* rightChild = root->right; // take the right of the target node;
        TreeNode* lastRightChildOnLeft = findLastRight(root->left); // take the left of the target node and find the right of it
        lastRightChildOnLeft->right = rightChild; // connect the last right to the targets right
        return root->left; // returning the targets left as it is connected with the prev target node
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};