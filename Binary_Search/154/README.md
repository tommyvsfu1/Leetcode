二分搜索  
關鍵在於  
1. 用nums[mid] > nums[right] 來判斷原本index 0是在mid的右邊 (反之，則會在mid的左邊)  
2. 透過right--來消除無用的數字  