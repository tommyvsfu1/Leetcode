class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> presum({0});

        int sum = 0;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] > 8)
                sum+=1;
            else
                sum-=1;
            presum.push_back(sum);
        }

        stack<int> st;
        for (int i = 0; i < presum.size(); i++) {
            if (st.empty() || presum[st.top()] > presum[i]) {
                st.push(i);
            }
        }

        int res = 0;
        for (int i = presum.size() - 1; i>= 0; i--) {
            while(!st.empty() && presum[st.top()] < presum[i]) {
                res = max(res, i - st.top());
                st.pop();
            }
        }
        return res;

    }
};