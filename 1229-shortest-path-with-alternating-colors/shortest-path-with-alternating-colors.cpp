class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto it:redEdges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,0});
        }
        for(auto it:blueEdges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,1});
        }
        vector<int> dist(n, -1);
        vector<vector<int>>visited(n+1,vector<int>(2,0));
        dist[0] = 0;
        visited[0][0]=1;
        visited[0][1]=1;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, -1}});
        while (!q.empty()) {
            auto [node, temp] = q.front();
            auto [dis, prevcol] = temp;
            q.pop();

            for (auto it : adj[node]) {
                int neg = it.first;
                int negcol = it.second;
               
                 if(!visited[neg][negcol] && negcol!=prevcol){
                    
                    visited[neg][negcol]=1;
                    if(dist[neg]==-1){
                        dist[neg]=dis+1;
                    }
                  q.push({neg,{dis+1,negcol}});
                }
                  
            }

        }

        return dist;
    }
};