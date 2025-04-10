/*
Title: Linear Search

Problem statement
You have been given a random integer array/list(ARR) of size N, and an integer X. You need to search 
for the integer X in the given array/list using 'Linear Search'.

You have been required to return the index at which X is present in the array/list. If X has multiple 
occurrences in the array/list, then you need to return the index at which the first occurrence of X 
would be encountered. In case X is not present in the array/list, then return -1.

'Linear search' is a method for finding an element within an array/list. It sequentially checks each 
element of the array/list until a match is found or the whole array/list has been searched.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains the value of X(integer to be searched in the given array/list)

Output format :
For each test case, print the index at which X is present or -1, otherwise.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
-2 ^ 31 <= X <= (2 ^ 31) - 1

Time Limit: 1 sec

Sample Input 1:
1
7
2 13 4 1 3 6 28
3

Sample Output 1:
4

Sample Input 2:
2
7
2 13 4 1 3 6 28
9
5
7 8 5 9 5      
5

Sample Output 2:
-1
2
*/

#include<iostream>
using namespace std;

int LinearSearch(int array[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(array[i] == key) {
            return i;
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++) {
        int n;
        cin >> n;

        int array[n];
        for(int i = 0; i < n; i++) {
            cin >> array[i];
        }

        int key;
        cin >> key;

        cout << LinearSearch(array, n, key) << endl;
    }
    return 0;
}