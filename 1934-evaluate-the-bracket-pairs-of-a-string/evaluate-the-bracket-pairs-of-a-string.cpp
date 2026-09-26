class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string>mpp;
        for(auto temp:knowledge){
            mpp[temp[0]]=temp[1];
        }

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                int j=i+1;
                string temp="";
                while(j<s.size() && s[j]!=')'){
                 temp+=s[j];
                 j++;
                }
               i=j;
              if(mpp.find(temp)==mpp.end()){
                ans+="?";

              }else ans+=mpp[temp];
              

            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};