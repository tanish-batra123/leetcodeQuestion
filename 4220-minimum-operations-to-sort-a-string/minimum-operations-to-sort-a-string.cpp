class Solution {
public:
    int minOperations(string s) {
        string temp=s;
        sort(temp.begin(),temp.end());
        if(s==temp)return 0;
        if (s.size() == 2)
            return -1;
        int cnt = 0;
        int maxchar = -1;
        int minchar = INT_MAX;

        int maxidx = INT_MIN;
        int minidx = INT_MAX;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] >= maxchar) {
                maxchar = int(s[i]);
                maxidx=i;
            }
             if(s[i] < minchar){
                minchar=int(s[i]);
                minidx=i;
             }
        }
         if(minidx==0 || maxidx==s.size()-1)return 1;
         else if(minidx==s.size()-1 && maxidx==0)return 3;
         else return 2;
    }
};
//