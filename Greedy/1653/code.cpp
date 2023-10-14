class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int> pre(n, 0);
        pre[0] = (s[0] == 'b');
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + (s[i] == 'b');
        }

        vector<int> suf(n, 0);
        suf[n-1] = (s[n-1] == 'a');
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i+1] + (s[i] == 'a');
        }

        int res = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            res = min(res, pre[i] + suf[i+1]);
        }
        res = min(res, pre[n-1]);
        res = min(res, suf[0]);
        return res;

    }
};