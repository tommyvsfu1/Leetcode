class Solution {
public:
    int maximizeWin(vector<int>& p, int k) {
        int n = p.size();

        if (p[n-1] - p[0] <= 2*k) return p.size();

        vector<int> pre(n);
        vector<int> suf(n);

        int i = 0;
        int mx = 0;
        for (int j = 0; j < n; j++) {
            while(p[j] - p[i] > k)
                i++;
            int len = j-i+1;
            mx = max(mx, len);
            pre[j] = mx;
        }

        mx = 0;
        int j = n-1;
        for (int i = n-1; i>=0; i--) {
            while(p[j] - p[i] > k)
                j--;
            int len = j - i + 1;
            mx = max(mx, len);
            suf[i] = mx;
        }

        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            res = max(res, pre[i] + suf[i+1]);
        }
        return res;


    }
};