/*
Title: Bubble Sort Linked List Iterative

Problem statement
Given a singly linked list of integers, sort it using 'Bubble Sort.'

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first and the only line of each test case or query contains the elements of the singly linked 
list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, 
would never be a list element

Output format :
For each test case/query, print the elements of the sorted singly linked list.
Output for every test case will be printed in a seperate line.

Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
3 4 5 6 7 8 9 10 

Sample Input 2 :
10 -5 9 90 5 67 1 89 -1

Sample Output 2 :
-5 1 5 9 10 67 89 90
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

Node * bubbleSort(Node * head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}
	
	Node * temp = head;
	while(temp->next != NULL) {
		Node * node = head;
		while(node->next != NULL) {
			if(node->data > node->next->data) {
				int temp = node->data;
				node->data = node->next->data;
				node->next->data = temp;
			}

			node = node->next;
		}

		temp = temp->next;
	}

    return head;
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

void print(Node *head) {
	Node *temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);

	return 0;
}