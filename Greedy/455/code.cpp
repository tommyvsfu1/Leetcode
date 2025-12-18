class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        if (s.size() == 0) return 0;
        if (g.size() == 0) return 0;
        if (s.back() < g[0]) return 0;

        // int res = 0;
        // int j = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     j = res;
        //     while (j < g.size()) {
        //         if (s[i] >= g[j]) {
        //             res++;
        //             break;
        //         }
        //         else {
        //             j++;
        //         }
        //     }
        // }
        int res = 0;
        int j = 0;
        for (int i = 0; i < g.size(); i++) {
            auto it = lower_bound(s.begin() + j, s.end(), g[i]);
            if (it != s.end()) {
                res++;
                int k = distance(s.begin(), it);
                j = k + 1;
            }
        }
        return res;
    }
};