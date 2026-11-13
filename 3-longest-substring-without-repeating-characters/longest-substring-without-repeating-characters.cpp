class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mpp;
        int longlen=0;
        int i=0,j=0;
        while(j<s.size()){
            mpp[s[j]]++;

            while(mpp[s[j]]>1){
                mpp[s[i]]--;
                if(mpp[s[i]]==0)mpp.erase(s[i]);
                i++;
            }
            longlen=max(longlen,j-i+1);
            j++;
        }
        return longlen;
    }
};