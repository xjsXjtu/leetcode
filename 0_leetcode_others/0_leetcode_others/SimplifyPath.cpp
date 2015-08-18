#include <string>
#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {
        string res;
        path += "/";
        size_t pos = path.find_first_of("/"), last = 0;
        while (pos != string::npos)
        {
            string s = path.substr(last, pos - last);
            if (s == "..") 
            {
                if (!res.empty())
                    res.resize(res.find_last_of("/"));
            }
            else if (!s.empty() && s != ".")
            {
                res += "/";
                res += s;
            }
            last = pos + 1;
            pos = path.find_first_of("/", last);
        }
        return res.empty() ? "/" : res;
    }
    // too many damm coner cases! such as /..., /.../
    string simplifyPath_1(string path) {
        if(path.size() <= 1)
            return path;
        if(path == "/...")
            return path; // damm case
        path.push_back('/'); // to handle case like this: '/..'
        int len = path.size();
        stack<char> s;
        for(int i=0; i<len; i++)
        {
            if(path[i] == '/')
            {
                if(s.size() > 1 && s.top() == '/')
                {
                    continue;
                }
                else if(s.size() > 1 && s.top() == '.')
                {
                    s.pop(); // '.'
                    if(s.size() > 1 && s.top() == '.')
                    {
                        s.pop(); // '.'
                        if(s.size() > 1)
                            s.pop(); // '/'
                        while(s.size() > 1 && s.top() != '/')
                        {
                            s.pop(); // dir name
                        }
                    }
                }
                else
                {
                    s.push('/');
                }
            }
            else
            {
                s.push(path[i]);
            }
        }
        string out;
        while(s.size())
        {
            out.push_back(s.top());
            s.pop();
        }
        reverse(out.begin(), out.end());
        if(out.size() > 1 && out[out.size() - 1] == '/')
            out.pop_back();

        return out;
    }
};

int main()
{
    Solution s;
     // cout << s.simplifyPath("") << endl;
     // cout << s.simplifyPath("/") << endl;
     // cout << s.simplifyPath("//") << endl;
     // 
     // cout << s.simplifyPath("/.") << endl;
     cout << s.simplifyPath("/..") << endl;
     
     
     cout << s.simplifyPath("/home/") << endl;
     cout << s.simplifyPath("/home//") << endl;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;

    system("pause");
    return 0;
}