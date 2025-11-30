class Solution {
    int parents[100005];
    int ranks[100005];

    int Find(int p) {
        if (p != parents[p]) {
            parents[p] = Find(parents[p]);
        }
        return parents[p];
    }
    void Union(int a, int b) {
        int pa = Find(a);
        int pb = Find(b);

        if (pa == pb) return;

        if (ranks[pa] > ranks[pb]) {
            parents[pb] = pa;
        }
        else if (ranks[pb] > ranks[pa]) {
            parents[pa] = pb;
        }
        else {
            parents[pa] = pb;
            ranks[pb]++;
        }
    }
public:
    bool gcdSort(vector<int>& nums) {
        
        vector<int> primes(100005, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i * i <= 100000; i++) {
            for (int j = i * i; j <= 100000; j += i) {
                primes[j] = 0;
            }
        }

        vector<int> reduced_primes;
        for (int i = 0; i < 100005; i++) {
            if (primes[i]) reduced_primes.push_back(i);
        }

        for (int i = 0; i < 100005; i++) {
            parents[i] = i;
            ranks[i] = 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            for (auto p : reduced_primes) {
                if (x < p) break;               
                if (x % p == 0) {
                    if (Find(nums[i]) != Find(p)) {
                        Union(nums[i], p);
                    }
                }
                while (x % p == 0) x = x / p;
            }
        }

        vector<int> nums1 = nums;

        sort(nums1.begin(), nums1.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums1[i] != nums[i]) {
                if (Find(nums[i]) != Find(nums1[i])) return false;
            }
        }
        return true;
    }
};