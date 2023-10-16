class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> leftMoves(n, 0);
        int left = 0;
        for (int i = 1; i < n; i++) {
            left += (boxes[i-1] == '1');
            leftMoves[i] = leftMoves[i-1] + left;
        }

        vector<int> rightMoves(n, 0);
        int right = 0;
        for (int i = n - 2; i>=0; i--) {
            right += (boxes[i+1] == '1');
            rightMoves[i] = rightMoves[i+1] + right;
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            res[i] = leftMoves[i] + rightMoves[i];
        }
        return res;
    }
};