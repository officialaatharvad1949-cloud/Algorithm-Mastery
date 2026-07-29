#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

/**
    * This method performs an inorder traversal of a binary tree
    * using the Morris Traversal algorithm, which does not use
    * additional space for a stack or recursion.
*/

 
class Solution {
public:
    vector<int> getInorder(TreeNode* root) {
        // Vector to store inorder traversal
        vector<int> inorder;
        // Pointer to current node
        TreeNode* cur = root; 

        while (cur != nullptr) {
            if (cur->left == nullptr) {
                // Add current node's value and move to right child
                inorder.push_back(cur->data); 
                cur = cur->right; 
            } else {
                // Find predecessor
                TreeNode* prev = cur->left; 
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                /* Establish a temporary link and move to the
                left child */
                if (prev->right == nullptr) {
                    prev->right = cur; 
                    cur = cur->left; 
                } else {
                /* Remove the temporary link, add current node's value
                and move to the right child */      
                    prev->right = nullptr; 
                    inorder.push_back(cur->data); 
                    cur = cur->right;
                }
            }
        }
        // Return inorder traversal
        return inorder; 
    }
};
