我覺得蠻不好想的，首先要有個概念就是要如果要好好利用type-1 operation，那到底何時會可以用type 1 operation 而不需要用type 2? 答案就是 string可以分成 兩個子字串，各個子字串都是01交錯的，只是兩個子字串的端點不是01交錯，這時候就可以把前面的子字串移到第二個子字串後面
101010  0101  => 0101 101010 \
所以其實我們真的要尋找的就是可以把每個index當作一個分界點，然後把左右子字串轉換成01交錯，看看哪個index需要最少的operation