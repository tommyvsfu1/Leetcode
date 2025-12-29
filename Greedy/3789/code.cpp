class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        int cBoth = min(cost1 + cost2, costBoth);

        int c1 = min(cBoth, cost1);
        int c2 = min(cBoth, cost2);

        int overlap = min(need1, need2);

        long long res = 0;

        res = res + (long long)overlap * cBoth;

        res = res + ((overlap == need1) ? (need2-overlap) * (long long)c2 : (need1-overlap) * (long long)c1);
        return res;
    }
};