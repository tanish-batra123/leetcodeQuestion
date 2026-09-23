class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;

        for(string s:strs){
            string copy=s;
            sort(copy.begin(),copy.end());
            if(mpp.find(copy)!=mpp.end()){
                mpp[copy].push_back(s);

            }
           else  mpp[copy].push_back(s);
           
        }
         for(auto it:mpp){
                ans.push_back(it.second);
            }
         return ans;


    }
};