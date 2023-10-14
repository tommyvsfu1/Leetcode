using LL = long long;
class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        map<pair<int,int>, int> mp;
        mp[{0,0}] = 1;

        int a = 0;
        int b = 0;
        LL res = 0;
        for (auto ch : s) {
            if (ch == '0') a++;
            else b++;

            int k = min(a/num1, b/num2);
            int r_a = a - k*num1, r_b = b - k*num2;
            if (mp.find({r_a,r_b}) != mp.end()) {
                res += mp[{r_a, r_b}];
            }

            mp[{r_a, r_b}] += 1;
        }
        return res;
    }
};