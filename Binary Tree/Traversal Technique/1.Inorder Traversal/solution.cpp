class Solution{
	public:
		vector<int> inorder(TreeNode* root){
	        //your code goes here
            vector<int> ans;
            stack<TreeNode*> st;
            TreeNode* node = root;
            while(1){
                if(node == nullptr){
                    if(st.empty()) break;

                    TreeNode* to_in = st.top();
                    ans.push_back(to_in->data);
                    node = to_in->right;
                    st.pop();
                    continue;
                }
                st.push(node);
                node = node->left;
            }
            return ans;
		}
};
