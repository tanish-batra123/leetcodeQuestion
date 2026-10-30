class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto temp : edges) {
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];
            adj[u].push_back({v, w});
        }

        pair<int, pair<int, pair<char, int>>> p;
        priority_queue<decltype(p), vector<decltype(p)>, greater<decltype(p)>>
            pq;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        pq.push({0, {0, {labels[0], 1}}});
        dist[0][1] = 0;

        while (!pq.empty()) {
            auto [wt, temp1] = pq.top();
            auto [node, temp2] = temp1;
            auto [lastchar, cnt] = temp2;
            pq.pop();
            if (wt != dist[node][cnt])
                continue;
            if (node == n - 1)
                return wt;

            for (auto it : adj[node]) {
                int neg = it.first;
                int newt = it.second;
                char newchar = labels[neg];
                int newcnt = 0;
                if (newchar != lastchar) {
                    newcnt = 1;
                } else {

                    newcnt = cnt + 1;
                }
                if (newcnt > k)
                    continue;

                if (wt + newt < dist[neg][newcnt]) {
                    dist[neg][newcnt] = wt + newt;
                    pq.push({dist[neg][newcnt],{neg, {newchar, newcnt}}});
                }
            }
        }
        return -1;
    }
};