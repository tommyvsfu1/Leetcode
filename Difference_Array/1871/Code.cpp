class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        int n = s.size();
        vector<int> diff(n+1, 0);

        diff[0+minJump] = 1;
        diff[0+maxJump+1] = -1;

        int reach = 0;
        for (int i = 0; i < n; i++) {
            reach += diff[i];
            if (s[i] == '1') continue;
            if (reach == 0) continue;

            if (i + minJump <= n)
                diff[i+minJump] += 1;
            if (i + maxJump + 1 <= n)
                diff[i+maxJump+1] -= 1;
        }

        return reach;
    }
};



