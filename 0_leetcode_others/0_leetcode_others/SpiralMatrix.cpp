class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        int sizex = matrix.size(); 
        if(sizex <= 0) return out;
        int sizey = matrix[0].size();
        rec(matrix, 0, 0, sizex, sizey, &out);
        return out;
    }
private:
    void rec(const vector<vector<int>>& matrix, int startx, int starty, int sizex, int sizey, vector<int> *pout)
    {
        if(sizex <= 0 || sizey <= 0) return;
        if(sizex == 1) 
        {
            pout->insert(pout->end(), matrix[startx].begin() + starty, matrix[startx].begin() + starty + sizey);
            return;
        }
        if(sizey == 1)
        {
            for(int x=0; x<sizex; x++)
            {
                pout->push_back(matrix[startx + x][starty]);
            }
            return;
        }
        pout->insert(pout->end(), matrix[startx].begin() + starty, matrix[startx].begin() + starty + sizey);
        for(int x=1; x<sizex; x++)
        {
            pout->push_back(matrix[startx + x][starty + sizey - 1]);
        }
        for(int y=sizey-2; y>=0; y--)
        {
            pout->push_back(matrix[startx + sizex - 1][starty + y]);
        }
        for(int x=sizex-2; x>=1; x--)
        {
            pout->push_back(matrix[startx + x][starty]);
        }
        rec(matrix, startx + 1, starty + 1, sizex - 2, sizey - 2, pout);
    }
};