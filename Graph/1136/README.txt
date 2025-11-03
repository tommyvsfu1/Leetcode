topological sort
1. res : 剝洋蔥次數(因為topological sort就是每層剝洋蔥，題目要求的就是要剝幾次)
2. visited: topological sort不需要visited，但這題要判斷有沒有cycle(e.g. 3->4, 4->3)
因為topological sort加入的node要是indegree == 0，有cycle的node indegree永遠不為0，所以利用這個特性，用visited來判斷是否有cycle
