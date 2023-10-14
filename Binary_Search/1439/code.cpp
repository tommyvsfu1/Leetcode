class Solution {
private:
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int left = 0;
        int right = INT_MAX;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (checkOK(mat, k, mid)) // >= k
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

    bool checkOK(vector<vector<int>>& mat, int k, int mid) {

        int sum = 0;
        int count = 1;
        for (int i = 0; i < mat.size(); i++)
            sum += mat[i][0];
        
        if (sum > mid) return false;

        dfs(mat, 0, mid, sum, count, k);

        return count >= k;
    }

    void dfs(vector<vector<int>>& mat, int row, int mid, int sum, int& count, int k) {

        if (row >= mat.size()) return;
        if (count > k) return;

        for (int j = 0; j < mat[0].size(); j++) {

            if (sum + mat[row][j] - mat[row][0] <= mid) {
                if (j > 0) count++;
                dfs(mat, row+1, mid, sum + mat[row][j] - mat[row][0], count, k);
            }
            else
                break;

        }

        return;
    }
};