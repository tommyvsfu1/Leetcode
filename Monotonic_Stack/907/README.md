算是反向思路的解法，所有subarray的組合 = 把每個index作為最小值所能產生的subarray的互斥聯集 
從最小值來建立subarray，更準確來說是盡量擴張左邊界和右邊界，使得能產生越多種subarray越好  
在找左邊界跟右邊界時，就是要找其他更小的值(因為不能包含到那些更小的值)  

另外這題有個要注意的地方是為了避免重複算到subarray，要規定next smaller 或 prev smaller某一邊可以有等號