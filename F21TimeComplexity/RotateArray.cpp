/*
Title: Rotate Array

Problem statement
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the
given array/list by D elements(towards the left).
Note:
Change in the input array/list itself.You don't need to return or print the elements.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.
    First line of each test case or query contains an integer 'N' representing the size of the array/list.
    Second line contains 'N' single space separated integers representing the elements in the array/list.
    Third line contains the value of 'D' by which the array/list needs to be rotated.

Output Format :
For each test case, print the rotated array/list in a row separated by a single space.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^4
0 <= N <= 10^6
0 <= D <= N

Time Limit: 1 sec

Sample Input 1:
1
7
1 2 3 4 5 6 7
2

Sample Output 1:
3 4 5 6 7 1 2

Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2

Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2
*/

#include<iostream>
using namespace std;

// compromising space and optimizing time
void Rotate(int array[], int d, int size) {
    if(d % size == 0) {
        return;
    }

    int temp_array[d];
    for(int i = 0; i < d; i++) {
        temp_array[i] = array[i];
    }

    for(int i = 0; i < size - d; i++) {
        array[i] = array[i + d];
    }

    int idx = 0;
    for(int i = size - d; i < size; i++) {
        array[i] = temp_array[idx++];
    }
}

// compromising time and optimizing space
/*
void Rotate(int array[], int d, int size) {
    if(d % size == 0) {
        return;
    }

    for(int i = 0; i < d; i++) {
        int temp = array[0];
        for(int i = 0; i < size - 1; i++) {
            array[i] = array[i+1];
        }
        array[size - 1] = temp;
    }
}
*/

int main() {
	int t;
	cin >> t;

	while(t--) {
		int size;
		cin >> size;

		int *input = new int[size];

		for(int i = 0; i < size; ++i) {
			cin >> input[i];
		}

		int d;
		cin >> d;

		Rotate(input, d, size);

		for(int i = 0; i < size; ++i) {
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}

	return 0;
}