# Java Code

### dagtest Project

The project contains an example of a Directed Acyclic Graph, It is treated as a tree with n-nodes.

All ID nodes are string of numbers.

It's possible to create a Graph(width,depth), where width represents the number of children.

##### Features

* Graph Creation (automatically)
* BFS and DFS Algorithms

##### Properties

* Name of each node is unique
* The first Node is named 1 always, has 0 depth and no parent
* The children of X is named X.n and so on, the children of X.Y is named X.Y.n
* A child Node has depth 1, higher than its parent
* A node has either zero or one parents
* A Node has 0 children if its depth is greater than or equal to depth, otherwise a Node has exactly width children