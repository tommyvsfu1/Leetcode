class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<int> hist(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    hist[j] += 1;
                else
                    hist[j] = 0;
            }
            res = max(res, maximalHistogram(hist));
        }

        return res;
    }
    int maximalHistogram(vector<int> hist) {
        hist.insert(hist.begin(), 0);
        hist.push_back(0);
        stack<int> st;
        int res = 0;
        for (int i = 0; i < hist.size(); i++) {
            while(!st.empty() && hist[st.top()] > hist[i]) {
                int H = hist[st.top()];
                st.pop();
                int area = H * (i - st.top() - 1);
                res = max(res, area);
            }
            st.push(i);
        }
        return res;
    }
};