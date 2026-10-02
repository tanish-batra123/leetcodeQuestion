class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;

        for (auto n : adj[node]) {
            if (!visited[n]) {
                dfs(n, adj, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        if(edges.size() < n-1)return -1;
        int cnt = 0;
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                cnt++;
            }
        }

        return cnt - 1;
    }
};