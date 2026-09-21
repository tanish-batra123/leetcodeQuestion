class Solution {
public:
    int reverseDegree(string s) {
        int total=0;
          for(int i=0;i<s.size();i++){
            int val=('z'-s[i]+1)*(i+1);
            total+=val;
        }
        return total;
    }
};