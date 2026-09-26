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
// mark all the child nodes wrt the parent nodes
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
        //maintain a map which stores which node is visited and not
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
                //check if there is a next or prev node and wether it is visited or not
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
        // once you hit currLvl = k you will break thru the above loop but the queue won't be empty so for that
        // mean the queue has the resulting elements which are at a distance k from target....now push them in ans
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            ans.push_back(front->val);
        }
        return ans;
    }
};