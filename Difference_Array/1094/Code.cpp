class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001];

        for (int i = 0; i < trips.size(); i++) {
            diff[trips[i][1]] += trips[i][0];
            diff[trips[i][2]] -= trips[i][0];
        }

        int pre = 0;
        for (int i = 0; i <= 1000; i++) {
            pre += diff[i];
            if (pre > capacity) return false;
        }
        return true;
    }
};
