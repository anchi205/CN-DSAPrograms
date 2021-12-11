#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"
#include <queue>
void printLevelWise(BinaryTreeNode<int> *root) {
	if (root == NULL) {                                              // Corner Case
		return;
	}
    
    queue<BinaryTreeNode<int>*> pendingNodes;                        // Create a Queue
    pendingNodes.push(root);                                         // Push the root first
    
    while (pendingNodes.size() != 0) {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
		pendingNodes.pop();                                          // Root changes
    
        cout << frontNode->data <<":";                                   // Root
		
        if (frontNode->left) {                                           // Left Child
            cout << "L:" << frontNode->left->data << "," ;
			pendingNodes.push(frontNode->left);
		}
        else{
            cout << "L:-1,";
        }
		
        if (frontNode->right) {                                          // Right Child
            cout << "R:" << frontNode->right->data;
		    pendingNodes.push(frontNode->right);
	    }
        else{
            cout << "R:-1" ;
        }
        cout << endl;                                                // Next Root
    }
}
/*
Time Complexity: O(N) -- N - No of nodes in the input tree
Space Complexity: O(N)
*/

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}