/*
Title: Construct BST

Problem statement
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a 
balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains 
n space separated integers, that denote the values of array.

Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.

Constraints:
Time Limit: 1 second

Sample Input 1:
7
1 2 3 4 5 6 7

Sample Output 1:
4 2 1 3 6 5 7
*/

#include<iostream>
#include<queue>
using namespace std;

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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

BinaryTreeNode<int> * constructBinaryTree(int *input, int n, int idxStart, int idxEnd) {
	if(idxStart > idxEnd) {
		return NULL;
	}

	int idxMid = (idxStart +idxEnd) / 2;

	BinaryTreeNode<int> *left = constructBinaryTree(input, n, idxStart, idxMid-1);
	BinaryTreeNode<int> *right = constructBinaryTree(input, n, idxMid+1, idxEnd);

	BinaryTreeNode<int> *root = new BinaryTreeNode(input[idxMid]);
	root->left = left;
	root->right = right;

	return root;
};

BinaryTreeNode<int>* constructTree(int *input, int n) {
	return constructBinaryTree(input, n, 0, n-1);
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}