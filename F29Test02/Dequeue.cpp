/*
Title: Dequeue

Problem statement
You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be 
inserted and deleted from both the ends.

You don't need to double the capacity.

You need to implement the following functions -

1. constructor
You need to create the appropriate constructor. Size for the queue passed is 10.

2. insertFront -
This function takes an element as input and insert the element at the front of queue. Insert the element 
only if queue is not full. And if queue is full, print -1 and return.

3. insertRear -
This function takes an element as input and insert the element at the end of queue. Insert the element 
only if queue is not full. And if queue is full, print -1 and return.

4. deleteFront -
This function removes an element from the front of queue. Print -1 if queue is empty.

5. deleteRear -
This function removes an element from the end of queue. Print -1 if queue is empty.

6. getFront -
Returns the element which is at front of the queue. Return -1 if queue is empty.

7. getRear -
Returns the element which is at end of the queue. Return -1 if queue is empty.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
For C++ and Java, input is already managed for you. You just have to implement given functions.

For Python:
The choice codes and corresponding input for each choice are given in a new line. The input is terminated 
by integer -1. The following table elaborately describes the function, their choice codes and their 
corresponding input - 

Function        Choice          Input Formate
insertFront     1               The function takes an integer as input.
insertRear      2               The function takes an integer as input.
deleteFront     3               The function doesn't takes any input.
deleteRear      4               The function doesn't takes any input.
getFront        5               The function doesn't takes any input.
getRear         6               The function doesn't takes any input.

Output Format:
For C++ and Java, output is already managed for you. You just have to implement given functions.

For Python: 
The output format for each function has been mentioned in the problem description itself. 

Sample Input 1:
5 1 49 1 64 2 99 5 6 -1

Sample Output 1:
-1
64
99

Explanation:
The first choice code corresponds to getFront. Since the queue is empty, hence the output is -1. 
The following input adds 49 at the top and the resultant queue becomes: 49.
The following input adds 64 at the top and the resultant queue becomes: 64 -> 49
The following input add 99 at the end and the resultant queue becomes: 64 -> 49 -> 99
The following input corresponds to getFront. Hence the output is 64.
The following input corresponds to getRear. Hence the output is 99.
*/

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * prev;
        Node * next;

        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

class Deque {
    // Complete this class
    private:
        int max_size;
        Node * head;
        Node * tail;
        int size;
    
    public:
        Deque(int max_size) {
            this->max_size = max_size;
            this->size = 0;
        }

        bool isEmpty() {
            return this->size == 0;
        }

        bool isFull() {
            return this->size == this->max_size;
        }

        void insertFront(int data) {
            if(this->isFull()) {
                cout << "-1" << endl;
                return;
            }

            Node * newNode = new Node(data);

            if(this->isEmpty()) {
                this->head = newNode;
                this->tail = newNode;
            } else {
                newNode->next = this->head;
                this->head->prev = newNode;
                this->head = newNode;
            }

            this->size++;
            return;
        }

        void insertRear(int data) {
            if(this->isFull()) {
                cout << "-1" << endl;
                return;
            }

            Node * newNode = new Node(data);

            if(this->isEmpty()) {
                this->head = newNode;
                this->tail = newNode;
            } else {
                newNode->prev = this->tail;
                this->tail->next = newNode;
                this->tail = newNode;
            }

            this->size++;
            return;
        }

        void deleteFront() {
            if(this->isEmpty()) {
                cout << "-1" << endl;
                return;
            }


            if(this->size == 1) {
                this->head = NULL;
                this->tail = NULL;
                this->size--;
                return;
            }

            this->head = this->head->next;
            this->head->prev = NULL;
            this->size--;
            return;
        }

        void deleteRear() {
            if(this->isEmpty()) {
                cout << "-1" << endl;
                return;
            }

            if(this->size == 1) {
                this->head = NULL;
                this->tail = NULL;
                this->size--;
                return;
            }

            this->tail = this->tail->prev;
            this->tail->next = NULL;
            this->size--;
            return;
        }

        int getFront() {
            if(this->isEmpty()) {
                return -1;
            }

            return this->head->data;
        }

        int getRear() {
            if(this->isEmpty()) {
                return -1;
            }

            return this->tail->data;
        }
};

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice, input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}