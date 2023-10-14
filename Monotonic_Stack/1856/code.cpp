class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }  

        vector<long long> presum(n, 0);
        presum[0] = nums[0];
        for (int i = 1; i < n; i++)
            presum[i] = presum[i-1] + (long long)nums[i];
        

        long long res = 0;
        for (int i = 0; i < n; i++) {
            int a = prevSmaller[i];
            int b = nextSmaller[i];
            // subarry sum [a+1, b-1] = prefixSum[b-1] - prefixSum[a]
            long long subarray_sum = (long long)presum[b-1] - (long long)((a == -1) ? 0 : presum[a]); 
            long long curr = (long long)nums[i] * subarray_sum;
            res = max(res, curr);
        }

        long long M = 1e9 + 7;
        return res % M;
    }
};