class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (firstList[i][1] < secondList[j][0])
                i++;
            else if (secondList[j][1] < firstList[i][0])
                j++;
            else {
                int start = max(firstList[i][0], secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]);

                res.push_back({start, end});
                if (firstList[i][1] < secondList[j][1])
                    i++;
                else
                    j++;
            }
        }
        return res;
    }
};