1. 因為t是monotonic increase，所以很直觀會想用binary search by value猜答案
2. 這題困難的是證明一個given t，可以mark所有elements，因為有可能存在多個strategies來mark elements
但一定有一個可行的strategy -> greedy方式: 最後再mark，前面盡可能去把element進行--
