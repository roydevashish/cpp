/*
Title: Pair Sum in a BST

Problem statement
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can 
use extra space of the order of O(log n).

Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the 
nodes of the tree is separated by space. If any node does not have left or right child, take -1 in 
its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it 
will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of S.

Output format:
You have to print each pair in a different line (pair elements separated by space). The order of 
different pairs, to be printed, does not matter.

Constraints:
Time Limit: 1 second   

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12

Sample Output 1:
2 10
5 7
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

bool searchBST(BinaryTreeNode<int> * root, int x) {
	if(root == NULL) {
		return false;
	}

	if(x == root->data) {
		return true;
	}

	if(x < root->data) {
		return searchBST(root->left, x);
	}

	if(x > root->data) {
		return searchBST(root->right, x);
	}
}

void printNodesSumToSHelper(BinaryTreeNode<int> * root, BinaryTreeNode<int> * node, int s) {
	if(node == NULL) {
		return;
	}

	printNodesSumToSHelper(root, node->left, s);
	if(node->data < (s - node->data) && searchBST(root, s - node->data) ) {
		cout << node->data << " " << s - node->data << endl;
	}
	printNodesSumToSHelper(root, node->right, s);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
	printNodesSumToSHelper(root, root, s);
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if(first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if(first->left != NULL) {
            q.push(first->left);
        }
        if(first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}