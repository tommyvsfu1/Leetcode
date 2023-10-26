class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int res = 0;
        int j = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            while(j < s.size() && checkOK(mp, s[j], k)) {
                j++;
            }
            res = max(res, j-i);

            mp[s[i]]--;
            if (mp[s[i]] == 0)
                mp.erase(s[i]);
        }
        return res;

    }
    bool checkOK(unordered_map<char, int>& mp, char c, int k) {
        mp[c]++;
        if (mp.size() > k) {
            mp[c]--;
            if (mp[c] == 0)
                mp.erase(c);
            return false;
        }
        return true;
    }
};