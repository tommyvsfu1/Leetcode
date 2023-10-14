class Solution {
private:
    int sides[4];
    int width;
public:
    bool dfs(vector<int>& matchsticks, int index, bool& res) {
        if (index >= matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= width) {
                sides[i] += matchsticks[index];
                if (dfs(matchsticks, index+1, res))
                    return true;
                sides[i] -= matchsticks[index];
            }
        }

        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end());
        bool res = false;
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;

        width = total / 4;
        
        res = dfs(matchsticks, 0, res);

        return res;
    }
};