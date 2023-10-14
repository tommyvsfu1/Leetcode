class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long eventCount = 1, oddCount = 0;
        int res = 0;
        long prefix = 0;
        long M = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            prefix += arr[i];

            if (prefix % 2 == 0) {
                res += oddCount; 
            }
            else {
                res += eventCount;
            }
            res = res % M;

            if (prefix % 2 == 0) {
                eventCount += 1;
            }
            else {
                oddCount += 1;
            }
        }
        return res;
    }
};