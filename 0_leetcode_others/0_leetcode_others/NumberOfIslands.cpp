#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <queue>
#include "shared_functions.h"
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        queue<Position> q;
        int sizex = grid.size();
        if(sizex <= 0)
            return 0;
        int sizey = grid[0].size();
        
        int num = 0; 
        Position pos;
        while(findNextOne(grid, sizex, sizey, pos))
        {
            num++;
            q.push(pos);
            while(!q.empty())
            {
                pos = q.front(); q.pop();
                int x=pos.x, y = pos.y;
                grid[x][y] = '2';
                if(x > 0 && grid[x-1][y] == '1')
                {
                    process_elem(grid, x-1, y, q);
                }
                if(x < sizex -1 && grid[x+1][y] == '1')
                {
                    process_elem(grid, x+1, y, q);
                }
                if(y > 0 && grid[x][y-1] == '1')
                {
                    process_elem(grid, x, y-1, q);
                }
                if(y < sizey - 1 && grid[x][y+1] == '1')
                {
                    process_elem(grid, x, y+1, q);
                } 
            }
        }
        return num;
    }
private:
    struct Position{
        int x; int y;
        Position(int px=0, int py=0): x(px), y(py){}
    };
    bool findNextOne(vector<vector<char>>& grid, int sizex, int sizey, Position &pos)
    {
        for(int x=0; x<sizex; x++)
        {
            for(int y=0; y<sizey; y++)
            {
                if(grid[x][y] == '1')
                {
                    pos.x = x; pos.y = y;
                    return true;
                }
            }
        }
        return false;
    }
    void process_elem(vector<vector<char>> &board, int x, int y, queue<Position> &q)
    {
        q.push(Position(x, y));
        board[x][y] = '2';
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