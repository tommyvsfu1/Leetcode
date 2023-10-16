class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        vector<int> left01(n, 0);
        vector<int> left10(n, 0);
        vector<int> right01(n, 0);
        vector<int> right10(n, 0);

        int countLeft01 = 0;
        int countLeft10 = 0;
        for (int i = 0; i < n; i++) {
            if ( (i % 2 == 0 && s[i] == '1') || (i % 2 != 0 && s[i] == '0') )
                countLeft01++;
            if ( (i % 2 == 0 && s[i] == '0') || (i % 2 != 0 && s[i] == '1') )
                countLeft10++;
            left01[i] = countLeft01;
            left10[i] = countLeft10;        
        }

        int countRight01 = 0;
        int countRight10 = 0;
        for (int i = n-1; i >= 0; i--) {
            int j = n - 1 - i;
            if ( (j % 2 == 0 && s[i] == '1') || (j % 2 != 0 && s[i] == '0') )
                countRight01++;
            if ( (j % 2 == 0 && s[i] == '0') || (j % 2 != 0 && s[i] == '1') )
                countRight10++;
            right01[i] = countRight01;
            right10[i] = countRight10;        
        }

        int res = INT_MAX;
        res = min(res, left01[n-1]);
        res = min(res, left10[n-1]);
        for (int i = 0; i < n-1; i++) {
            res = min(res, left01[i] + right10[i+1]);
            res = min(res, left10[i] + right01[i+1]);
        }
        return res;

    }
};