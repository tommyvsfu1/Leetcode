標準的binary search by value猜答案  
注意因為=的情況是移動left，故改成left = mid的寫法，所以要把mid的計算方式改成left + (right-left +1)/2

重點:
為何=情況，設計成left = mid，是因為=的情況有兩種，一種是猜小了，一種是真的是答案，所以因為是模糊的，讓left = mid，right = mid - 1，最後夾出答案
為了更快速的去背，GreaterOrEqual()這種題目，就都設計成left = mid ，請背起來!!!!!
