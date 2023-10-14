// 以下為參考官神的寫法，這個找質數的方法稱為埃拉托斯特尼篩法，簡稱埃氏篩，也稱質數篩
void FindPrimes(int n) {
    vector<int> q(n+1, 0); // q[i] == 0 為質數
    q[0] = q[1] = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (q[i] == 1) continue;

        // 以下寫法看起來有點複雜，但其實就是 2*i, 3*i, ... 的數字都為合數，所以要設為1 
        int j = i * 2;
        while (j <= n) { 
            q[j] = 1;
            j += i;
        }
        
    }
    for (int i = 2; i <= n; i++) {
        if (q[i] == 0)
            primes.insert(i);
    }
}