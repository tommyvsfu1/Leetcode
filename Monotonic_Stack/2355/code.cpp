using LL = long long;
class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<LL> dp(n);
        stack<int> st;
        LL res = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && books[st.top()] > books[i] - (i-st.top())) {
                st.pop();
            }

            if (!st.empty()) {
                LL d = i - st.top();

                dp[i] = dp[st.top()] + (d * ((LL)books[i] + (LL)books[i] - (d-1)))/ 2;
            }
            else {
                LL d = min(i+1, books[i]);
                dp[i] = (d * ((LL)books[i] + (LL)books[i] - (d-1))) / 2;
            }
            
            st.push(i);
            res = max(res, dp[i]);

        }

        return res;
    }
};