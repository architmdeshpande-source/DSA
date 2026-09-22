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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool zigZag = true;

        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i = 0; i<n; i++){
                TreeNode* temp1 = q.front();
                q.pop();
                int idx = zigZag? i : n-i-1;
                temp[idx] = temp1->val;
                if(temp1->left){
                    q.push(temp1->left);
                }
                if(temp1->right){
                    q.push(temp1->right);
                }
            }
            zigZag = !zigZag;
            ans.push_back(temp);
        }
        return ans;
    }
};