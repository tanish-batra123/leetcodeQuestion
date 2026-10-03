class Solution {
public:

bool isSafe(int r,int c,int n,vector<string>small){
    //check col
   for(int i=0;i<c;i++){
    if(small[r][i]=='Q')return false;
   }
    for(int i=0;i<r;i++){
    if(small[i][c]=='Q')return false;
    }
    //right dia
    int i=r-1;
    int j=c-1;
    while(i>=0 && j>=0){
        if(small[i][j]=='Q')return false;
        i--;
        j--;
    }
    i=r-1;
    j=c+1;
   //left dia
    while(i>=0 && j<n){
        if(small[i][j]=='Q')return false;
        i--;
        j++;
    }
    return true;

}
    void solve(int n, int row, vector<string>& small, vector<vector<string>>& big) {
        if (row == n){
            big.push_back(small);
            return;
        }
        

        for (int i = 0; i < n; i++) {
            if (isSafe(row,i,n,small)) {
                small[row][i] = 'Q';
                solve(n, row + 1, small, big);
                small[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> small(n, string(n, '.'));
        vector<vector<string>> big;
        solve(n,0,small,big);
        return big;
    }
};