class Solution {
public:
    int bfs(int node, vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        queue<pair<int,pair<int,int>>>q;
        int node_mask=1<<node;
        q.push({0,{node,node_mask}});
        visited[node][node_mask]=true;

        while(!q.empty()){
          auto temp=q.front();
          int dis=temp.first;
          int node=temp.second.first;
          int mask=temp.second.second;
          q.pop();
          if(mask==(1<<n)-1)return dis;

          for(auto neg:adj[node]){
            int neg_mask=mask | 1<<neg;
            if(!visited[neg][neg_mask]){
               visited[neg][neg_mask]=true;
               q.push({dis+1,{neg,neg_mask}});
            }
          }

        }

        return INT_MAX;
    }
    int shortestPathLength(vector<vector<int>>& adj) {
        int n=adj.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bfs(i, adj));
        }
        return mini;
    }
};