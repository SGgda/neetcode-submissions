class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0;r<9;r++){ //Checking each row if it is valid or not.
            unordered_set<char>st;
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    continue;
                }
                if(st.count(board[r][c])){
                    return false;
                }
                st.insert(board[r][c]);
            }

        }

        for(int r=0;r<9;r++){//Checking if each column is valid or not
            unordered_set<char>st;
            for(int c=0;c<9;c++){
                if(board[c][r]=='.'){
                    continue;
                }
                if(st.count(board[c][r])){
                    return false;
                }
                st.insert(board[c][r]);
            }
        }

        //Now checking for each 3*3 grid
        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                unordered_set<char>st;
                for(int i=r;i<r+3;i++){
                    for(int j=c;j<c+3;j++){
                        if(board[i][j]=='.'){
                            continue;
                        }
                        if(st.count(board[i][j])){
                            return false;
                        }
                        st.insert(board[i][j]);
                    }
                    
                }
            }
        }
        return true;

    }
};
