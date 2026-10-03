class Solution {
public:

bool isSafe(int r,int c, char digit,vector<vector<char>>& board){
     
     for(int i=0;i<9;i++){
        if(board[r][i]==digit)return false;
     }
      for(int i=0;i<9;i++){
        if(board[i][c]==digit)return false;
     }
     int startRow=r-(r%3);
     int startCol=c-(c%3);

     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[startRow+i][startCol+j]==digit)return false;
        }
     }
     return true;


}
    bool solve(int r, int c, vector<vector<char>>& board) {
        if (r == 9)return true;

        if(c==9) return solve(r+1,0,board);

        if(board[r][c]!='.')return solve(r,c+1,board);
        
        for(char digit='1';digit<='9';digit++){
            if(isSafe(r,c,digit,board)){
                board[r][c]=digit;
                if(solve(r,c+1,board))return true;
                board[r][c]='.';

            }
        }
        return false;
            
    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(0,0,board);
         
          }
};