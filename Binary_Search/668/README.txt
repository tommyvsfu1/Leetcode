1. 需要發現這是sorted matrix 題目，這樣可以直接想到用binary search
2. 再來是要猜一個數是top-K in sorted matrix，可以透過min(x/i, n)加總，注意這會考量到所有重複的x
