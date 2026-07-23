/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {

public:
   
    	//your code goes here
       vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes as: map[column][row] = multiset of values (to handle duplicates sorted)
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {column, row}}
        
        if (root != nullptr) {
            q.push({root, {0, 0}});
        }
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* curr = p.first;
            int col = p.second.first;
            int row = p.second.second;
            
            nodes[col][row].insert(curr->data); // Assuming node value is stored in 'val' (change to 'data' if custom struct uses 'data')
            
            if (curr->left) {
                q.push({curr->left, {col - 1, row + 1}});
            }
            if (curr->right) {
                q.push({curr->right, {col + 1, row + 1}});
            }
        }
        
        vector<vector<int>> ans;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
    
};
