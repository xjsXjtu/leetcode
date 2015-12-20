class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()<=0) return;
        int mx = matrix.size();
        int my = matrix[0].size();
        assert(mx == my);
        rec(&matrix, 0, 0, mx);
    }
private:
    void rec(vector<vector<int>> *pmatrix, int startx, int starty, int size)
    {
        if(size <= 1) return;
        for(int i=0; i<size-1; i++)
        {
            int temp = (*pmatrix)[startx][starty+i];
            (*pmatrix)[startx][starty+i]                = (*pmatrix)[startx+size-1-i][starty];
            (*pmatrix)[startx+size-1-i][starty]         = (*pmatrix)[startx+size-1][starty+size-1-i];
            (*pmatrix)[startx+size-1][starty+size-1-i]  = (*pmatrix)[startx+i][starty+size-1];
            (*pmatrix)[startx+i][starty+size-1]         = temp;
        }
        rec(pmatrix, startx+1, starty+1, size-2);
    }
};