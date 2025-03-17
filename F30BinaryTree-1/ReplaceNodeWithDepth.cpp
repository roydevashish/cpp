/*
Title: Replace Node with Depth

Problem statement
For a given a Binary Tree of integers, replace each of its data with the depth of the tree.
Root is at depth 0, hence the root data is updated with 0. Replicate the same further going down the in 
the depth of the given tree.
The modified tree will be printed in the in-order fashion.

Example:
2 3 3 6 6 6 6 -1 -1 -1 -1 -1 -1 -1 -1 

The above tree after updating will look like this:
0 1 1 2 2 2 2 -1 -1 -1 -1 -1 -1 -1 -1 

Output: 2 1 2 0 2 1 2 (printed in the in-order fashion)

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 
is used as an indication whether the left or right node data exist for root, it will not be a part of the 
node data.

Output Format:
The first and the only line of output prints the updated tree in the in-order fashion.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1sec

Sample Input 1:
2 35 10 2 3 5 2 -1 -1 -1 -1 -1 -1 -1 -1 

Sample Output 1:
2 1 2 0 2 1 2 

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
2 1 2 0 2 1 2
*/

#include <iostream>
#include <queue>
using namespace std;

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

void changeToDepthTree(BinaryTreeNode<int> * root, int x) {
	if(root == NULL) {
		return;
	}

	root->data = x;
	changeToDepthTree(root->left, x+1);
	changeToDepthTree(root->right, x+1);
	return;
}

void changeToDepthTree(BinaryTreeNode<int>* root) {
	changeToDepthTree(root, 0);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void inOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);

    cout << root->data << " ";
    
    inOrder(root->right);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    changeToDepthTree(root);
    inOrder(root);
}