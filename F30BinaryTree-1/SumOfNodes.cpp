/*
Title: Sum of Nodes

Problem statement
For a given Binary Tree of integers, find and return the sum of all the nodes data.

Example:
10 20 30 40 50 -1 -1 -1 -1 -1 -1
When we sum up all the nodes data together, we get 150. Hence, the output will be 150.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input will contain the nodes data, all separated by a single space. 
Since -1 is used as an indication whether the left or right node data exist for root, it will not 
be a part of the node data.

Output Format:
The first and the only line of output prints the sum of all the nodes data present in the binary tree.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
2 3 4 6 -1 -1 -1 -1 -1

Sample Output 1:
15

Explanation :
The binary tree formed using the input values: 2, 3, 4, 6, -1, -1, -1, -1, -1. Hence the sum is 15. 

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
28
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

int getSum(BinaryTreeNode<int>* root) {
	if(root == NULL) {
		return 0;
	}

	int leftSum = getSum(root->left);
	int rightSum = getSum(root->right);
	return root->data + leftSum + rightSum;
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
    cout << getSum(root);
}