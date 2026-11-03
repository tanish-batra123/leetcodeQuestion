class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstlist, vector<vector<int>>& secondlist) {
         vector<vector<int>>ans;
        for(int i=0;i<firstlist.size();i++){
           auto v1=firstlist[i];
            for(int j=0;j<secondlist.size();j++){
             auto v2=secondlist[j];

             if(v1[1] >= v2[0] && v1[0] <= v2[1]){
                int start=max(v1[0],v2[0]);
                int end=min(v1[1],v2[1]);
                ans.push_back({start,end});
             }
                
            }
        }
        return ans;
    }
};