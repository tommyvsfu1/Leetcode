class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        map<int, vector<pair<int,int>>> Map;
        for (auto &update : updates) {
            int start = update[0];
            int end = update[1];
            int diff = update[2];
            Map[start].push_back({diff, 1});
            Map[end+1].push_back({diff, -1});
        }

        int pre = 0;
        vector<int> res(length, 0);
        for (int i = 0; i < length; i++) {
            if (Map.find(i) != Map.end()) {
                for (auto& [diff, p] : Map[i]) {
                    if (p == 1) {
                        pre += diff;
                    }
                    else {
                        pre -= diff;
                    }
                }
            }
            res[i] = pre;
        }
        return res;
    }
};
