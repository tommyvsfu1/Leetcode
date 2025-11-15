1. minimum value ，並且valid string會隨著t變大而遞增，可以用binary search by value來猜答案
2. 每次猜答案時，為了要快速計算有多少個valid string，可以去計算不包含*的substring，很像排列組合的問題， #valid string = #所有組合 - #不包含*的substring


重點: count function裡面不熟悉two pointers寫法，要多練習 (2025/11/15)
