class Solution {
private:
    bool visited[15];
    int width;
public:
    bool dfs(vector<int>& matchsticks, int index, int curr, int group, bool& res) {
        if (group == 4) {
            return true;
        }

        if (curr > width) {
            return false;
        }
        
        if (curr == width) {
            return dfs(matchsticks, 0, 0, group+1, res);
        }

        for (int i = index; i < matchsticks.size(); i++) {
            if (visited[i] == false) {
                visited[i] = true;
                if (dfs(matchsticks, i+1, curr + matchsticks[i], group, res))
                    return true;
                visited[i] = false;
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
        return dfs(matchsticks, 0, 0, 1, res);

    }
};