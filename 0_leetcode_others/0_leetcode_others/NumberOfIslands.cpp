#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <queue>
#include "shared_functions.h"
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int xsize = grid.size();
        if(xsize==0) return 0;
        int ysize = grid[0].size();
        queue<pair<int, int>> q;
        int x, y;
        int out = 0;
        while(findNextElemOne(grid, &x, &y))
        {
            out++;
            pushQueueChangeElem(&grid, &q, x, y, out + '2');
            while(!q.empty())
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                pushQueueChangeElem(&grid, &q, x-1, y, out + '2');
                pushQueueChangeElem(&grid, &q, x+1, y, out + '2');
                pushQueueChangeElem(&grid, &q, x, y-1, out + '2');
                pushQueueChangeElem(&grid, &q, x, y+1, out + '2');
            }
        }
        return out;
    }
private:
    void pushQueueChangeElem(vector<vector<char>>  *grid, queue<pair<int, int>> *q, const int x, const int y, const char tag)
    {
        int xsize = grid->size();
        int ysize = (*grid)[0].size();
        if(x>=0 && x<xsize && y>=0 && y<ysize && (*grid)[x][y]=='1')
        {
            (*grid)[x][y] = tag;
            q->push(make_pair(x, y));
        }
    }
    bool findNextElemOne(const vector<vector<char>>& grid, int *x, int *y)
    {
        int xsize = grid.size();
        int ysize = grid[0].size();
        for(int i=0; i<xsize; i++)
        {
            for(int j=0; j<ysize; j++)
            {
                if(grid[i][j] == '1')
                {
                    *x = i; *y = j;
                    return true;
                }
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
    cout << "numIslands:" << s.numIslands(board) << endl << endl;
    return;
}
void test20(char a[][20], int sizex)
{
    vector<vector<char>> board;
    for(int x=0; x<sizex; x++)
    {
        board.push_back(vector<char>(&a[x][0], &a[x][0] + 20));
    }
    Solution s;
    cout << "Input:" << endl;
    printVV<char>(board);    
    cout << "numIslands:" << s.numIslands(board) << endl << endl;
    return;
}
 
int main()
{
    char a1[][4] = {
        {'0', '0', '0', '0'}
    };
    test(a1, 0);
    test(a1, 1);

    char a10[][4] = {
        {'1', '1', '1', '1'}
    };
    test(a10, 1);

    char a11[][4] = {
        {'0', '1', '0', '1'}
    };
    test(a11, 1);

    char a12[][4] = {
        {'0', '1', '0', '0'},
        {'1', '0', '1', '0'},
        {'0', '1', '0', '0'},
        {'0', '0', '0', '0'}
    };
    test(a12, 4);
    
    char a2[][4] = {
        {'0', '0', '0', '0'},
        {'0', '1', '1', '0'},
        {'0', '1', '0', '0'},
        {'0', '0', '0', '0'}
    };
    test(a2, 4);

    char a3[][4] = {
        {'0', '0', '1', '1'},
        {'1', '1', '0', '1'},
        {'0', '1', '1', '1'},
        {'0', '0', '1', '1'}
    };
    test(a3, 4);

    char a4[][4] = {
        {'0', '0', '0', '0'},
        {'0', '1', '1', '0'},
        {'1', '1', '0', '0'},
        {'0', '0', '0', '1'}
    };
    test(a4, 4);

    char a5[][20] = {
        {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0'},
        {'1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };
    test20(a5, 20);
    
    system("pause");
    return 0;
}