#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool recursive(vector<vector<char>>& board, vector<vector<bool>>& flag, string word, int wordi, int x, int y)
    {
        if(word.size() == wordi)
            return true;
        int sizex = board.size(), sizey = board[0].size();
        if(x < 0 || x >= sizex || y < 0 || y >= sizey)
            return false;
        if(board[x][y] != word[wordi] || flag[x][y] == false)
            return false;
        
        flag[x][y] = false;
        if(recursive(board, flag, word, wordi + 1, x - 1, y))
            return true;
        if(recursive(board, flag, word, wordi + 1, x + 1, y))
            return true;
        if(recursive(board, flag, word, wordi + 1, x, y - 1))
            return true;
        if(recursive(board, flag, word, wordi + 1, x, y + 1))
            return true;
        flag[x][y] = true;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int sizex = board.size(), sizey = board[0].size();
        vector<vector<bool>> flag(sizex, vector<bool>(sizey, true));

        for(int x=0; x<sizex; x++)
        {
            for(int y=0; y<sizey; y++)
            {
                if(recursive(board, flag, word, 0, x, y))
                    return true;
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
