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
TreeNode<int>* getNextLargerElement(TreeNode<int> *root, int x) {
    if(root==NULL) // Edge Case
        return NULL;
    if(root->children.size()==0){ // No children
        if(root->data>x)
            return root;
        else
            return NULL;
    }
    TreeNode<int>* curr = NULL;
    if(root->data>x)
        curr=root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* desc=getNextLargerElement(root->children[i],x);
        if(desc!=NULL){
            if(curr==NULL || curr->data>desc->data)
                curr=desc;
        }
    }
    return curr;
}
/*
OR
#include <climits>
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int n){
    if(root==NULL){
        return root;
    }
    bool flag = false;
    TreeNode<int> *nextLarger = NULL;
    if(root->data > n){
        flag = true;
        nextLarger = root;
    }
    for(int i = 0;i<root->children.size();i++){
        TreeNode<int> *temp = getNextLargerElement(root->children[i],n);
        if(nextLarger == NULL){
            nextLarger = temp;
        }
        else if(temp!= NULL && temp->data < nextLarger->data){
            flag = true;
            nextLarger = temp;
        }
    }
    return nextLarger;
}
/*
Time complexity : O(N)
Space complexity : O(H)
N -- number of nodes in the tree
H -- height/depth of the tree
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
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}