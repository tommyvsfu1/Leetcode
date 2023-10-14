using LL = long long;
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        
        stack<int> st;
        vector<int> nextSmaller(n, -1);
        vector<int> prevSmaller(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && maxHeights[st.top()] >= maxHeights[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }


        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && maxHeights[st.top()] >= maxHeights[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<LL> leftSum(n, 0);
        vector<LL> rightSum(n, 0);
        leftSum[0] = maxHeights[0];
        for (int i = 1; i < n; i++) {
            int prev = prevSmaller[i];
            if (prev != -1) {
                LL count = i - prev;
                leftSum[i] += count * maxHeights[i];
                leftSum[i] += leftSum[prev];
            }
            else {
                LL count = i + 1;
                leftSum[i] += maxHeights[i] * count;
            }
        }
        rightSum[n-1] = maxHeights[n-1];
        for (int i = n - 2; i >= 0; i--) {
            int next = nextSmaller[i];
            if (next != -1) {
                LL count = next - i;
                rightSum[i] += count * maxHeights[i];
                rightSum[i] += rightSum[next];
            }
            else {
                LL count = n - i;
                rightSum[i] += maxHeights[i] * count;
            }
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long area = (LL)leftSum[i] + (LL)rightSum[i] - (LL)maxHeights[i];
            res = max(res, area);
        }
        return res;
    }
};