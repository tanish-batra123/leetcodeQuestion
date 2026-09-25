class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mpp1;
        unordered_map<string,char>mpp2;
         vector<string>store;
        s+=" ";
        string temp="";
     
        for(int i=0;i<s.size();i++){
           if(s[i]!=' '){
            temp.push_back(s[i]);
           }else {
            store.push_back(temp);
            temp="";
           }
        }
        if(pattern.size()>store.size()||pattern.size()<store.size())return false;
        for(int i=0;i<pattern.size();i++){
            char ch=pattern[i];
            string y=store[i];
            if(mpp1.find(ch)!=mpp1.end()){
                string x=mpp1[ch];
                if(y!=x)return false;
                if(mpp2.find(x)!=mpp2.end()){
                    if(mpp2[x]!=ch)return false;
                }

            }
            else if(mpp2.find(store[i])!=mpp2.end()){
                if(mpp2[store[i]]!=ch)return false;
            }
            mpp1[ch]=store[i];
            mpp2[store[i]]=ch;
        }
        return true;
    }
};