class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> mp(3, 0);
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while(j < n && (mp[0]*mp[1]*mp[2] == 0)) {
                if (s[j] == 'a') mp[0]++;
                if (s[j] == 'b') mp[1]++;
                if (s[j] == 'c') mp[2]++;
                j++;
            }

            if (mp[0]*mp[1]*mp[2] != 0) {
                res += (n-1 - j + 1 + 1);
            }
            if (s[i] == 'a') mp[0]--;
            if (s[i] == 'b') mp[1]--;
            if (s[i] == 'c') mp[2]--;
        }
        return res;
    }
};

// X X X X X X X X
//     i     j   n-1