這題關鍵在於要看出題目的意思其實就是選擇兩個數nums[i],nums[j]然後同時把兩數的k-th bit設為0\
而如果一個區間beautiful，代表其實這個區間的所有元素，有偶數個元素在i-th bit是1\
所以其實我們可以把state compression的技巧來表示一個區間在每個bit的奇偶性，在這樣的表示法下，代表我們要找的居間[j,i]，是一個滿足presum[i] - presum[j-1] = 0