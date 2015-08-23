#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;
        if(root == NULL)
            return out;
        
        queue<TreeNode*> q;
        vector<int> level;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *tn = q.front(); q.pop();
            if(tn == NULL)  // end of one level
            {
				out.push_back(level);
                if(q.empty())
                    break;
                level.clear();
                q.push(NULL);
            }
            else // inside one level
            {
                level.push_back(tn->val);
                if(tn->left)
                    q.push(tn->left);
                if(tn->right)
                    q.push(tn->right);
            }
        }
        
        for(int i=0; i<out.size(); i++)
        {
            if(i % 2 == 1)
                reverse(out[i].begin(), out[i].end());
        }
        return out;
    }
};

void printVV(vector<vector<int>> in)
{
	cout << "[" << endl;
	for(int i=0; i<in.size(); i++)
	{
		cout << " [";
		for(int j=0; j<in[i].size(); j++)
		{
			cout << in[i][j] << ", "; 
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
}

void test(TreeNode *root)
{
	Solution s;
	printVV(s.zigzagLevelOrder(root));
}
int m_ain()
{
	TreeNode root(1);
	test(&root);

	system("pause");
	return 0;
}

