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
    bool fillMap(TreeNode* root, int k, unordered_set<int>& s){
        if(!root) return false;
        if(s.find(root->val) != s.end()) return true;
        s.insert(k - root->val);
        return fillMap(root->left, k, s) || fillMap(root->right, k, s);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return fillMap(root, k, s);
    }
};