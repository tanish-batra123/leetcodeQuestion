class Solution {
public:
bool isValid(int r,int c, char digit,vector<vector<char>>& board){
     
     for(int i=0;i<9;i++){
        if(i!=c && board[r][i]==digit)return false;
     }
      for(int i=0;i<9;i++){
        if(i!=r && board[i][c]==digit)return false;
     }
     int startRow=r-(r%3);
     int startCol=c-(c%3);

     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int nr=startRow+i;
            int nc=startCol+j;
            if((nr!=r || nc!=c)&&board[nr][nc]==digit)return false;
        }
     }
     return true;


}
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
              if(board[i][j]!='.'&&isValid(i,j,board[i][j],board)==false)return false;
            }
        }
        return true;
    }
};