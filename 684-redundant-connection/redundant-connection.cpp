class DisjointSet{
      vector<int>parent,rank;
      public:
      DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
    }

    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(int u,int v,vector<int>&cycleEdge){
        int pu=findPar(u);
        int pv=findPar(v);
        if (pu == pv){
            cycleEdge[0]=u;
            cycleEdge[1]=v;
        } ;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;

        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size());
        vector<int>cycleEdge(2);
        for(auto temp:edges){
            ds.unionByRank(temp[0],temp[1],cycleEdge);
        }
        return cycleEdge;

    }
};