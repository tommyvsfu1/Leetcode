class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs(long(dividend));
        long long b = abs(long(divisor));
        
        long long ans = 0;

        long long sign = 1;
        if (dividend < 0) sign *= -1;
        if (divisor < 0) sign *= -1;

        while (a >= b) {
            long long c = b;
            long long count = 1;
            while ((c << 1) <= a) {
                c = c << 1;
                count = count << 1;
            }
            ans += count;
            a = a - c; 
        }

        ans = ans * sign;

        if (ans > INT_MAX) {
            return INT_MAX;
        }
        
        return ans;

    }
};
