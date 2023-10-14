binary search部分，浮點數的寫法要稍微背一下    
比如left = mid, right = mid，因為浮點數的情況，每次mid都會是介於left跟right的數字     

然後while loop裡面count的時候，可以再用binary search來更快的count  
nums[i] / nums[j] <= mid  
nums[j] >= nums[i] / mid  
尋找所有的nums[j]   


第二個方法就是用priority queue，就無腦把fraction放進pq裡面就好