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
    TreeNode* tree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& m){
        if(inStart>inEnd || postStart>postEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootIdx = m[root->val];
        int numsLeft = rootIdx - inStart;

        root->left = tree(inorder, inStart, rootIdx-1, postorder, postStart, postStart+numsLeft-1, m);
        root->right = tree(inorder, rootIdx+1, inEnd, postorder, postStart+numsLeft, postEnd-1, m);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for(int i = 0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }

        return tree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, m);
    }
};