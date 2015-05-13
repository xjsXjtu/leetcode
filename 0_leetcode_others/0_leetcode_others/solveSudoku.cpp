#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <assert.h>
using namespace std;


void printSudoku(vector<vector<char>>& board);

class Solution {
private:
    bool isValidNum(vector<vector<char>>& board, int x, int y, int val)
    {
        for(int k=0;k<9;k++)  
        {  
            if(board[k][y]==val + '0')  
                return false;  
        }  
        for(int k=0;k<9;k++)  
        {  
            if(board[x][k]==val + '0')  
                return false;  
        }          
        for(int row = x/3*3; row<x/3*3+3; row++)  
        {  
            for(int col=y/3*3; col<y/3*3+3; col++)  
            {  
                if(board[row][col]==val + '0')  
                    return false;
            }  
        }  
        return true; 
    }

    bool solve(vector<vector<char>>& board, int x, int y)
    {
        if(x == 9)
            return true;
        if(y == 9)
            return solve(board, x + 1, 0);
        if(board[x][y] != '.')
            return solve(board, x, y + 1);

        for(int val=1; val<10; val++)
        {
            if(isValidNum(board, x, y, val))
            {
                board[x][y] = val + '0';
                if(solve(board, x, y + 1))
                    return true;
                // backtracking, need restore the board
                board[x][y] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        assert(board.size() == 9);
        assert(board[0].size() == 9);

        solve(board, 0, 0);
        return;
    }
};

void printSudoku(vector<vector<char>>& board)
{
    for(int i=0; i<9; i++)
    {
        if(i % 3 == 0)
            cout << "--------------------------------" << endl;
        for(int j=0; j<9; j++)
        {
            if(j % 3 == 0)
                cout << "|";
            cout << " " << board[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "--------------------------------" << endl;
}

int main()
{
    vector<vector<char>> board(9);
    for(int i=0; i<9; i++)
    {
        board[i].resize(9, '.');
    }
    board[0][0] = '5'; board[0][1] = '3'; board[0][4] = '7';
    board[1][0] = '6'; board[1][3] = '1'; board[1][4] = '9'; board[1][5] = '5';
    board[2][1] = '9'; board[2][2] = '8'; board[2][7] = '6';
    board[3][0] = '8'; board[3][4] = '6'; board[3][8] = '3';
    board[4][0] = '4'; board[4][3] = '8'; board[4][5] = '3'; board[4][8] = '1';
    board[5][0] = '7'; board[5][4] = '2'; board[5][8] = '6';
    board[6][1] = '6'; board[6][6] = '2'; board[6][7] = '8';
    board[7][3] = '4'; board[7][4] = '1'; board[7][5] = '9'; board[7][8] = '5';
    board[8][4] = '8'; board[8][7] = '7'; board[8][8] = '9';
    printSudoku(board);


    Solution s;
    s.solveSudoku(board);
    cout << endl << "after solve" << endl;
    printSudoku(board);

    system("pause");
    return 0;
}