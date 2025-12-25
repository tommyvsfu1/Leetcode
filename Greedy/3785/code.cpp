class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();

        unordered_map<int, int> total_cnt;
        unordered_map<int, int> forbid_cnt;
        for (int i = 0; i < n; i++) {
            total_cnt[nums[i]]++;
            forbid_cnt[forbidden[i]]++;
        }

        for (auto &[val, cnt] : total_cnt) {
            if (cnt > n - forbid_cnt[val]) return -1;
        }


        int S = 0;
        int max_f = 0;
        unordered_map<int, int> conflict;
        for (int i = 0; i < n; i++) {
            if (nums[i] == forbidden[i]) {
                S++;
                conflict[nums[i]]++;
                max_f = max(max_f, conflict[nums[i]]);
            }
        }

        if (S == 0) return 0;

        if (max_f * 2 > S) return max_f;
        return (S+1) / 2;
    }
};

// O X O -> X O O

// X X O X -> 


// 1 2 3
// 2 1 3
// 3 1 2
// 1 5 1