#include <iostream>
#include <vector>

using namespace std;

//recursively computes the height of the subtree rooted at 'node'.
int computeHeight(int node, const vector<vector<int>>& children)
{
    int maxChildHeight = 0;
    for (int child : children[node])
    {
        int childHeight = computeHeight(child, children);
        if (childHeight > maxChildHeight)
        {
            maxChildHeight = childHeight;
        }
    }
    return 1 + maxChildHeight;
}

int main()
{
    //number of nodes
    int numberOfNodes;
    cin >> numberOfNodes;

    vector<int> parentList(numberOfNodes);
    for (int i = 0; i < numberOfNodes; ++i)
    {
        cin >> parentList[i];
    }

    //adjacency list of children for each node
    vector<vector<int>> childrenList(numberOfNodes);
    int rootIndex = -1;
    for (int i = 0; i < numberOfNodes; ++i)
    {
        int p = parentList[i];
        if (p == -1) {
            rootIndex = i;
        } else {
            childrenList[p - 1].push_back(i);
        }
    }

    // compute height starting from root
    int treeHeight = computeHeight(rootIndex, childrenList);

    cout << treeHeight << "\n";
    return 0;
}
