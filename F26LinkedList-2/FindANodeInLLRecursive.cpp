/*
Title: Find a Node in LL Recursive

Problem statement
Given a singly linked list of integers and an integer n, find and return the index for the 
first occurrence of 'n' in the linked list. -1 otherwise.

Follow a recursive approach to solve this.

Note :
Assume that the Indexing for the linked list always starts from 0.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.
    The first line of each test case or query contains the elements of the singly linked list 
    separated by a single space.
    The second line of input contains a single integer depicting the value of 'n'.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, 
would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.
Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit:  1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
100

Sample Output 1 :
-1

Sample Input 2 :
2
10 20010 30 400 600 -1
20010
100 200 300 400 9000 -34 -1
-34

Sample Output 2 :
1
5
*/

#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

int findNodeRec(Node * head, int val) {
    if(head == NULL) {
        return -1;
    }

    if(head->data == val) {
        return 0;
    }

    int samllOutput = findNodeRec(head->next, val);
    if(samllOutput != -1) {
        return samllOutput+1;
    }
    return -1;
}

Node *takeinput() {
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while(data != -1) {
		Node *newnode = new Node(data);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		} else {
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
	}

	return 0;
}