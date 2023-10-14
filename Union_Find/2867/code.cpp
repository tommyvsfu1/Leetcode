using LL = long long;
class Solution {
    unordered_set<int> primes;
    int parents[100001];
    int Find(int x) {
        if (parents[x] == x) return x;
        return parents[x] = Find(parents[x]);
    }
    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u < v) parents[v] = u;
        else parents[u] = v;
    }
public:
    bool PrimeCheck(int x) {
        if (x == 1) return false; 
        int res = 0;
        for (int i = 2; i < x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    bool isPrime(int x) {
        return primes.find(x) != primes.end();
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        
        for (int i = 1; i <= n; i++) {
            if (PrimeCheck(i))
                primes.insert(i);
        }


        vector<vector<int>> graph(n+1);

        for (int i = 1; i <= n; i++)
            parents[i] = i;
        
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);

            int a = e[0];
            int b = e[1];
            if (!isPrime(a) && !isPrime(b)) {
                if (Find(a) != Find(b)) 
                    Union(a, b);
            }
        }
        
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            mp[Find(i)] += 1;
        }


        LL res = 0;
        for (auto p : primes) {
            vector<LL> arr;
            for (auto next : graph[p]) {
                if (!isPrime(next)) {
                    arr.push_back(mp[Find(next)]);
                }
            }
            LL sum = 0;
            LL total = accumulate(arr.begin(), arr.end(), 0LL);

            for (int i = 0; i < arr.size(); i++) {
                sum += arr[i] * (total - arr[i]);
            }

            res += (sum/2 + total);
        }

        return res;
    }
};