/*
Title: Print Nodes at Distance K from Node

Problem statement
You are given a Binary Tree of type integer, a integer value of target node's data, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be 
printed will not matter.

Example:
For a given input tree(refer to the image below):
1. Target Node: 5
2. K = 2

3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
Starting from the target node 5, the nodes at distance K are 7 4 and 1.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as 
an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains two integers separated by a single space, representing the value of 
the target node and K, respectively.

Output Format:
All the node data at distance K from the target node will be printed on a new line.
The order in which the data is printed doesn't matter.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.
1 ≤ data of node ≤ 10^9
1 ≤ target ≤ 10^9

Time Limit: 1 sec

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1

Sample Output 1:
9
6

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3

Sample Output 2:
4
5
*/

#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

void nodesAtDistanceKFromRoot(BinaryTreeNode<int> * node, int k) {
    if(node == NULL || k < 0) {
        return;
    }

    if(k == 0) {
        cout << node->data << endl;
        return;
    }

    nodesAtDistanceKFromRoot(node->left, k-1);
    nodesAtDistanceKFromRoot(node->right, k-1);
}

int printNodesAtDistanceK(BinaryTreeNode<int> * root, int node, int k) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == node) {
        nodesAtDistanceKFromRoot(root, k);
        return 0;
    }

    int ld = printNodesAtDistanceK(root->left, node, k);
    if(ld != -1) {
        if(ld+1 == k) {
            cout << root->data << endl; 
        } else {
            nodesAtDistanceKFromRoot(root->right, k-ld-2);
        }
        return 1+ld;
    }

    int rd = printNodesAtDistanceK(root->right, node, k);
    if(rd != -1) {
        if(rd+1 == k) {
            cout << root->data << endl;
        } else {
            nodesAtDistanceKFromRoot(root->left, k-rd-2);
        }
        return 1 + rd;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    printNodesAtDistanceK(root, node, k);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}