/*
Title: Reverse Char Pattern

Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 5
E
ED
EDC
EDCB
EDCBA

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer N (Total no. of rows)

Output format :
Pattern in N lines

Constraints
0 <= N <= 50

Sample Input 1:
7

Sample Output 1:
G
GF
GFE
GFED
GFEDC
GFEDCB
GFEDCBA

Sample Input 1:
6

Sample Output 1:
F
FE
FED
FEDC
FEDCB
FEDCBA
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col <= row; col++) {
            cout << (char) ('A' + n - 1 - col) << " ";
        }
        cout << endl;
    }

    return 0;
}