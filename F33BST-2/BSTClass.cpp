/*
Title: BST Class

Problem statement
Implement the BST class which includes following functions -
1. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to 
the data of the node, insert it in the left subtree.

2. search
Given an element, find if that is present in BST or not. Return true or false.

3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both 
children, replace that with the minimum element from right sub-tree.

4. printTree (recursive) -
Print the BST in in the following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y

where, N is data of any node present in the binary tree. x and y are the values of left and right 
child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.

Sample Input 1:
6
1 2
1 3
1 1
4
2 2
4

Sample Output 1:
2:L:1,R:3
1:
3:
3:L:1,
1:

Explanation for sample Input 1:
Explanation: The first line 6 indicates that there are 6 operations to be performed on the BST.
The subsequent lines are the operations, which can be understood as follows:
    1 2: Insert 2 into the BST.

    1 3: Insert 3 into the BST.

    1 1: Insert 1 into the BST.

    4: Print the BST in the specified format.

    2 2: Search for 2 in the BST.

    4: Print the BST in the specified format.
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

class BST {
    private:
    BinaryTreeNode<int> * root;

    public:
    BST() { 
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/
    BinaryTreeNode<int> * removeHelper(BinaryTreeNode<int> * node, int data) {
        if(node == NULL) {
            return NULL;
        }

        if(data < node->data) {
            node->left = removeHelper(node->left, data);
            return root;
        } else if(data > node->data) {
            node->right = removeHelper(node->right, data);
            return node;
        } else {
            if(node->left == NULL && node->right == NULL) {
                return NULL;
            } else if(node->left == NULL) {
                return node->right;
            } else if(node->right == NULL) {
                return node->left;
            } else {
                BinaryTreeNode<int> * minNode = node->right;
                while(minNode->left != NULL) {
                    minNode = minNode->left;
                }

                node->data = minNode->data;
                node->right = removeHelper(node->right, minNode->data);
                return node;
            }
        }
    }

    void remove(int data) { 
        this->root = removeHelper(this->root, data);
    }

    void printHelper(BinaryTreeNode<int> * node) {
        if(node == NULL) {
            return;
        }

        cout << node->data << ":";
        if(node->left != NULL) {
            cout << "L:" << node->left->data << ",";
        }

        if(node->right != NULL) {
            cout << "R:" << node->right->data;
        }
        cout << endl;

        printHelper(node->left);
        printHelper(node->right);
    }

    void print() { 
        printHelper(this->root);
    }

    BinaryTreeNode<int> * insertHelper(BinaryTreeNode<int> * node, int data) {
        if(node == NULL) {
            BinaryTreeNode<int> * newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if(data <= node->data) {
            node->left = insertHelper(node->left, data);
        }

        if(data > node->data) {
            node->right = insertHelper(node->right, data);
        }

        return node;
    }

    void insert(int data) { 
        this->root = insertHelper(this->root, data); 
    }

    bool searchHelper(BinaryTreeNode<int> * node, int data) {
        if(node == NULL) {
            return false;
        }

        if(node->data == data) {
            return true;
        }

        if(data < node->data) {
            return searchHelper(node->left, data);
        } else if(data > node->data) {
            return searchHelper(node->right, data);
        }
    }

    bool search(int data) {
        return searchHelper(this->root, data);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while(q--) {
        cin >> choice;
        switch(choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}