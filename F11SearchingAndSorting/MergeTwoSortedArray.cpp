/*
Title: Merge Two Sorted Array

Problem statement
You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively, merge them 
into a third array/list such that the third array is also sorted.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.
Second line contains 'N' single space separated integers representing the elements of the first array/list.
Third line contains an integer 'M' representing the size of the second array/list.
Fourth line contains 'M' single space separated integers representing the elements of the second array/list.

Output Format :
For each test case, print the sorted array/list(of size N + M) in a single row, separated by a single space.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5

Time Limit: 1 sec 

Note:
Consider the case when size of the two arrays is not same.

Sample Input 1 :
1
5
1 3 4 7 11
4
2 4 6 13

Sample Output 1 :
1 2 3 4 4 6 7 11 13 

Sample Input 2 :
2
3
10 100 500
7
4 7 9 25 30 300 450
4
7 45 89 90
0

Sample Output 2 :
4 7 9 10 25 30 100 300 450 500
7 45 89 90
*/

#include<iostream>
using namespace std;

void MergeTwoSortedArray(int array_1[], int size_1, int array_2[], int size_2) {
    int array_merged[size_1 + size_2];
    
    int idx_1 = 0;
    int idx_2 = 0;
    int idx_merged = 0;

    while(idx_1 < size_1 && idx_2 < size_2) {
        if(array_1[idx_1] <= array_2[idx_2]) {
            array_merged[idx_merged] = array_1[idx_1];
            idx_1++;
        } else {
            array_merged[idx_merged] = array_2[idx_2];
            idx_2++;
        }
        
        idx_merged++;
    }

    while(idx_1 < size_1) {
        array_merged[idx_merged] = array_1[idx_1];
        idx_1++;
        idx_merged++;
    }

    while(idx_2 < size_2) {
        array_merged[idx_merged] = array_2[idx_2];
        idx_2++;
        idx_merged++;
    }


    for(int i = 0; i < size_1 + size_2; i++) {
        cout << array_merged[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++) {
        int size_1;
        cin >> size_1;

        int array_1[size_1];
        for(int i = 0; i < size_1; i++) {
            cin >> array_1[i];
        }

        int size_2;
        cin >> size_2;
        int array_2[size_2];
        for(int i = 0; i < size_2; i++) {
            cin >> array_2[i];
        }

        MergeTwoSortedArray(array_1, size_1, array_2, size_2);
    }

    return 0;
}