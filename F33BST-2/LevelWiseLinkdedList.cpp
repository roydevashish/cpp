/*
Title: Level wise LinkedList

Problem statement
Given a binary tree, write code to create a separate linked list for each level. You need to return 
the array which contains head of each level linked list.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the 
nodes of the tree is separated by space. If any node does not have left or right child, take -1 in 
its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it 
will not be a part of the data of any node.

Output format :
Each level linked list is printed in new line (elements are separated by space).

Constraints:
Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:
5 
6 10 
2 3 
9
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
	vector<Node<int> *> output;

	if(root == NULL) {
		return output;
	}

	queue<BinaryTreeNode<int> *> q;
	q.push(root);
	while(!q.empty()) {
		int size = q.size();
		Node<int> * head = NULL;
		for(int i = 0; i < size; i++) {
			BinaryTreeNode<int> * front = q.front();
			q.pop();
			if(front->right != NULL) {
				q.push(front->right);
			}

			if(front->left != NULL) {
				q.push(front->left);
			}

			if(head == NULL) {
				Node<int> * newNode = new Node<int>(front->data);
				head = newNode;
			} else {
				Node<int> * newNode = new Node<int>(front->data);
				newNode->next = head;
				head = newNode;
			}
		}
		output.push_back(head);
	}

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

void print(Node<int> *head) {
    Node<int> *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for(int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}