/*
Title: Path Sum Root to Leaf

Problem statement
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum 
of all the node data along the path is equal to K.

Example:
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1

If you see in the above-depicted picture of Binary Tree, we see that there are a total of two paths, 
starting from the root and ending at the leaves which sum up to a value of K = 13.

The paths are:
a. 2 3 4 4
b. 2 3 8

One thing to note here is, there is another path in the right sub-tree in reference to the root, which
sums up to 13 but since it doesn't end at the leaf, we discard it.
The path is: 2 9 2(not a leaf)

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used 
as an indication whether the left or right node data exist for root, it will not be a part of the node 
data.
The second line of input contains an integer value K.

Output Format:
Lines equal to the total number of paths will be printed. All the node data in every path will be printed 
in a linear fashion taken in the order they appear from top to down bottom in the tree. A single space 
will separate them all.

Constriants:
1 <= N <= 10^5
0 <= K <= 10^8
Where N is the total number of nodes in the binary tree.

Time Limit: 1 second

Sample Input 1:
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13

Sample Output 1:
2 3 4 4 
2 3 8

Sample Input 2:
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13

Sample Output 2:
5 6 2
5 7 1
*/

#include<iostream>
#include<queue>
#include<string>
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

void rootToLeafPathsSumToK(BinaryTreeNode<int> * root, int k, string output) {
	if(root == NULL) {
		return;
	}

	int root_data = root->data;
	output = output + to_string(root_data) + ' ';
	if(root->left == NULL && root->right == NULL && root_data == k) {
		cout << output << endl;
		return;
	}

	rootToLeafPathsSumToK(root->left, k-root_data, output);
	rootToLeafPathsSumToK(root->right, k-root_data, output);
}


void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
	rootToLeafPathsSumToK(root, k, "");
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
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}