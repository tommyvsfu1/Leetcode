class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<int> q(n+1, 0);

        q[0] = 1;
        if (n >= 2)
            q[1] = 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (q[i] == 1) continue;

            int j = 2;
            while ((j * i) <= n) {
                q[j * i] = 1;
                j++;
            }

        }

        for (int i = 2; i < n; i++) {
            if (q[i] == 0) res++;
        }

        return res;
    }
};
