#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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
/*
Time complexity: O(N) -- N -- no of nodes in the tree
Space complexity: O(H) -- H -- height/depth of the tree
*/
template <typename T>
class secLargest{       
    public:
    TreeNode<T> *max;                  // Parameter 1
    TreeNode<T> *secMax;               // Parameter 2

    secLargest(TreeNode<T> *first, TreeNode<T> *second){   // Constructor for the class
        this->max = first;
        this->secMax = second;
    }
};

secLargest<int> *helperSecondLargest(TreeNode<int> *root){  // Helper function
    if(root==NULL){
        return new secLargest<int>(NULL,NULL); // Creating an object which calls the constructor
    }
    secLargest<int> *ans = new secLargest<int>(root,NULL); // Create an object 'ans'
    for(int i = 0;i<root->children.size();i++){
        secLargest<int> *childAns = helperSecondLargest(root->children[i]); // Create an object 'childAns'
        if(childAns->max->data > ans->max->data){          // Comparing max values of both
            if(childAns->secMax == NULL){
                ans->secMax = ans->max;   // shift the smaller into the NULL value containing node
                ans->max = childAns->max; // shift the larger into the main max
            }
            else{
                if(childAns->secMax->data > ans->max->data){  
                    ans->secMax = childAns->secMax;
                    ans->max = childAns->max;
                }
                else{
                    ans->secMax = ans->max;
                    ans->max = childAns->max;
                }
            }
        }
        else{
            if(ans->max->data!=childAns->max->data && (ans->secMax==NULL || childAns->max->data > ans->secMax->data)){ 
                // Comparing discarded max value with secMax 
                ans->secMax = childAns->max;
            }
        }
    }
    return ans;
}

TreeNode<int> * getSecondLargestNode(TreeNode<int> *root) {
    if(root == NULL or root -> children.size() == 0) {
        return NULL;
    }
    return helperSecondLargest(root)->secMax;
}
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

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}
