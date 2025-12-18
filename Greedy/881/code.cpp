class Solution {
    static bool cmp(int &a, int& b) {
        return a > b;
    }
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), cmp);
        int n = people.size();
        int left = 0;
        int right = n-1;
        int round = 0;
        while (left < right) {
            if (people[left] + people[right] <= limit) {
                round++;
                left++;
                right--;
            }
            else {
                left++;
                round++;
            }
        }

        if (left == right) round++;

        return round;
    }
};