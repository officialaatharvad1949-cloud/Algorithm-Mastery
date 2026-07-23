VERTICAL ORDER TRAVERSAL
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and 
ending on the rightmost column. 
There may be multiple nodes in the same row and same column.
In such a case, sort these nodes by their values. Return the binary tree's vertical order traversal.

Main INTUITION 
Divide the whole tree into multiple sections, then store the data of the node as a value and the position as a key. 
Using the data structure map<int, map<int, multiset<int>>>; first int stores the vertical line position, second int variable stores the level of each node, 
and the multiset variable stores the data of the node.Since the data can have repeated value and also it's need to be in proper sorted sequence.
If the two node share the same position in the tree , then they should be printed sequentially as per question.
We can use any data structure to label the each node. But using the level order traversal should be much more easy.
After labelling every node,map data structure is traversed to access all the node and print it in proper manner.
