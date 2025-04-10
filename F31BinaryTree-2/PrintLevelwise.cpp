/*
Title: Print Levelwise

Problem statement
For a given a Binary Tree of type integer, print the complete information of every node, when traversed in 
a level-order fashion.

To print the information of a node with data D, you need to follow the exact format : D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.

Example:
1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
For the above depicted Binary Tree, the level order travel will be printed as followed:

1:L:2,R:3
2:L:4,R:-1
3:L:5,R:6
4:L:-1,R:7
5:L:-1,R:-1    
6:L:-1,R:-1
7:L:-1,R:-1

Note: There is no space in between while printing the information for each node.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 
is used as an indication whether the left or right node data exist for root, it will not be a part of the 
node data.

Output Format:
Information of all the nodes in the Binary Tree will be printed on a different line where each node will 
follow a format of D:L:X,R:Y, without any spaces in between.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
8:L:3,R:10
3:L:1,R:6
10:L:-1,R:14
1:L:-1,R:-1
6:L:4,R:7
14:L:13,R:-1
4:L:-1,R:-1
7:L:-1,R:-1
13:L:-1,R:-1

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
1:L:2,R:3
2:L:4,R:5
3:L:6,R:7
4:L:-1,R:-1
5:L:-1,R:-1
6:L:-1,R:-1
7:L:-1,R:-1
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
};

void printLevelWise(BinaryTreeNode<int> * root) {
	if(root == NULL) {
		return;
	}

	queue<BinaryTreeNode<int> *> pendingNode;
	pendingNode.push(root);

	while(!pendingNode.empty()) {
		BinaryTreeNode<int> * node = pendingNode.front();
		pendingNode.pop();

		int left, right;

		if(node->left != NULL) {
			pendingNode.push(node->left);
			left = node->left->data;
		} else {
			left = -1;
		}

		if(node->right != NULL) {
			pendingNode.push(node->right);
			right = node->right->data;
		} else {
			right = -1;
		}

		cout << node->data << ":L:" << left << ",R:" << right << endl;
	}
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
        if (first == NULL) {
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
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}