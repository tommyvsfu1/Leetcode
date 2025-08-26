Since this is a BST, all values in the left subtree are smaller than the current node, and all values in the right subtree are larger.

If both p and q are smaller than the current node, move left.

If both are larger, move right.

Otherwise, the current node is the LCA.
