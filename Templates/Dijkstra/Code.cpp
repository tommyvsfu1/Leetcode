#include <bits/stdc++.h>
using namespace std;

// 圖的型別：g[u] 裡面放 {v, w}，代表 u -> v 邊權 w（非負）
using Graph = vector<vector<pair<int,int>>>;
const long long INF = (1LL<<62);

// 回傳 dist 與 parent，用於還原路徑
pair<vector<long long>, vector<int>> dijkstra(int n, const Graph& g, int s) {
    vector<long long> dist(n, INF);
    vector<int> parent(n, -1);

    // 最小堆：{目前距離, 節點}
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue; // 過期條目，略過
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return {dist, parent};
}

// 由 parent 回溯 s->t 路徑；若不可達回空向量
vector<int> reconstruct_path(int s, int t, const vector<int>& parent) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    if (path.empty() || path.front() != s) return {};
    return path;
}
