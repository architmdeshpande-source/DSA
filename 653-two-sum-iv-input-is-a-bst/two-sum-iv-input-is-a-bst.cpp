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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        stack<TreeNode*> left, right;

        for(TreeNode* p = root; p; p = p->left) left.push(p); // push all xtreme left nodes
        for(TreeNode* p = root; p; p = p->right) right.push(p); // push all xtreme right nodes

        while(left.top()!=right.top()){
            int sum = left.top()->val + right.top()->val;
            if(sum == k) return true;
            else if(sum<k){
                TreeNode* n = left.top();
                left.pop();
                for(TreeNode* p = n->right; p; p = p->left) left.push(p); // next in the inorders right all elements
            }else{
                TreeNode* n = right.top();
                right.pop();
                for(TreeNode* p = n->left; p; p = p->right) right.push(p);// next in the inorders left all elements
            }
        }
        return false;
    }
};