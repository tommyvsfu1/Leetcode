標準的binary search by value猜答案  
注意因為=的情況是移動left，故改成left = mid的寫法，所以要把mid的計算方式改成left + (right-left +1)/2