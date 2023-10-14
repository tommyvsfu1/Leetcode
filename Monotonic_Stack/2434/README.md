這題其實看到題目的兩種operation會蠻直覺發現是一個stack  
再來關鍵是  
1. 比較st.top() 和 剩餘的字符，先把比較小的拿來當作res比較前面的字符。如果比較小的字符是在剩餘的字符裡，就繼續加入stack  
2. 用suffix min來快速判斷剩餘字符中最小的字符  
>這題算是結合greedy思想的stack問題，但必須想到用suffix min來快速判斷