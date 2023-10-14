class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        if (q.size() == 0 || q.size() == (n*n)) return -1;

        vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        int time = -1;
        while(!q.empty()) {
            time++;
            int len = q.size();
            while(len--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (auto d : dir) {
                    int x = i + d.first;
                    int y = j + d.second;
                    if (x < 0 || y < 0 || x >= n || y >= n) continue;
                    if (grid[x][y] == 0 && visited[x][y] == 0) {
                        visited[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
        }

        return time;
        
    }
};