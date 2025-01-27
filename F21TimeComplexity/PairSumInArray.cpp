/*
Title: Pair sum in array

Problem statement
You have been given an integer array/list(ARR) and a number 'num'. Find and return the total
number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can contain duplicate elements.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the first array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.
Third line contains an integer 'num'.

Output format :
For each test case, print the total number of pairs present in the array/list.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec

Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7

Sample Output 1:
7

Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10

Sample Output 2:
0
2

Explanation for Input 2:
Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.
For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).
*/

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

// Optimization 02: Using two pointers
// Can be done need to handle the edge cases.
/*
int PairSum(int array[], int size, int sum) {
    sort(array, array + size);
    int left = 0;
    int right = size - 1;
    int count = 0;

    while(left < right) {
        if(array[left] + array[right] > sum) {
            right--;
        } else if(array[left] + array[right] < sum) {
            left++;
        } else {
            // equal to sum
            int left_x = 0;
            int idx_left = left;
            while(array[idx_left++] == array[left]) {
                left_x++;
            }

            int right_x = 0;
            int idx_right = right;
            while(array[idx_right--] == array[right]) {
                right_x++;
            }

            if(left_x == 0 && right_x == 0) {
                count++;
                left++;
                right--;
            } else {
                if(left_x > right_x) {
                    count += left_x;
                    left += left_x;
                } else if(left_x < right_x) {
                    count += right_x;
                    right -= right_x;
                } else {
                    count += right_x;
                    left += left_x;
                    right -= right_x;
                }
            }


        }
    }

    return count;
}
*/

// Optimization 01: Using map
int PairSum(int array[], int size, int sum) {
    int count = 0;
    map<int, int> mymap;

    for(int i = 0; i < size; i++) {
        mymap.insert({array[i], 0});
    }

    for(int i = 0; i < size; i++) {
        int target = sum - array[i];
        if(mymap.at(target)) {
            count += mymap.at(target);
        }
        mymap.at(array[i]) = mymap.at(array[i]) + 1;
    }

    return count;
}

// Burt Force
/*
int PairSum(int array[], int size, int x) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(array[i] + array[j] == x) {
                count += 1;
            }
        }
    }
    return count;
}
*/

int main() {
	int t;
	cin >> t;

	while(t--) {
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for(int i = 0; i < size; i++) {
			cin >> input[i];
		}

		cin >> x;

		cout << PairSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}