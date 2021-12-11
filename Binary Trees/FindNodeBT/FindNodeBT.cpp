#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }
    else if(root->data == x){
        return true;
    }
    // return isNodePresent(root->left,x) || isNodePresent(root->right,x);
    /*
    Time complexity: O(N)
    Space complexity: O(H)

    N -- no of nodes in the tree
    H -- height of the tree
    H = log(N) for a balanced tree

    */
    bool isLeftP;
    bool isRightP;
    if(root->left){
        isLeftP = isNodePresent(root->left,x);
    }
    if(root->right){
        isRightP = isNodePresent(root->right,x);
    }
    if(isLeftP || isRightP){
        return true;
    }
    else{
        return false;
    }
}
BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}