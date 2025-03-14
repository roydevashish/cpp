/*
Title:
Problem statement
You have been given a singly linked list of integers, an integer value called 'data' and a position 
with the name 'pos.' Write a function to add a node to the list with the 'data' at the specified 
position, 'pos.'

Note :
Assume that the Indexing for the singly linked list always starts from 0.
If the position is greater than the length of the singly linked list, you should return the same
linked list without any change.

Illustration :
The following images depict how the insertion has been taken place.
Image-I :
Head -> 10 -> 20 -> 30 -> 40 -> NULL

Image-II :
100 -> NULL

Image-III :
Head -> 10 -> 20 -> 30       40 -> NULL
                    |-> 100 ->|

Image-IV :
Head -> 10 -> 20 -> 30 -> 100 -> 40 -> NULL

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.
    The first line of each test case or query contains the elements of the linked list separated by
    a single space. 
    The second line contains the two integer values of 'data' and 'pos' separated by a single space,
    respectively

Reminder/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, 
would never be a list element.

Output format :
For each test case, print the resulting singly linked list of integers in a row, separated by a single space.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
pos >= 0

Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 100

Sample Output 1 :
3 4 5 100 2 6 1 9

Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0 20
10 98 7 66 8 -1
5 99

Sample Output 2 :
20 3 4 5 2 6 1 9
10 98 7 66 8 99
*/

#include <iostream>
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

Node * insert(Node * head, int pos, int data) {
    if(head == NULL) {
        if(pos == 0) {
            return new Node(data);
        }

        return NULL;
    }

    int idx = 0;
    Node * prev = NULL;
    Node * current = head;

    while(current != NULL && idx < pos) {
        idx++;
        prev = current;
        current = current->next;
    }

    if(pos == 0) {
        Node * newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }

	if(idx == pos) {
		Node * newNode = new Node(data);
		newNode->next = current;
		prev->next = newNode;
	}
	
    return head;
}

Node *takeinput() {
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1) {
		Node *newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
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

int main() {
	int t;
	cin >> t;
	while (t--) {
		Node *head = takeinput();
		int pos, data;
		cin >> pos >> data;
		head = insert(head, pos, data);
		print(head);
	}
	return 0;
}