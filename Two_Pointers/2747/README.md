這題在玩文字遊戲，logs基本上就是每台server收到的requests時間點\
而queries本身沒有意義，它只是問你對於每個區間 [queries[i]-x, queries[i]]，有多少台server在這個區間沒有收到request\
所以本質上這個題目很像interval問題(實作上比較像滑窗) 