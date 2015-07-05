#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <unordered_set>
#include <assert.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> blocks(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')continue;
                int num = board[i][j] - '1';
                if (rows[i][num] || cols[j][num] || blocks[i - i % 3 + j / 3][num])
                    return false;
                rows[i][num] = cols[j][num] = blocks[i - i % 3 + j / 3][num] = true;
            }
        return true;
    }
};

int main()
{
    vector<vector<char>> board(9);
    for (int i = 0; i < 9; i++)
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
    
    Solution s;
    cout << true << endl;
    cout << s.isValidSudoku(board) << endl;
    system("pause");
    return 0;
}