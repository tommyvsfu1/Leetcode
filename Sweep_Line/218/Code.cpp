class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<pair<int,int>>> Map;
        for (auto &building : buildings) {
            Map[building[0]].push_back({building[2], 1});
            Map[building[1]].push_back({building[2], -1});
        }

        multiset<int> Set;
        vector<vector<int>> res;
        for (auto &[pos, v] : Map) {
            for (auto &pair : v) {
                if (pair.second == 1) {
                    Set.insert(pair.first);
                }
                else {
                    Set.erase(Set.find(pair.first));
                }
            }
            int H = Set.empty() ? 0 : *Set.rbegin();
            if (res.empty() || res.back()[1] != H) {
                res.push_back({pos, H});
            }
        }
        return res;
    }
};
