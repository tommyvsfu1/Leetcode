class Prefix2D {
public:
    vector<vector<int>> presum;
    Prefix2D(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        presum.resize(m);
        for (int i = 0; i < m; i++)
            presum[i].resize(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int a = (i > 0) ?  presum[i-1][j] : 0;
                int b = (j > 0) ? presum[i][j-1] : 0;
                int c = (i > 0 && j > 0) ? presum[i-1][j-1] : 0;
                presum[i][j] = A[i][j] + a + b - c;
            }
        }
    }
    int query(int i, int j, int x, int y) {
        int a = (i > 0 && j > 0) ? presum[i-1][j-1] : 0;
        int b = (j > 0) ? presum[x][j-1] : 0;
        int c = (i > 0) ? presum[i-1][y] : 0;
        return presum[x][y] - b - c + a;
    }
};
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        
        Prefix2D Grid(grid);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> stamps(m, vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = i + stampHeight - 1;
                int y = j + stampWidth - 1;
                if (x >= m || y >= n) continue;
                if (Grid.query(i, j, x, y) == 0)
                    stamps[x][y] = 1;
            }
        }

        Prefix2D Stamps(stamps);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
            
                int x = min(m-1, i + stampHeight - 1);
                int y = min(n-1, j + stampWidth - 1);
                if (Stamps.query(i, j, x, y) == 0) return false;
            }
        }
        return true;
    }
};
