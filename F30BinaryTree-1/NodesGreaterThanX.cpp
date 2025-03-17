/*
Title: Nodes Greater than X

Problem statement
For a given a binary tree of integers and an integer X, find and return the total number of nodes of the 
given binary tree which are having data greater than X.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as 
an indication whether the left or right node data exist for root, it will not be a part of the node data.
The second line of input contains an integer, denoting the value of X.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Output Format:
The only line of output prints the total number of nodes where the node data is greater than X.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
1 4 2 3 -1 -1 -1
2

Sample Output 1:
2

Explanation for Sample Input 1:
Out of the four nodes of the given binary tree, [3, 4] are the node data that are greater than X = 2.

Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
5

Sample Output 2:
3
*/

#include<iostream>
#include<queue>
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

int countNodesGreaterThanX(BinaryTreeNode<int>* root, int x) {
	if(root== NULL) {
		return 0;
	}

	int leftCount = countNodesGreaterThanX(root->left, x);
	int rightCount = countNodesGreaterThanX(root->right, x);

	if(root->data > x) {
		return leftCount+rightCount+1;
	}
	
    return leftCount+rightCount;
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

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int x;
    cin >> x;
    cout << countNodesGreaterThanX(root, x);
}