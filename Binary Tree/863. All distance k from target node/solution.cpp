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
private:
   void markThenode(TreeNode* root , unordered_map<TreeNode* , TreeNode*> &parent_track){
    if(root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);
    while(q.size()){
        TreeNode* front = q.front();
        q.pop();
        if(front->left){
            parent_track[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            parent_track[front->right] = front;
            q.push(front->right);
        }
    }
   }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent_track;
        markThenode(root , parent_track);
        vector<int> ans;
        unordered_map<TreeNode* , bool> vis;
        queue<TreeNode*> q;
        int level = 0;
        
        q.push(target);
vis[target] = true;

while(!q.empty()) {
    int size = q.size();

    if(level == k)
        break;

    while(size--) {
        TreeNode* curr = q.front();
        q.pop();

        if(parent_track.count(curr) && !vis[parent_track[curr]]) {
            vis[parent_track[curr]] = true;
            q.push(parent_track[curr]);
        }

        if(curr->left && !vis[curr->left]) {
            vis[curr->left] = true;
            q.push(curr->left);
        }

        if(curr->right && !vis[curr->right]) {
            vis[curr->right] = true;
            q.push(curr->right);
        }
    }

    level++;
}
        int size = q.size();
        while(q.size()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
        
    }
};
