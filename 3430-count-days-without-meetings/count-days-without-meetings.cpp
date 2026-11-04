class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int cnt=0;
  sort( meetings.begin(), meetings.end());
         vector<vector<int>>ans;

        for(auto interval : meetings){
            if(ans.size()==0){
                ans.push_back(interval);
            }
            else if( ans.back()[1] < interval[0]){
                  
                  cnt+=interval[0]-ans.back()[1]-1;
                  ans.push_back(interval);
                  cout<<cnt<<endl;
            }
            else{
                vector<int>temp=ans.back();
                ans.pop_back();
                ans.push_back({temp[0],max(temp[1],interval[1])});
            }
        }
        cnt+=ans[0][0]-1;
        cnt+=days-ans.back()[1];
        return cnt;
    }
};