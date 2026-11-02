class Solution {
public:
    
    
    int countMagicalPairs(string s) {
       int cnt=0;
        for(int i=0;i<s.size();i++){

            unordered_map<char,int>leftmap;
            unordered_map<char,int>rightmap;
            unordered_map<int,int>mpp;
            int right=0;
            //left
            for(int j=i;j>=0;j--){
               leftmap[s[j]]++;
               mpp[leftmap.size()]++;
            }
         
            
            for(int k=i+1;k<s.size();k++){
              rightmap[s[k]]++;
             cnt+=mpp[rightmap.size()];
            }

            
        }
        return cnt;

        
    }
};