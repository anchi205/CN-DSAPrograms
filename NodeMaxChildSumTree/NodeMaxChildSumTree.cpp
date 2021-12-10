#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

// #include "solution.h"
// #include <climits> For using INT_MIN
template <typename T> // Create and declare a Template
class MaxNodePair{    // Create a Pair class 
    public:
    TreeNode<T> *node; // Create a node                  -- Parameter 1
    int sum;           // Create a sum variable          -- Parameter 2
};
MaxNodePair<int> *maxSumNodeHelper(TreeNode<int> *root){   // Helper function 
    if(root==NULL){
        return 0;
        /* Can use this here in place of return 0
        MaxNodePair<int> *pair = new MaxNodePair<int>(); // Create a 'pair' object of MaxNodePair class
        pair->node = NULL;      // initialising parameter -- node value
        pair->sum = INT_MIN;
        return pair;
        */
    }

    int sum = root->data;
    for(int i = 0;i<root->children.size();i++){     // Ans for the root node
        sum+=root->children[i]->data;
    }

    MaxNodePair<int> *ans = new MaxNodePair<int>(); // Create a 'ans' object of MaxNodePair class
    ans->node = root;
    ans->sum = sum;

    for(int i = 0;i<root->children.size();i++){
        MaxNodePair<int> *childAns = maxSumNodeHelper(root->children[i]); // Create a 'childAns' object of MaxNodePair class and assigning the value of recursive call to it
        if(childAns->sum > ans->sum){
            ans = childAns;
        }
    }

    return ans; 
}
TreeNode<int> *maxSumNode(TreeNode<int> *root){                           // Given function
    return maxSumNodeHelper(root)->node;
}
/*
Time complexity: O(N) -- N -- no of nodes in the tree
Space complexity: O(H) -- H -- height/depth of the tree
*/

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}