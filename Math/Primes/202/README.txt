
factorization概念 + hash set (或slow, fast pointer)
概念: 將一個數的digit^2 加總，最後一定會落在
0 ~ (9^2 * 10 = 810) 區間，並且會進行週期性的收斂序列 (鴿籠原理)
所以可以用hash set或slow,fast pointer來判斷何時發生收斂(重複) ，同時判斷是否==1
