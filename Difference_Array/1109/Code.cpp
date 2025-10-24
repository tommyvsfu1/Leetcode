class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        map<int, vector<pair<int,int>>> Map;
        for (auto &booking : bookings) {
            int start = booking[0];
            int end = booking[1];
            int reserve = booking[2];
            Map[start].push_back({reserve, 1});
            Map[end+1].push_back({reserve, -1});
        }

        int pre = 0;
        vector<int> res(n, 0);
        for (int i = 1; i <= n; i++) {
            if (Map.find(i) != Map.end()) {
                for (auto &[diff, p] : Map[i]) {
                    if (p == 1) {
                        pre += diff;
                    }
                    else {
                        pre -= diff;
                    }
                }
            }
            res[i-1] = pre;
        }
        return res;
    }
};
