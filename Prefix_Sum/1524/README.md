概念是說，當算到prefix[i]時，如果prefix[i]是偶數，那麼如果以前算過的prefix[j]是奇數，就能讓prefix[i] - prefix[j]是奇數。而如果prefix[i]是奇數，那就是看prefix[j]是偶數的數量。 最後就是記得初始化的時候，evenCount = 1，因為如果prefix[i]是奇數，並且是考慮整個array的時候也要算進來。\
