/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parentTrack[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parentTrack[node->right] = node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        markParents(root,parentTrack,target);
        vector<int> ans;
        if(root == NULL) return ans;
        unordered_map<TreeNode*, bool> m;
        queue<TreeNode*> q;
        m[target] = true;
        q.push(target);
        int currLvl = 0;
        while(!q.empty()){
            int sz = q.size();
            if(currLvl++ == k) break;
            for(int i = 0; i<sz; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                if(frontNode->left && !m[frontNode->left]){
                    q.push(frontNode->left);
                    m[frontNode->left] = true;
                }
                if(frontNode->right && !m[frontNode->right]){
                    q.push(frontNode->right);
                    m[frontNode->right] = true;
                }
                if(parentTrack[frontNode] && !m[parentTrack[frontNode]]){
                    q.push(parentTrack[frontNode]);
                    m[parentTrack[frontNode]] = true;
                }
            }
        }

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            ans.push_back(front->val);
        }
        return ans;
    }
};