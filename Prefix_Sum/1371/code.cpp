class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp; // state -> index
        mp[0] = -1;
        int state = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') state = state ^ (1 << 4);
            else if (s[i] == 'e') state = state ^ (1 << 3);
            else if (s[i] == 'i') state = state ^ (1 << 2);
            else if (s[i] == 'o') state = state ^ (1 << 1);
            else if (s[i] == 'u') state = state ^ (1 << 0);

            if (mp.find(state) != mp.end()) {
                res = max(res, i - mp[state]);
            }

            if (mp.find(state) == mp.end())
                mp[state] = i;
        }
        return res;
    }
};

