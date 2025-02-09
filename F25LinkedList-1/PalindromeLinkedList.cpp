/*
Title: Palindrome Linked List

Problem statement
You have been given a head to a singly linked list of integers. Write a function check to whether 
the list given is a 'Palindrome' or not.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.
    First and the only line of each test case or query contains the the elements of the singly linked 
    list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, 
would never be a list element.

Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec
Where 'M' is the size of the singly linked list.

Sample Input 1 :
1
9 2 3 3 2 9 -1

Sample Output 1 :
true

Sample Input 2 :
2
0 2 3 2 5 -1
-1

Sample Output 2 :
false
true

Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.
For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
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


#include <stack>

int countOfNodes(Node *head) {
    if(head == NULL) {
        return 0;
    }

    int smallOutput = countOfNodes(head->next);
    return 1 + smallOutput;
}

bool isPalindrome(Node *head) {
    stack<int> S;
    int count = countOfNodes(head);
    int mid = count/2;

    int idx = 0;
    Node *temp = head;
    while(temp != NULL && idx < mid) {
        S.push(temp->data);
        idx++;
        temp = temp->next;
    } 

    if(count % 2 != 0) {
        temp = temp->next;
    }

    while(temp != NULL) {
        if(temp->data != S.top()) {
            return false;
        }
        
        S.pop();
        temp = temp->next;
    }

    return true;
}

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

int main() {
	int t;
	cin >> t;

	while (t--) {
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}