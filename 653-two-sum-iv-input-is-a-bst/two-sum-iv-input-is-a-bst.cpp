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
        if (!root) return false;

        stack<TreeNode*> L, R;   // L walks smallest -> larger, R walks largest -> smaller
        for (TreeNode* p = root; p; p = p->left)  L.push(p);
        for (TreeNode* p = root; p; p = p->right) R.push(p);

        while (L.top() != R.top()) {
            int sum = L.top()->val + R.top()->val;
            if (sum == k) return true;

            if (sum < k) {                      // need a bigger sum: advance left pointer
                TreeNode* n = L.top(); L.pop();
                for (TreeNode* p = n->right; p; p = p->left) L.push(p);
            } else {                            // need a smaller sum: advance right pointer
                TreeNode* n = R.top(); R.pop();
                for (TreeNode* p = n->left; p; p = p->right) R.push(p);
            }
        }
        return false;
    }
};