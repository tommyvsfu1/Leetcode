class Diff2D {
public:
    int m;
    int n;
    vector<vector<int>> f;
    vector<vector<int>> diff;
    Diff2D(int m, int n) {
        this->m = m;
        this->n = n;
        f.resize(m+1);
        diff.resize(m+1);
        for (int i = 0; i <= m; i++) {
            f[i].resize(n+1);
            diff[i].resize(n+1);
        }
    }
    void set(int i, int j, int x, int y, int val) {
        diff[i][j] += val;
        diff[i][y+1] -= val;
        diff[x+1][j] -= val;
        diff[x+1][y+1] += val;
    }
    void compute() {
        f[0][0] = diff[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up    = (i ? f[i-1][j] : 0);
                int left  = (j ? f[i][j-1] : 0);
                int diag  = (i && j ? f[i-1][j-1] : 0);
                f[i][j] = diff[i][j] + up + left - diag;
            }
        }
    }
};
using LL = long long;
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> PointX;
        set<int> PointY;

        for (auto & rectangle : rectangles) {
            PointX.insert(rectangle[0]);
            PointY.insert(rectangle[1]);
            PointX.insert(rectangle[2]);
            PointY.insert(rectangle[3]);
        }

        vector<int> VecX(PointX.begin(), PointX.end());
        vector<int> VecY(PointY.begin(), PointY.end());

        unordered_map<int,int> X2Idx;
        unordered_map<int,int> Y2Idx;
        for (int i = 0; i < VecX.size(); i++) {
            X2Idx[VecX[i]] = i;
        }
        for (int i = 0; i < VecY.size(); i++) {
            Y2Idx[VecY[i]] = i;
        }

        int m = VecX.size();
        int n = VecY.size();
        Diff2D grid(m, n);
        for (auto & rectangle : rectangles) {
            int i = X2Idx[rectangle[0]];
            int j = Y2Idx[rectangle[1]];
            int x = X2Idx[rectangle[2]];
            int y = Y2Idx[rectangle[3]];
            grid.set(i, j, x-1, y-1, 1);
        }

        grid.compute();

        LL res = 0;
        int Mod = 1e9 + 7;

        for (int i = 0; i < m-1; i++) {
            for (int j = 0; j < n-1; j++) {
                if (grid.f[i][j] > 0) {
                    LL dx = VecX[i+1] - VecX[i];
                    LL dy = VecY[j+1] - VecY[j];
                    res = (res + (dx * dy) % Mod) % Mod;
                }
            }
        }
        return res;
    }
};
