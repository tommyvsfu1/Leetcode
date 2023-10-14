class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        vector<int> mp(1024, 0);
        int state = 0;
        mp[0] += 1;

        long long res = 0;
        for (int i = 0; i < n; i++) {
            state = state ^ (1 << (word[i]-'a'));

            res += mp[state];
            for (int k = 0; k < 10; k++) {
                int stateJ = state ^ (1 << k);
                res += mp[stateJ];
            }

            mp[state] += 1;
        }

        return res;

        
    }
};