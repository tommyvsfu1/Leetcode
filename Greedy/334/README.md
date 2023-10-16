蠻容易想到就是three pass (因為三個indices)\
1. 用monotonic stack 求nextGreater, prevSmaller，最後看每個index的nextGreater和prevSmaller
2. 用prevMin 和 nextMax，跟1很像
3. 找長度為3的LIS (很巧妙的解法)