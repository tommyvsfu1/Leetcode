class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int res = 0;

        int j = 0; // right pointer
        int flip = 0;
        for (int i = 0; i < n; i++) {
            while(j < n && ( answerKey[j] == 'T' || flip < k)) {
                if (answerKey[j] == 'F')
                    flip++;
                j++;
            }
            res = max(res, j-i);
            if (answerKey[i] == 'F')
                flip--;
        }

        j = 0; // right pointer
        flip = 0;
        for (int i = 0; i < n; i++) {
            while(j < n && ( answerKey[j] == 'F' || flip < k)) {
                if (answerKey[j] == 'T')
                    flip++;
                j++;
            }
            res = max(res, j-i);
            if (answerKey[i] == 'T')
                flip--;
        }
        return res;
    }
};