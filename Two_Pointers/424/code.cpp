class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> mp(26, 0);

        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && checkOK(mp, s, j, j-i+1, k))
                j++;
            res = max(res, j-i);
            mp[s[i]-'A']--;
        }

        return res;

    }
    bool checkOK(vector<int>& mp, string& s, int j, int L, int k) {
        mp[s[j]-'A']++;
        int maxCount = *max_element(mp.begin(), mp.end());
        if (L - maxCount <= k)
            return true;
        
        mp[s[j]-'A']--;
        return false;
    }
};