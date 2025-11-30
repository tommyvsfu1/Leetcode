class Solution {
public:
    bool isPowerOfThree(int n) {
        int dividend = n;
        if (n <= 0) return false;
        while (dividend != 1) {
            if (dividend % 3 != 0) return false;
            dividend /= 3;
        }
        return true;
    }
};