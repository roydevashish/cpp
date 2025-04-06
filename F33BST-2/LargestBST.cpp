/*
Title: Largest BST

Problem statement
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum 
height in the given binary tree. You have to return the height of largest BST.

Note :
The binary tree will be consisting of only unique elements.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the 
nodes of the tree is separated by space. If any node does not have left or right child, take -1 in 
its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it 
will not be a part of the data of any node.

Output format:
The first and only line of output contains the height of the largest BST.

Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^6

Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:
2
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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

class CustomeBinaryTreeReturn {
	public:
    int minimum;
    int maximum;
    bool isBST;
    int height;

    CustomeBinaryTreeReturn(int minimum, int maximum, bool isBST, int height) {
        this->minimum = minimum;
        this->maximum = maximum;
        this->isBST = isBST;
        this->height = height;
    }
};

CustomeBinaryTreeReturn * largestBSTSubtreeHelper(BinaryTreeNode<int> * root) {
	if(root == NULL) {
		return new CustomeBinaryTreeReturn(INT_MAX, INT_MIN, true, 0);
	}

	CustomeBinaryTreeReturn * left = largestBSTSubtreeHelper(root->left);
	CustomeBinaryTreeReturn * right = largestBSTSubtreeHelper(root->right);

	int min_x = min(root->data, min(left->minimum, right->minimum));
	int max_x = max(root->data, max(left->maximum, right->maximum));
	int height = max(left->height, right->height);
	bool isBST = true;

	if(left->maximum >= root->data) {
		isBST = false;
	}

	if(right->minimum < root->data) {
		isBST = false;
	}

	if(!left->isBST) {
		isBST = false;
	}

	if(!right->isBST) {
		isBST = false;
	}

	if(isBST) {
		return new CustomeBinaryTreeReturn(min_x, max_x, isBST, height+1);
	}

	return new CustomeBinaryTreeReturn(min_x, max_x, isBST, height);
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
	CustomeBinaryTreeReturn * output = largestBSTSubtreeHelper(root);
	return output->height;
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
    cout << largestBSTSubtree(root);
    delete root;
}