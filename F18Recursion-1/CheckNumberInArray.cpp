/*
Title: Check Number Recusively

Problem statement
Given an array of length N and an integer x, you need to find if x is present in the array or not.
Return true or false.
Do this recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
'true' or 'false'

Constraints :
1 <= N <= 10^3

Sample Input 1 :
3
9 8 10
8

Sample Output 1 :
true

Sample Input 2 :
3
9 8 10
2

Sample Output 2 :
false
*/

#include<iostream>
using namespace std;

bool CheckNumber(int input[], int n, int x) {
    if(input[n-1] == x) {
        return true;
    }

    if(n == 0) {
        return false;
    }

    return CheckNumber(input, n-1, x);
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

    if(CheckNumber(input, n, x)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}