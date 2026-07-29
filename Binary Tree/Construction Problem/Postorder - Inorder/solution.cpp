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
private:
    TreeNode* build_tree(vector<int> &postorder , int pos_start , int pos_end , vector<int> &inorder 
                        , int in_start , int in_end , unordered_map<int , int> &hash_map){
            if(pos_start > pos_end || in_start > in_end) return nullptr;
            TreeNode* root = new TreeNode(postorder[pos_end]);
            int child = hash_map[postorder[pos_end]];
            int len = child - in_start;

            root->left = build_tree(postorder , pos_start , pos_start+len-1 , inorder , in_start , child-1 , hash_map);

            root->right = build_tree(postorder , pos_start+len , pos_end-1, inorder , child+1 , in_end , hash_map);

            return root;


        }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //your code goes here
        int n = postorder.size();

        unordered_map<int , int> hash_in;

        for(int i = 0 ; i < n ; ++i){
            hash_in[inorder[i]] = i;
        }

        return build_tree(postorder , 0 , n-1 , inorder , 0 , n-1 , hash_in);
    }
};
