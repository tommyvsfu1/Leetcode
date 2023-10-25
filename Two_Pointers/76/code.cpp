class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        unordered_map<char, int> mp;
        for (char &c : t) {
            table[c] += 1;
        }
        int n = s.size();
        int j = 0;
        int res_len = 0;
        int res_start = 0;
        int Len = INT_MAX;
        int count = 0;
        int M = table.size();
        for (int i = 0; i < n; i++) {
            while (j < n) {
                if (count == M)
                    break;
                mp[s[j]]++;
                if (mp[s[j]] == table[s[j]])
                    count++;
                j++;
            }
            if (count == M) {
                if (Len > j-i) {
                    Len = j-i;
                    res_len = Len;
                    res_start = i;
                }
            }
            mp[s[i]]--;
            if (mp[s[i]] == table[s[i]] - 1)
                count--;

        }
        return s.substr(res_start, res_len);
    }
};