/*
Title: Level Order Traversal

Problem statement
For a given a Binary Tree of type integer, print it in a level order fashion where each level will be 
printed on a new line. Elements on every level will be printed in a linear fashion and a single space 
will separate them.

Example:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

For the above-depicted tree, when printed in a level order fashion, the output would look like:
10
20 30 
40 50 60

Where each new line denotes the level in the tree.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 
is used as an indication whether the left or right node data exist for root, it will not be a part of the 
node data.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line.
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 

Sample Output 1:
10 
20 30 
40 50 60 

Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
8 
3 10 
1 6 14 
4 7 13
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

void printLevelWise(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return;
	}

	queue<BinaryTreeNode<int> *> q1;
	queue<BinaryTreeNode<int> *> q2;
	q1.push(root);

	while(!q1.empty()) {
		BinaryTreeNode<int> * front = q1.front();
		cout << front->data << " ";
		q1.pop();

		if(front->left != NULL) {
			q2.push(front->left);
		}

		if(front->right != NULL) {
			q2.push(front->right);
		}

		if(q1.empty()) {
			queue<BinaryTreeNode<int> *> temp = q2;
			q2 = q1;
			q1 = temp;
			cout << endl;
		}
	}
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
    printLevelWise(root);
}