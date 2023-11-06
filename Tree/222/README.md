O(n)就直接DFS就好了\
如果要更快，可以用binary search來檢驗最後一個level\
或是把complete binary tree拆成root, 左子樹和右子樹，如果左子樹的left Depth, right Depth相等，那就可以快速求出左子樹的節點數目，如果不相等，那代表右子樹一定是顆complete binary tree，所以也可以快速求出節點數目。而剩餘的部分就遞迴