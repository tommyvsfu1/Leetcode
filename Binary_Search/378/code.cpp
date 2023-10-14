class Solution {
public:
    int numLessOrEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= mid)
                    count++;
            }
        }

        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        long left = INT_MIN;
        long right = INT_MAX;

        while (left < right) {
            int mid = left + (right - left) / 2;

            int nu = numLessOrEqual(matrix, mid);

            if (nu >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};