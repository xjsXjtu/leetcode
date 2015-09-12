#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <queue>
#include "shared_functions.h"
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pos_t> posq;
        int sizex = board.size();
        if(sizex <= 1)
            return;
        int sizey = board[0].size();
        for(int i=0; i<sizey; i++)
        {
            process_elem(board, 0, i, posq);
            process_elem(board, sizex - 1, i, posq);            
        }
        for(int i=0; i<sizex; i++)
        {
            process_elem(board, i, 0, posq);
            process_elem(board, i, sizey - 1, posq);            
        }
        // DFS
        while(!posq.empty())
        {
            pos_t curpos = posq.front(); posq.pop();
            int x = curpos.x, y = curpos.y;
            if(x > 0 && board[x-1][y] == 'O')
            {
                process_elem(board, x-1, y, posq);
            }
            if(x < sizex -1 && board[x+1][y] == 'O')
            {
                process_elem(board, x+1, y, posq);
            }
            if(y > 0 && board[x][y-1] == 'O')
            {
                process_elem(board, x, y-1, posq);
            }
            if(y < sizey - 1 && board[x][y+1] == 'O')
            {
                process_elem(board, x, y+1, posq);
            }
        }
        for(int x=0; x<sizex; x++)
            for(int y=0; y<sizey; y++)
            {
                switch (board[x][y])
                {
                case 'V':
                    board[x][y] = 'O';
                    break;
                case 'O':
                    board[x][y] = 'X';
                    break;
                default:
                    break;
                }
            }
    }
private:
    struct pos_t{
        int x;
        int y;
        pos_t(int px, int py):x(px), y(py){}
    };
    void process_elem(vector<vector<char>> &board, int x, int y, queue<pos_t> &q)
    {
        if(board[x][y] == 'O')
        {
            q.push(pos_t(x, y));
            board[x][y] = 'V';
        }
    }
};

void test(char a[][4], int sizex)
{
    vector<vector<char>> board;
    for(int x=0; x<sizex; x++)
    {
        board.push_back(vector<char>(&a[x][0], &a[x][0] + 4));
    }
    Solution s;
    cout << "Input:" << endl;
    printVV<char>(board);
    s.solve(board);
    cout << "Output:" << endl;
    printVV<char>(board);
    return;
}
 
int main()
{
    char a1[][4] = {
        {'X', 'X', 'X', 'X'}
    };
    test(a1, 0);
    test(a1, 1);
    
    char a2[][4] = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    test(a2, 4);

    char a3[][4] = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'X'}
    };
    test(a3, 4);

    char a4[][4] = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'O', 'O', 'X', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    test(a4, 4);
    
    system("pause");
    return 0;
}



