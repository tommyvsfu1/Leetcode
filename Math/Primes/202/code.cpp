class Solution {
public:
    int next(int n) {
        int res = 0;
        while (n != 0) {
            int p = n % 10;
            res += (p * p);
            n = n / 10;
            
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> Set;
        while (n != 1 && Set.find(n) == Set.end()) {
            Set.insert(n);
            n = next(n);   
        }
        return n == 1;
    }
};