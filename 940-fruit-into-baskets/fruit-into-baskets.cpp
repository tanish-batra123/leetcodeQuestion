class Solution {
public:
    int totalFruit(vector<int>&fruits) {
        unordered_map<int,int> mpp;
        int i = 0;
        int maxlen=0;
        for (int j = 0; j < fruits.size(); j++) {
            mpp[fruits[j]]++;

            while (mpp.size() > 2) {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0)mpp.erase(fruits[i]);
                i++;
            }
            maxlen=max(maxlen,j-i+1);

        }
        return maxlen;
    }
};