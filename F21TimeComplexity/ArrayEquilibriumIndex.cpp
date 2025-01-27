/*
Title: Array Equilibrium Index

Problem statement
For a given array/list(ARR) of size 'N,' find and return the 'Equilibrium Index' of the array/list.
Equilibrium Index of an array/list is an index 'i' such that the sum of elements at indices [0 to(i - 1)]
is equal to the sum of elements at indices [(i + 1) to (N-1)]. One thing to note here is, the item at the
index 'i' is not included in either part.
If more than one equilibrium indices are present, then the index appearing first in left to right fashion
should be returned. Negative one(-1) if no such index is present.

Example:
Let's consider an array/list Arr = [2, 3, 10, -10, 4, 2, 9]  of size, N = 7.
There exist three equilibrium indices, one at 2, another at 3, and another at 5.
At index 2, the sum of all the elements to the left, [2 + 3] is 5, and the elements to its right, [-10 + 4 + 2 + 9]
is also 5. Hence index 2 is an equilibrium index according to the condition we want to achieve. Mind it that we haven't
included the item at index 2, which is 10, to either of the parts.
Similarly, we can see at index 3 and 5, the elements to its left sum up to 15 and 9 respectively and to the right,
sum up to 15 and 9 respectively either.
Hence the answer would be 2.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains an integer 'N' representing the size of the first array/list.
The second line contains 'N' single space separated integers representing the elements of the array/list

Output Format :
For each test case, print the 'Equilibrium Index'.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec

Sample Input 1 :
1
5
1 4 9 3 2

Sample Output 1 :
2

Sample Input 2 :
2
3
1 4 6
3
1 -1 4

Sample Output 2 :
-1
2
*/

#include<iostream>
using namespace std;

// Optimization 02: Using single pointer.
int FindEquilibriumIndex(int array[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += array[i];
    }

    int current_sum = 0;
    for(int i = 0; i < size; i++) {
        sum -= array[i];

        if(current_sum == sum) {
            return i;
        }

        current_sum += array[i];
    }

    return -1;
}

// Optimization 01: Using prefix sum and suffix sum
/*
int FindEquilibriumIndex(int array[], int size) {
    int prefix_sum[size];
    for(int i = 0; i < size; i++) {
        prefix_sum[i] = array[i];
    }
    for(int i = 1; i < size; i++) {
        prefix_sum[i] += prefix_sum[i-1];
    }

    int suffix_sum[size];
    for(int i = 0; i < size; i++) {
        suffix_sum[i] = array[i];
    }
    for(int i = size-2; i >= 0; i--) {
        suffix_sum[i] += suffix_sum[i+1];
    }

    for(int i = 0; i < size; i++) {
        if(prefix_sum[i] == suffix_sum[i]) {
            return i;
        }
    }

    return -1;
}
*/

// Burt force
// for each index calculate the sum on left side and right side
/*
int FindEquilibriumIndex(int array[], int size) {
    for(int i = 0; i < size; i++) {
        int left_sum = 0;
        for(int left = 0; left < i; left++) {
            left_sum += array[left];
        }

        int right_sum = 0;
        for(int right = i+1; right < size; right++) {
            right_sum += array[right];
        }

        if(left_sum == right_sum) {
            return i;
        }
    }

    return -1;
}
*/

int main() {
	int t;
	cin >> t;
	while(t--) {
		int size;
		cin >> size;
		int *input = new int[size];

		for(int i = 0; i < size; i++) {
			cin >> input[i];
		}

		cout << FindEquilibriumIndex(input, size) << endl;

		delete[] input;
	}
	return 0;
}