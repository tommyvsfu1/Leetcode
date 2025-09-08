Brute Force method
For each query, we find the distances between the node and all the other nodes. 
And perform depth first search from start node until finding the end node. 
Then, we can find the closest node to the node in the path based on the preprocessing information.

Another method
1. Contruct a 2D matrix cotaining the distances between all the nodes.
2. Travsing the path from start to end, and calculate the closest node to the given node in the path.
-> We can efficiently traverse the path by the relation matrix[cur][end] = matrix[nxt][end] + 1 (Because the path will be the shortest path, so we can ensure the relation)
