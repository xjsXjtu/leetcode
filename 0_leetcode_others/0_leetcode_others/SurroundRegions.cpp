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
        int xsize = board.size();
        if(xsize==0) return;
        int ysize = board[0].size();
        queue<pair<int, int>> q;
        int x, y;
        while(findNextElemOAlongEdge(board, &x, &y)) // find seed
        {
            pushQueueChangeElem(&board, &q, x, y, 'R');
            while(!q.empty())
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                pushQueueChangeElem(&board, &q, x-1, y, 'R');
                pushQueueChangeElem(&board, &q, x+1, y, 'R');
                pushQueueChangeElem(&board, &q, x, y-1, 'R');
                pushQueueChangeElem(&board, &q, x, y+1, 'R');
            }
        }
        normalizeElem(&board);
        return;
    }
private:
    void normalizeElem(vector<vector<char>>  *grid)
    {
        int xsize = grid->size();
        int ysize = (*grid)[0].size();
        for(int i=0; i<xsize; i++)
        {
            for(int j=0; j<ysize; j++)
            {
                if((*grid)[i][j] == 'R')
                {
                    (*grid)[i][j] = 'O';
                }
                else
                {
                    (*grid)[i][j] = 'X';
                }
            }
        }
    }
    void pushQueueChangeElem(vector<vector<char>>  *grid, queue<pair<int, int>> *q, const int x, const int y, const char tag)
    {
        int xsize = grid->size();
        int ysize = (*grid)[0].size();
        if(x>=0 && x<xsize && y>=0 && y<ysize && (*grid)[x][y]=='O')
        {
            (*grid)[x][y] = tag;
            q->push(make_pair(x, y));
        }
    }
    bool findNextElemOAlongEdge(const vector<vector<char>>& grid, int *x, int *y)
    {
        int xsize = grid.size();
        int ysize = grid[0].size();
        for(int i=0; i<ysize; i++)
        {
            if(grid[0][i] == 'O')
            {
                *x = 0; *y = i;
                return true;
            }
            if(grid[xsize-1][i] == 'O')
            {
                *x = xsize-1; *y = i;
                return true;
            }
        }
        for(int i=0; i<xsize; i++)
        {
            if(grid[i][0] == 'O')
            {
                *x = i; *y = 0;
                return true;
            }
            if(grid[i][ysize-1] == 'O')
            {
                *x = i; *y = ysize-1;
                return true;
            }
        }
        return false;
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



