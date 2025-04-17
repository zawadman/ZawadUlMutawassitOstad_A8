#include <iostream>
#include <vector>

using namespace std;

//first left subtree, visit current node, then right subtree
void inOrderTraversal(int nodeIndex,
                      const vector<int>& nodeValues,
                      const vector<int>& leftChildIndex,
                      const vector<int>& rightChildIndex,
                      vector<int>& outputSequence)
{
    if (nodeIndex == -1) return;  // no node here
    inOrderTraversal(leftChildIndex[nodeIndex],
                     nodeValues, leftChildIndex, rightChildIndex,
                     outputSequence);
    outputSequence.push_back(nodeValues[nodeIndex]);
    inOrderTraversal(rightChildIndex[nodeIndex],
                     nodeValues, leftChildIndex, rightChildIndex,
                     outputSequence);
}

// first current node, then left subtree, then right subtree
void preOrderTraversal(int nodeIndex,
                       const vector<int>& nodeValues,
                       const vector<int>& leftChildIndex,
                       const vector<int>& rightChildIndex,
                       vector<int>& outputSequence)
{
    if (nodeIndex == -1) return;
    outputSequence.push_back(nodeValues[nodeIndex]);
    preOrderTraversal(leftChildIndex[nodeIndex],
                      nodeValues, leftChildIndex, rightChildIndex,
                      outputSequence);
    preOrderTraversal(rightChildIndex[nodeIndex],
                      nodeValues, leftChildIndex, rightChildIndex,
                      outputSequence);
}

// traverse left subtree, then right subtree, then visit current node
void postOrderTraversal(int nodeIndex,
                        const vector<int>& nodeValues,
                        const vector<int>& leftChildIndex,
                        const vector<int>& rightChildIndex,
                        vector<int>& outputSequence)
{
    if (nodeIndex == -1) return;
    postOrderTraversal(leftChildIndex[nodeIndex],
                       nodeValues, leftChildIndex, rightChildIndex,
                       outputSequence);
    postOrderTraversal(rightChildIndex[nodeIndex],
                       nodeValues, leftChildIndex, rightChildIndex,
                       outputSequence);
    outputSequence.push_back(nodeValues[nodeIndex]);
}

int main() {
    int numberOfNodes;
    cin >> numberOfNodes;

    //sttoring each node's value and the indices of its left/right children
    vector<int> nodeValues(numberOfNodes);
    vector<int> leftChildIndex(numberOfNodes);
    vector<int> rightChildIndex(numberOfNodes);

    for (int i = 0; i < numberOfNodes; ++i) {
        cin >> nodeValues[i]
            >> leftChildIndex[i]
            >> rightChildIndex[i];
    }

    //collect each traversal
    vector<int> inOrderResult;
    vector<int> preOrderResult;
    vector<int> postOrderResult;

    //root is always at index 0
    inOrderTraversal(0, nodeValues, leftChildIndex, rightChildIndex, inOrderResult);
    preOrderTraversal(0, nodeValues, leftChildIndex, rightChildIndex, preOrderResult);
    postOrderTraversal(0, nodeValues, leftChildIndex, rightChildIndex, postOrderResult);

    // Print inorder on first line
    for (int value : inOrderResult) {
        cout << value << ' ';
    }
    cout << "\n";

    // print preorder on second line
    for (int value : preOrderResult) {
        cout << value << ' ';
    }
    cout << "\n";

    //print post-order on third line
    for (int value : postOrderResult) {
        cout << value << ' ';
    }
    cout << "\n";

    return 0;
}
