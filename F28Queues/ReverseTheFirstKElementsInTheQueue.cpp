/*
Title: Reverse the First k Elements in the Queue

Problem statement
For a given queue containing all integer data, reverse the first K elements.
You have been required to make the desired change in the input queue itself.

Example:
Input queue:
Front -> 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 <- Rear

For the above input queue, if K = 4 then after reversing the first 4 elements, the queue will be updated as:

Output queue:
Front -> 40 | 30 | 20 | 10 | 50 | 60 | 70 | 80 | 90 <- Rear

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input would contain two integers N and K, separated by a single space. They denote the 
total number of elements in the queue and the count with which the elements need to be reversed respectively.

The second line of input contains N integers separated by a single space, representing the order in which 
the elements are enqueued into the queue.

Output Format:
The only line of output prints the updated order in which the queue elements are dequeued, all of them 
separated by a single space. 

Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make 
the changes in the input queue itself.

Constraints :
1 <= N <= 10^6
1 <= K <= N
-2^31 <= data <= 2^31 - 1

Time Limit: 1sec

Sample Input 1:
5 3
1 2 3 4 5

Sample Output 1:
3 2 1 4 5

Sample Input 2:
7 7
3 4 2 5 6 7 8

Sample Output 2:
8 7 6 5 2 4 3
*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverseKElements(queue<int> &input, int k) {
	if(input.size() == 0 || k == 0 || k == 1) {
		return input;
	}

	int count = k;
	stack<int> x;
	while(count--) {
		x.push(input.front());
		input.pop();
	}

	while(!x.empty()) {
		input.push(x.top());
		x.pop();
	}

	count = input.size() - k;
	while(count--) {
		input.push(input.front());
		input.pop();
	}

	return input;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    queue<int> q;

    for(int i = 0, temp; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }

    queue<int> ans = reverseKElements(q, k);

    while(!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
}