/*
Title: Find Path in BST

Problem statement
Given a BST and an integer k. Find and return the path from the node with data k and root (if a 
node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the
nodes of the tree is separated by space. If any node does not have left or right child, take -1 in 
its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it 
will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.

Output Format :
The first line and only line of output prints the data of the nodes in the path from node k to root.
The data of the nodes is separated by single space.

Constraints:
Time Limit: 1 second   

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2

Sample Output 1:
2 5 8
*/

#include<iostream>
#include<queue>
#include<vector>
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

void getPathHelper(BinaryTreeNode<int> *root , int data, vector<int> **output) {
	if(root == NULL) {
		return;
	}

	getPathHelper(root->left, data, &*output);
	vector<int> *tempLeft = *output;
	if(tempLeft != NULL) {
		tempLeft->push_back(root->data);
		return;
	}

	getPathHelper(root->right, data, &*output);
	vector<int> *tempRight = *output;
	if(tempRight != NULL) {
		tempRight->push_back(root->data);
		return;
	}
	
	if(root->data == data) {
		vector<int> *temp = *output;
		temp->push_back(root->data);
		return;
	}
	
	return;
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	vector<int> *output;
	getPathHelper(root, data, &output);
	return output;
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

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if(output != NULL) {
        for(int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}