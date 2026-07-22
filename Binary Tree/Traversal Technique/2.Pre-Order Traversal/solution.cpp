class Solution{
	public:
		vector<int> preorder(TreeNode* root){
	       //your code goes here
           stack<TreeNode*> st;
           vector<int> ans;
           TreeNode* node = root;
           while(true){
            if(node == nullptr){
                if(st.empty()) break;

                node = st.top()->right;
                
                st.pop();

                continue;
            }

            st.push(node);

            ans.push_back(node->data);

            node = node->left;
           }
           return ans;
		}
};
