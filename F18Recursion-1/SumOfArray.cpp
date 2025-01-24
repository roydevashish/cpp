/*
Title: Sum of Array(Recursive)

Problem statement
Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :
Sum

Constraints :
1 <= N <= 10^3

Sample Input 1 :
3
9 8 9

Sample Output 1 :
26

Sample Input 2 :
3
4 2 1

Sample Output 2 :
7
*/

#include<iostream>
using namespace std;

int SumOfArray(int input[], int n) {
    if(n == 1) {
        return input[n-1];
    }

    return SumOfArray(input, n-1) + input[n-1];
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    cout << SumOfArray(input, n) << endl;
}