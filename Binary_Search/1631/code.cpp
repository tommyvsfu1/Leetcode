class Solution {
private:
    bool visited[100][100];
public:
    void dfs(vector<vector<int>>& heights, int i, int j, int mid) {
        int m = heights.size();
        int n = heights[0].size();
        visited[i][j] = true;
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        for (auto d : dir) {
            int x = i + d.first;
            int y = j + d.second;
            if (x < 0 || y < 0 || x >= m || y >= n) continue;
            if (visited[x][y]) continue;
            if (abs(heights[i][j] - heights[x][y]) > mid) continue;
            dfs(heights, x, y, mid);
        }
    }
    bool isOk(vector<vector<int>>& heights, int mid) {
        int m = heights.size();
        int n = heights[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        dfs(heights, 0, 0, mid);

        return visited[m-1][n-1] == true;

    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0;
        int right = 1e6;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isOk(heights, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};