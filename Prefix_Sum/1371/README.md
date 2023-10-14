想法: 首先區間頻次想到可以用prefix sum + hash map，再來因為看到奇偶配合多種有限字符，馬上想到可以用state compression，具體解法如下 
sum(arr[j:i]) even \
presum[i] - presum[j-1] even \ 
presum[i] and presum[j-1] are even or presum[i] and presum[j-1] are odd \
Given presum[i], find interested presum[j-1] \
Use state compression with hash map to check in O(1) 