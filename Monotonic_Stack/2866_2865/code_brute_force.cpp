using LL = long long;
class Solution {
public:
    LL calculate(vector<int> maxHeights, int max_index) {
        LL res = 0;
        for (int i = max_index; i >= 1; i--) {
            maxHeights[i-1] = min(maxHeights[i], maxHeights[i-1]);
            res = res + maxHeights[i-1];
        }
        
        for (int i = max_index + 1; i < maxHeights.size(); i++) {
            maxHeights[i] = min(maxHeights[i], maxHeights[i-1]);
            res = res + maxHeights[i];
        }
        
        res = res + maxHeights[max_index];
        return res;
    }
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        LL res = 0;
        for (int i = 0; i < maxHeights.size(); i++) {
            res = max(res, calculate(maxHeights, i));
        }
        return res;
    }
};