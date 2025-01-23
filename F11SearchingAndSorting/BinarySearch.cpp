/*
Title: Binary Search

Problem statement
You are given an integer array 'A' of size 'N', sorted in non-decreasing order. You are also given 
an integer 'target'. Your task is to write a function to search for 'target' in the array 'A'. If 
it exists, return its index in 0-based indexing. If 'target' is not present in the array 'A', return -1.

Note:
You must write an algorithm whose time complexity is O(LogN)

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 'N', which denotes the size of the array/list.
The second line contains 'N' single space-separated integers representing the elements in the array/list.
The third line contains the value of 'target' to be searched for in the array/list.

Output Format :
Return the index at which 'target' is present for each test case, -1 otherwise.

Constraints :
1 <= N <= 10^5
1 <= A[i] <= 10^9
1 <= target <= 10^9

Time Limit: 1 sec

Sample Input 1:
7
1 3 7 9 11 12 45
3

Sample Output 1:
1

Explanation of sample output 1:
nums = [1, 3, 7, 9, 11, 12, 45],
The index of element '3' is 1.
Hence, the answer is '1'.

Sample Input 2:
7
1 2 3 4 5 6 7
9

Sample Output 2:
-1

Explanation of sample output 2:
nums = [1, 2, 3, 4, 5, 6, 7],
Element '9' doesn't exist.
Hence, the answer is '-1'.
*/

#include<iostream>
using namespace std;

int BinarySearchRecursive(int array[], int start, int end, int key) {
    if(start > end) {
        return -1;
    }

    int mid = (start + end) / 2;
    
    if(array[mid] == key) {
        return mid;
    } else if(array[mid] > key) {
        return BinarySearchRecursive(array, start, mid - 1, key);
    } else {
        return BinarySearchRecursive(array, mid + 1, end, key);
    }
}

int BinarySearch(int array[], int size, int key) {
    return BinarySearchRecursive(array, 0, size - 1, key);   
}

int main() {
    int size;
    cin >> size;
    int array[size];
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }
    int key;
    cin >> key;

    cout << BinarySearch(array, size, key) << endl;

    return 0;
}