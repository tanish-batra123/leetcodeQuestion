class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstlist, vector<vector<int>>& secondlist) {
         vector<vector<int>>ans;
        int i=0;
        int j=0;
        int n=firstlist.size();
        int m=secondlist.size();
        while(i<n && j<m){
             auto v1=firstlist[i];
              auto v2=secondlist[j];
              if(v1[1] >= v2[0] && v1[0] <= v2[1]){
                int start=max(v1[0],v2[0]);
                int end=min(v1[1],v2[1]);
                ans.push_back({start,end});
                if(end==v1[1])i++;
                else j++;
                
             }
             else if(v1[0] > v2[1]){
                j++;

             }else{
                i++;
             }

        }
        return ans;
    }
};