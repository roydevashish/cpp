/*
Title: Last Index of x

Problem statement
Given an array of length N and an integer x, you need to find and return the last index of integer
x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes
last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
last index or -1

Constraints :
1 <= N <= 10^3

Sample Input :
4
9 8 10 8
8

Sample Output :
3
*/

#include<iostream>
using namespace std;

int LastIndexRecursive(int input[], int n, int x, int idx) {
    if(idx == n) {
        return -1;
    }

    int result = LastIndexRecursive(input, n, x, idx+1);

    if(input[idx] == x && result == -1) {
        return idx;
    }

    return result;
}

int LastIndex(int input[], int n, int x) {
    return LastIndexRecursive(input, n, x, 0);
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;
    cin >> x;

    cout << LastIndex(input, n, x) << endl;
}