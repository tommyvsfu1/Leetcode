using LL = long long;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        stack<int> st;

        vector<int> nextSmallerOrEqual(n, n);
        vector<int> prevSmaller(n, -1);

        for (int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                nextSmallerOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        LL res = 0;

        for (int i = 0; i < n; i++) {
            int r = nextSmallerOrEqual[i];
            int l = prevSmaller[i];

            res += (LL)arr[i] * (r-i) * (i-l);
        }

        LL M = 1e9 + 7;
        return res % M;

    }
};