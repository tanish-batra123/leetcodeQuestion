class Solution {
public:
    bool checkValidString(string s) {
        int low=0;
        int high=0;
       for(char ch:s){
        if(ch=='('){
          low++;
          high++;
        }
        else if(ch==')'){
            low--;
            high--;
        }
        else{
            low--;
            high++;
        }
        if(low <0)low=0;
        if(high<0)return false;
       }
       return low==0;


    }
};