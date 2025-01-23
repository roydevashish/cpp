/*
Title: Square Pattern

Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 4
4444
4444
4444
4444

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
7777777
7777777
7777777
7777777
7777777
7777777
7777777

Sample Input 1:
6

Sample Output 1:
666666
666666
666666
666666
666666
666666
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            cout << n;
        }
        cout << endl;
    }
    return 0;
}