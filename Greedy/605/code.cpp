class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res = 0;
        flowerbed.push_back(0);
        int k = flowerbed.size();
        int i = 0;
        while(i < k) {
            int j = i;

            while(j < k && flowerbed[j] != 1) {
                j++;
            }

            int num = j-i;

            res += (num / 2);

            i = j + 2;
        }
        return res >= n;
    }
};