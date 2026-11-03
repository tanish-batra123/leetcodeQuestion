class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool> rowbomb(m, false);
        vector<bool> colbomb(n, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowbomb[i] = true;
                    colbomb[j] = true;
                }
            }
        }

        for(int i=0;i<rowbomb.size();i++){
            for(int j=0;j<colbomb.size();j++){
                if(rowbomb[i] || colbomb[j]){
                    matrix[i][j]=0;
                }
            }
        }

    }
};