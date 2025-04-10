/*
Title: Eliminate Duplicates

Problem statement
You have been given a singly linked list of integers where the elements are sorted in ascending order. 
Write a function that removes the consecutive duplicate values such that the given list only contains 
unique elements and returns the head to the updated list.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.
    The first and the only line of each test case or query contains the elements(in ascending order) 
    of the singly linked list separated by a single space.

Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a
single space.
Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec
Where 'M' is the size of the singly linked list.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, 
would never be a list element.

Sample Input 1 :
1
1 2 3 3 3 3 4 4 4 5 5 7 -1

Sample Output 1 :
1 2 3 4 5 7 

Sample Input 2 :
2
10 20 30 40 50 -1
10 10 10 10 -1

Sample Output 2 :
10 20 30 40 50
10
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



Node *takeinput() {
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1) {
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
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node * removeDuplicates(Node * head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node * temp = removeDuplicates(head->next);

    if(temp != NULL && head->data == temp->data) {
        return temp;
    }

    head->next = temp;
    return head;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}