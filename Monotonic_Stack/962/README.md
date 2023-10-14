比較直觀的想法是binary search，就是直接建立一個遞減序列，如果遇到比最後一個元素更大的元素，就做binary search，然後算width  

比較不直觀的方法是先建立一個遞減的stack，然後由後往前遍歷nums，只要遇到nums[i]比目前stack top還大的元素，就退棧(因為題目要求maximum width，所以由後往前就確保當nums[i]比stack top還大的時候，i-st.top()會是對於st.top()所構成最大的width，所以就可以退棧了)