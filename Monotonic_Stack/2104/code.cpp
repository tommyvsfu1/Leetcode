using LL = long long;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> st;
        vector<int> nextGreaterOrEqual(n, n);
        for (int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                nextGreaterOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> nextSmallerOrEqual(n, n);
        for (int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                nextSmallerOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        vector<int> prevGreater(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                prevGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        
        vector<int> prevSmaller(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        LL res = 0;
        for (int i = 0; i < n; i++) {
            int l = prevSmaller[i];
            int r = nextSmallerOrEqual[i];

            res -= (LL)nums[i] * (i-l) * (r-i);

        }
        for (int i = 0; i < n; i++) {
            int l = prevGreater[i];
            int r = nextGreaterOrEqual[i];

            res += (LL)nums[i] * (i-l) * (r-i);
        }

        return res;
    }
};