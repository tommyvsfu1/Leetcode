Idea
1. Multiplication operation can be represented by bit manipulation (Because any number can be represented in binary format)
E.g. 3 = 1 << 2 + 1 << 0
E.g. 15 = 1 << 3 + 1 << 2 + 1 << 1 + 1 << 0

2. Since quotient * dividor = dividend, we can represent the multiplication into bit manipulation with for loop

3. 因為dividend / dividor 最小是-2^31，最大是2^31，而c++ int 最小是-2^31，最大只有到2^31 - 1
所以只有upper bound會overflow，所以最後要考慮 > INT_MAX的情況，不需考慮 < INT_MIN
