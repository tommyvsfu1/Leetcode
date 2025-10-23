class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        map<int, vector<pair<int,int>>> Map;
        set<int> Set;

        for (int i = 0; i < paint.size(); i++) {
            int start = paint[i][0];
            int end = paint[i][1];
            Map[start].push_back({i, 1});
            Map[end].push_back({i, -1});
        }

        int n = paint.size();
        vector<int> res(n, 0);
        vector<pair<int, vector<pair<int,int>>>> array(Map.begin(), Map.end());
        for (int i = 0; i < array.size(); i++) {
            int pos = array[i].first;
            for (auto &p : array[i].second) {
                if (p.second == 1) {
                    Set.insert(p.first);
                }
                else {
                    Set.erase(p.first);
                }
            }
            if (!Set.empty()) {
                res[*Set.begin()] += (array[i+1].first - pos);
            }
        }
        return res;
    }
};

// 1,0
// 4,0
// 4,2
// 5,1
// 7,2
// 8,1
