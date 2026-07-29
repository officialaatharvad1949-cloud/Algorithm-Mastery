This is the morris inorder Traversal .
Main benefit of this Traversal is that its space complexity is always constant;
here is the approach 
Approach:
Begin by initializing the current node to the root of the binary tree.
While the current node is not null:
If the current node lacks a left child, print its value and move to the right child by setting the current node to its right child.
If the current node has a left child:
Identify the in-order predecessor of the current node, which is the rightmost node in the left subtree.
If the right child of the in-order predecessor is null, create a thread by setting its right child to the current node. Then, move to the left child by updating the current node to its left child.
If the right child of the in-order predecessor is not null, this indicates a previously established thread. Revert this change by setting the right child of the in-order predecessor back to null. Print the current node's value and then move to the right child by setting the current node to its right child.
Repeat the above steps until the traversal reaches the end of the tree.
