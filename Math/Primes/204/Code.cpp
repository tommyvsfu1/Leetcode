class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n, 1);

        if (n == 0 || n == 1) return 0;

        primes[0] = 0;
        primes[1] = 0;

        for (int i = 2; i * i < n; i++) {
            if (primes[i] == 1) {
                int j = i * i;
                while (j < n) {
                    primes[j] = 0;
                    j+=i;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (primes[i] == 1) {
                res++;
            }
        }
        return res;
    }
};