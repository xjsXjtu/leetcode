#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool recursive(vector<vector<char>>& board, vector<vector<bool>>& flag, string word, int x, int y)
    {
        if(word.size() == 0)
            return true;
        int sizex = board.size(), sizey = board[0].size();
        if(x - 1 >= 0 && flag[x - 1][y] == true && board[x - 1][y] == word[0])        // up
        {
            flag[x - 1][y] = false;
            if(recursive(board, flag, word.substr(1, word.length() -1), x - 1, y))
                return true;
            flag[x - 1][y] = true;
        }
        if(x + 1 < sizex && flag[x+1][y] == true && board[x+1][y] == word[0])    // down
        {
            flag[x+1][y] = false;
            if(recursive(board, flag, word.substr(1, word.length() -1), x + 1, y))
                return true;
            flag[x+1][y] = true;
        }
        if(y - 1 >= 0 && flag[x][y - 1] == true && board[x][y - 1] == word[0])        // left
        {
            flag[x][y - 1] = false;
            if(recursive(board, flag, word.substr(1, word.length() -1), x, y - 1))
                return true;
            flag[x][y - 1] = true;
        }
        if(y + 1 < sizey && flag[x][y + 1] == true && board[x][y + 1] == word[0])    // right
        {
            flag[x][y + 1] = false;
            if(recursive(board, flag, word.substr(1, word.length() -1), x, y + 1))
                return true;
            flag[x][y + 1] = true;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int sizex = board.size(), sizey = board[0].size();
        vector<vector<bool>> flag(sizex);
        for(int i=0; i<sizex; i++)
            flag[i] = vector<bool>(sizey, true);

        for(int x=0; x<sizex; x++)
        {
            for(int y=0; y<sizey; y++)
            {
                if(board[x][y] == word[0])
                {
                    flag[x][y] = false;
                    if(recursive(board, flag, word.substr(1, word.length() - 1), x, y))
                        return true;
                    flag[x][y] = true;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board;
    board.resize(1);
    board[0] = vector<char>(2, 'a');
    Solution s;
    cout << "True = " << true << endl;
    cout << s.exist(board, "aaa") << endl;
    system("pause");
    return 0;
}
