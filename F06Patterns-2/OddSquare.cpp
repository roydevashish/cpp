/*
Title: Odd Square

Problem statement
Write a program to print the pattern for the given N number of rows.

For N = 4
1357
3571
5713
7135

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
135
351
513

Sample Input 2 :
5

Sample Output 2 :
13579
35791
57913
79135
91357
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col=2*row+1; col < 2*n+1; col+=2) {
            cout << col << " ";
        }

        for(int col = 1; col < 2*row+1; col += 2) {
            cout << col << " ";
        }

        cout << endl;
    }
    return 0;
}