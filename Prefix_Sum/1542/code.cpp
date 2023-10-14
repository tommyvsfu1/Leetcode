class Solution {
public:
    int longestAwesome(string s) {
        
        unordered_map<int, int> mp;
        int state = 0;
        mp[0] = -1;

        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            state = state ^ (1 << (s[i]-'0'));

            if (mp.find(state) != mp.end()) {
                res = max(res, i - mp[state]);
            }

            for (int k = 0; k < 10; k++) {
                int stateJ = state ^ (1 << k);
                if (mp.find(stateJ) != mp.end()) {
                    res = max(res, i - mp[stateJ]);
                }
            }

            if (mp.find(state) == mp.end())
                mp[state] = i;
        }

        return res;
    }
};