#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <unordered_set>
#include <assert.h>
using namespace std;

class Solution {
private:
    bool checkRow(const vector<vector<char>>& board, int row)
    {
        unordered_set<char> us;
        for (int i = 0; i < 9; i++)
        {
            char ch = board[row][i];
            if ( ch != '.')
            {
                if (us.find(ch) == us.end())
                {
                    us.insert(ch);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkCol(const vector<vector<char>>& board, int col)
    {
        unordered_set<char> us;
        for (int i = 0; i < 9; i++)
        {
            char ch = board[i][col];
            if (ch != '.')
            {
                if (us.find(ch) == us.end())
                {
                    us.insert(ch);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBlob(const vector<vector<char>>& board, int topx, int topy)
    {
        unordered_set<char> us;
        int endx = topx + 3, endy = topy + 3;
        for (int i = topx; i < endx; i++)
        {
            for (int j = topy; j < endy; j++)
            {
                char ch = board[i][j];
                if (ch != '.')
                {
                    if (us.find(ch) == us.end())
                    {
                        us.insert(ch);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        assert(board.size() == 9 && board[0].size() == 9);
        for (int i = 0; i < 9; i++)
        {
            if (!checkRow(board, i) || !checkCol(board, i) || !checkBlob(board, (i / 3) * 3, (i % 3) * 3))
            {
                return false;
            }
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