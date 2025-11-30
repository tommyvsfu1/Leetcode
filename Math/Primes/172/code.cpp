class Solution {
public:
    void count(int x, vector<int>& res) {
        int count2 = 0;

        while (x % 2 ==0) {
            count2++;
            x = x / 2;
        }

        int count5 = 0;

        while (x % 5 == 0) {
            count5++;
            x = x / 5;
        }
        
        res[0] += count2;
        res[1] += count5;
    }
    int trailingZeroes(int n) {

        vector<int> res(2, 0);

        for (int i = n; i >= 1; i--) {
            count(i, res);
        }      

        return min(res[0], res[1]);
    }
};