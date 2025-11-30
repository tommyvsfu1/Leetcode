class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        int q = n;
        while (q != 1) {
            if (q % 2 != 0 && q%3 != 0 && q%5 != 0) return false;
            if (q % 2 == 0) q = q / 2;
            else if (q % 3 == 0) q = q / 3;
            else if (q % 5 == 0) q = q / 5;
        }
        return true;
    }
};