class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> Set;
        int res = 0;

        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            while (j < s.size() && Set.find(s[j]) == Set.end()) {
                Set.insert(s[j]);
                j++;
            }
            res = max(res, (int)Set.size());
            Set.erase(s[i]);
        }
        return res;
    }
};
