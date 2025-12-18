class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int start_index = 0;
        int curr_tank = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            total_tank += (-cost[i] + gas[i]);
            curr_tank += (-cost[i] + gas[i]);

            if (curr_tank < 0) {
                start_index = i+1;
                curr_tank = 0;
            }
        }

        if (total_tank < 0) return -1;
        return start_index;
    }
};

//-1 -1 -1 4 -1 