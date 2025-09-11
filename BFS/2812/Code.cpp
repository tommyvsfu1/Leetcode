using PII = pair<int,int>;
class Solution {
public:
    vector<PII> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int ret;
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<PII> q;
        //vector<vector<int>> back(n, vector<int>(n, 0));
        //vector<vector<int>> visited(n, vector<int>(n, 0));


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    //back[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [x,y] = q.front();
                for (int k = 0; k < 4; k++) {
                    int i = x + dir[k].first;
                    int j = y + dir[k].second;

                    if (i < 0 || i >= n || j < 0 || j >= n) continue;
                    if (grid[i][j] != 0) continue;

                    grid[i][j] = grid[x][y] + 1;
                    q.push({i,j});
                }
                q.pop();
            }
        }
        int left = 0;
        int right = 2 * n;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            if (isOK(mid, grid)) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
    bool isOK(int d, vector<vector<int>>& grid) {
        int n = grid.size();
        queue<PII> q;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        if (grid[0][0] <= d) return false;

        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()) {
            auto [x,y] = q.front();
            
            for (int k = 0; k < 4; k++) {
                int i = x + dir[k].first;
                int j = y + dir[k].second;

                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (visited[i][j]) continue;
                if (grid[i][j] <= d) continue;

                if (i == n-1 && j == n-1) return true;

                visited[i][j] = 1;
                q.push({i,j});
            }
            q.pop();
        }
        return false;
    }
    // void dfs(int i, int j, int dist, vector<vector<int>>& visited, vector<vector<int>>& grid, vector<vector<int>>& back) {
    //     int n = grid.size();
    //     if (i < 0 || i >= n || j < 0 || j >= n) return;
    //     if (visited[i][j] == 1) return;
    //     if (back[i][j] == 1) return;

    //     if (i == n-1 && j == n-1) {
    //         dist = max(ret, dist);
    //         return;
    //     }

    //     dist = min(dist, grid[i][j]);
    //     visited[i][j] = 1;
    //     dfs(i+1,j,dist,visited, grid, back);
    //     dfs(i-1,j,dist,visited, grid, back);
    //     dfs(i,j+1,dist,visited, grid, back);
    //     dfs(i,j-1,dist,visited, grid, back);
    // }
};
