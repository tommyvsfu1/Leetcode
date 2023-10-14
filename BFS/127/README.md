"建graph完後BFS
關鍵是string compare的部分，直接從每個word的character改變後，來看有沒有存在於wordList裡面，
也就是用c++內建的string compare方式 (不要直接比較兩個string 是不是差一個character，會TLE)"