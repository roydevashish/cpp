/*
Title: BST to LL

Problem statement
Given a BST, convert it into a sorted linked list. You have to return the head of LL.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The 
data of the nodes of the tree is separated by space. If any node does not have left or right child, 
take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, 
therefore, it will not be a part of the data of any node.   

Output Format:
The first and only line of output prints the elements of sorted linked list.

Constraints:
Time Limit: 1 second
1<=n<=10^5

Note:
In case if you are facing any issue to solve this problem, please prefer to use the helper function.

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

Sample Output 1:
2 5 6 7 8 10
*/

#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

Node<int> * constructLinkedList(BinaryTreeNode<int>* root) {
	if(root == NULL) {
		return NULL;
	}

	Node<int> *left = constructLinkedList(root->left);
	Node<int> *right = constructLinkedList(root->right);

	Node<int> *tempRoot = new Node(root->data);
	tempRoot->next = right;

	Node<int> *tempLeft = left;
	while(tempLeft != NULL && tempLeft->next != NULL) {
		tempLeft = tempLeft->next;
	}

	if(tempLeft == NULL) {
		return tempRoot;
	} else {
		tempLeft->next = tempRoot;
		return left;
	}
}

BinaryTreeNode<int> * takeInput() {
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
    BinaryTreeNode<int> * root = takeInput();
    Node<int> * head = constructLinkedList(root);

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}