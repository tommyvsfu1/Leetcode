class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int j = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while(j < n && checkOK(mp, s[j])) {
                j++;
            }
            if (mp.size() <= 2)
                res = max(res, j-i);
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                mp.erase(s[i]);
        }
        return res;
    }
    bool checkOK(unordered_map<char,int>& mp, char c) {
        mp[c]++;
        if (mp.size() > 2) {
            mp[c]--;
            if (mp[c] == 0)
                mp.erase(c);
            return false;
        }
        return true;
    }
};