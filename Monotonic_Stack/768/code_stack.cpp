class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;

        int currMax = 0;
        for (auto a : arr) {
            if (st.empty() || st.top() <= a) {
                st.push(a);
                currMax = a;
            }
            else {
                while(!st.empty() && st.top() > a)
                    st.pop();
                st.push(currMax);
            }
        }
        return st.size();
    }
};