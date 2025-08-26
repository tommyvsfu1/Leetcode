class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;

        for (auto& q : queries) {
            int a = q[0];
            int b = q[1];
            int count = 0;
            while (a != b) {
                if (a > b) {
                    a = a / 2;
                }
                else {
                    b = b / 2;
                }
                count++;
            }
            res.push_back(count + 1);
        }
        return res;
    }
};
