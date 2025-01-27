/*
Title: Find the unique element

Problem statement
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.

Note:
Unique element is always present in the array/list according to the given condition.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
For each test case, print the unique element present in the array.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec

Sample Input 1:
1
7
2 3 1 6 3 6 2

Sample Output 1:
1

Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7

Sample Output 2:
4
10
*/

#include<iostream>
#include<algorithm>
using namespace std;

// Optimization 02: By using XOR operation
int FindUnique(int array[], int size) {
    int val = 0;
    for(int i = 0; i < size; i++) {
        val = val ^ array[i];
    }

    return val;
}

// Optimization 01: By sorting the array
/*
int FindUnique(int array[], int size) {
    sort(array, array+size);                // nlogn

    for(int i = 0; i < size - 1; i+2) {     // n
        if(array[i] != array[i+1]) {
            return array[i];
        }
    }
    return -1;
}
*/

// Burt Force
/*
int FindUnique(int array[], int size) {
    int i = 0;
    for(i; i < size; i++) {
        int j = 0;
        for(j; j < size; j++) {
            if(i != j && array[i] == array[j]) {
                break;
            }
        }
        if(array[i] != array[j]) {
            return array[i];
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

        for(int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << FindUnique(input, size) << endl;
    }

    return 0;
}