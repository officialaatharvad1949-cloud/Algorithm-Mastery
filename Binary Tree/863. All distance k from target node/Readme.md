Given the root of a binary tree, the value of a target node target,
and an integer k, return an array of the values of all nodes that have a distance k from the target node.

Main intuition: While it is possible to find and or get the target node. And we can furthur traverse into their child to find out the node k distance from
the target.Main bottleneck of this problem is to traverse from child to parents.
To solve this bottleneck , we can simply map the parents and their child using any traversal technique . 
Once we map all the parent / child pair , we can define the vis map to keep track of repeated node . Then we can traverse in all three direction and findout
the nodes which are at distance k from the target node 
