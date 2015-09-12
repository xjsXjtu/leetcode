#include <cassert>
#include <cstdint>

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
// #include <initializer_list> // vs2012 doesn't support init list. 
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
    // UndirectedGraphNode(std::initializer_list<int> init_list) 
    // {    
    //      for (int i : init_list) 
    //          do_something    ;
    // }
};

class Solution {
public:
    typedef UndirectedGraphNode Node;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return cloneGraphDFS(node);
    }

    // BFS: 76ms
    Node *cloneGraphBFS(Node *node) {
        queue<Node*> srcq;
        unordered_map<Node*, Node*> nmap;
        if(node == NULL)
            return NULL;
        Node *newn = new Node(node->label);
        nmap[node] = newn;
        srcq.push(node);
        while(!srcq.empty())
        {
            Node *src = srcq.front(); srcq.pop();
            for(int i=0; i<src->neighbors.size(); i++)
            {
                Node *neib = src->neighbors[i];
                if(nmap.find(neib) == nmap.end())
                {
                    Node *newn = new Node(neib->label);
                    nmap[neib] = newn;
                    srcq.push(neib);
                }
                nmap[src]->neighbors.push_back(nmap[neib]);
            }
        }
        return nmap[node];
    }

    // DFS: 76ms
    Node *cloneGraphDFS(Node *node)
    {
        if(node == NULL)
            return NULL;
        unordered_map<Node*, Node*> umap;
        dfsRec(node, umap);
        return umap[node];
    }
    Node *dfsRec(Node *node, unordered_map<Node*, Node*>& umap)
    {
        if(umap.find(node) != umap.end()) // already created for this node and its neigbors.
            return umap[node];
        Node *newn = new Node(node->label);
        umap[node] = newn;
        for(int i=0; i<node->neighbors.size(); i++)
        {
            newn->neighbors.push_back(dfsRec(node->neighbors[i], umap));
        }
        return newn;
    }
};

// Construct Undirected Graph with strings
// eg: [#0,1,2, #1,2, #2, 2]
//      #       : alone with label value, label is unique integer numbers. 
//      others  : neigbours' label value
UndirectedGraphNode* ConstructUndirectedGraph(vector<string> vs)
{
    typedef UndirectedGraphNode Node;
    if(vs.size() <= 0)
        return NULL;
    unordered_map<int, Node*> umap;
    assert(vs[0][0]=='#');
    for(int i=0; i<vs.size(); i++)
    {
        assert(vs[i].size()>0);
        if(vs[i][0] == '#')
        {
            int val = std::stoi(vs[i].substr(1, vs[i].size() - 1));
            assert(umap.find(val) == umap.end()); // Assert label is unique.
            Node *newn = new Node(val);
            umap[val] = newn;
        }
    }
    Node *node = NULL;
    for(int i=0; i<vs.size(); i++)
    {
        if(vs[i][0] == '#')
        {
            if(node != NULL)
            {
                assert(node->neighbors.size() > 0); // Assert the graph is fully connected.
            }
            node = umap[std::stoi(vs[i].substr(1, vs[i].size() - 1))];
        }
        else
        {
            int label = std::stoi(vs[i]);
            node->neighbors.push_back(umap[label]); // node==> label
            if(node->label != label)
            {
                umap[label]->neighbors.push_back(node); // label ==> node
            }
        }
    }
    return umap[std::stoi(vs[0].substr(1, vs[0].size() - 1))];
}

void DestroyUndirectedGraph(UndirectedGraphNode *node) 
{}

UndirectedGraphNode* Test(string *vs, int size)
{
    vector<string> v(&vs[0], &vs[0] + size);
    UndirectedGraphNode *src = ConstructUndirectedGraph(v);
    Solution s;
    return s.cloneGraph(src);
}

int main()
{
    UndirectedGraphNode *out;
    string vs1[7] = {"#0", "1" , "2", "#1", "2", "#2", "2"};
    out = Test(vs1, 7);
    return 0;
}