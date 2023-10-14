經典題，subarray equal to K的問題  
把0當作-1，這樣當有相同的0和1時，sum就會等於0  
而這種題目可以用hash map來記錄上一次達到相同sum時的index  
比如說 如果hash map 有presum[i]的key，代表[mp[presum[i]]+1, i]這個區間是一個subarray equal to 0，也就是擁有相同數量的0和1(因為我們已經把0視為-1了) 