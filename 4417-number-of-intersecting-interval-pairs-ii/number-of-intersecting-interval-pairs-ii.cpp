bool comp(int val,vector<int>&b){
    return val<b[0];
    
}
class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>&mat) {
        long long cnt=0;
        int n=mat.size();
        sort(mat.begin(),mat.end());

        for(int i=0;i<n;i++){
            long long lastVal=mat[i][1];
            auto it=upper_bound(mat.begin()+i+1,mat.end(),lastVal,comp);
            int idx=distance(mat.begin(),it);
             cnt+=(idx-i-1);
        }
        return cnt;
    }
};