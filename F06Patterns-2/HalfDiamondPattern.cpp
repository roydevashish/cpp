/*
Title: Half Diamond Pattern

Problem statement
Write a program to print N number of rows for Half Diamond pattern using stars and numbers
Note : There are no spaces between the characters in a single line.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
A single integer: N

Output Format :
Required Pattern

Constraints :
0 <= N <= 50

Sample Input 1 :
3

Sample Output 1 :
*
*1*
*121*
*12321*
*121*
*1*
*

Sample Input 2 :
5

Sample Output 2 :
*
*1*
*121*
*12321*
*1234321*
*123454321*
*1234321*
*12321*
*121*
*1*
*
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << "*" << endl;

    for(int row = 0; row < n; row++) {
        cout << "*";

        for(int col = 1; col <= row+1; col++) {
            cout << col;
        }

        for(int col = row; col >= 1; col--) {
            cout << col;
        }

        cout << "*" << endl;
    }

    for(int row = n-2; row >= 0; row--) {
        cout << "*";

        for(int col = 1; col <= row+1; col++) {
            cout << col;
        }

        for(int col = row; col >= 1; col--) {
            cout << col;
        }

        cout << "*" << endl;
    }

    cout << "*" << endl;
    return 0;
}