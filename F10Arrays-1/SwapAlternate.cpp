/*
Title: Swap Alternate

Problem statement
You have been given an array/list(ARR) of size N. You need to swap every pair of alternate elements 
in the array/list.

You don't need to print or return anything, just change in the input array itself.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
For each test case, print the elements of the resulting array in a single row separated by a single space.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5

Time Limit: 1sec

Sample Input 1:
1
6
9 3 6 12 4 32

Sample Output 1 :
3 9 12 6 32 4

Sample Input 2:
2
9
9 3 6 12 4 32 5 11 19
4
1 2 3 4

Sample Output 2 :
3 9 12 6 32 4 11 5 19 
2 1 4 3
*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	for(int test_case = 0; test_case < t; test_case++) {
		int n;
		cin >> n;
		int array[n];
		for (int i = 0; i < n; i++) {
			cin >> array[i];
		}

        for(int i = 0; i < n; i += 2) {
            if(i+1 < n) {    
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }

		for (int i = 0; i < n; i++) {
			cout << array[i] << " ";
		}
        
		cout << endl;
	}
}