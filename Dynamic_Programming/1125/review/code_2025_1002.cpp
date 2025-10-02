class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        unordered_map<string, int> skill2idx;
        for (int i = 0; i < req_skills.size(); i++) {
            skill2idx[req_skills[i]] = i;
        }

        unordered_map<int, int> p2s;
        for (int i = 0; i < people.size(); i++) {
            int skills = 0;
            for (auto s : people[i]) {
                if (skill2idx.find(s) != skill2idx.end()) {
                    skills |= (1 << skill2idx[s]);
                }
            }
            p2s[i] = skills;
        }

        int C = (1 << 16);
        vector<int> dp(C, INT_MAX / 2);
        vector<vector<int>>saves(1<<16);
        people.insert(people.begin(), {""});
        dp[0] = 0;
        for (int i = 1; i <= people.size(); i++) {
            int skills = p2s[i-1];
            int add_people = -1;
            auto dp2 = dp;
            for (int c = 0; c < C; c++) {
                int new_skill = c | skills;
                //dp[new_skill] = min(dp[new_skill], dp2[c] + 1);
                if (dp[new_skill] > (dp2[c] + 1)) {
                    dp[new_skill] = dp2[c] + 1;
                    saves[new_skill] = saves[c];
                    saves[new_skill].push_back(i-1);
                }
            }
        }

        return saves[(1 << req_skills.size()) - 1];

    }
};
