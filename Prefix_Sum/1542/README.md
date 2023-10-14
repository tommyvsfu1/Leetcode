關鍵在於make any number of swaps in order to make it a palindrome == at most one character apperas an odd number of times in the substring\
所以其實跟1915幾乎差不多，還有再三強調只要是區間和, 區間頻次，都很常會用到prefix sum的技巧\
和1915一樣，因為prefix sum我們只在意奇偶性，且需要統計多種有限個字符的奇偶性，所以可以把prefix sum用state compression的技巧來表示，這樣會很方便統計跟計算\

word[j:i]如果要是最多只有一個字符是奇數\
1. 有可能所有字符都是偶數 -> prefix[i] - prefix[j-1] 要是偶數 (也就代表prefix[i] 跟 prefix[j-1] 都是奇數或偶數，如果從state compression的角度就代表bit mask完全一樣)\
2. 只有一個字符是奇數 (代表bit mask 只差一個位元)\

最後因為要求longest substring，所以hash map裡面存最小的index就可以了
