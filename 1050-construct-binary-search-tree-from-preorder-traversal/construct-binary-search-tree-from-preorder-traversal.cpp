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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        for(int i = 1; i<preorder.size(); i++){
            TreeNode* lastPopped = NULL;
            while(!st.empty() && st.top()->val<preorder[i]){
                lastPopped = st.top();
                st.pop();
            }
            TreeNode* child = new TreeNode(preorder[i]);
            if(lastPopped!= NULL){
                lastPopped->right = child;
            }else{
                st.top()->left = child;
            }

            st.push(child);
        }
        return root;
    }
};