/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
#include<sstream>
#include<queue>
#include<string>
class Solution {
public:

    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){

            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                ans += "#,";
            }else{
                ans += to_string(curr->data) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }

        }
        return ans;
        
    }

    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;
        
        stringstream s(data);
        string str;
        
        // Read the root value
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // Left child
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            } else {
                curr->left = nullptr;
            }
            
            // Right child
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            } else {
                curr->right = nullptr;
            }
        }
        
        return root;
    }
       
        
    
    

};
/*
* Your Codec object will be instantiated and called as such:
* Codec* ser = new Codec();
* Codec* deser = new Codec();
* string tree = ser->serialize(root);
* TreeNode* ans = deser->deserialize(tree);
* return ans;
*/
