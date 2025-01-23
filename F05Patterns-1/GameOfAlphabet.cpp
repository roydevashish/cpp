/*
Title: Game of Alphabet

Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 3
A
A B
A B C

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
Integer N (Total no. of rows)

Output Format:
Pattern in N lines

Constraints:
10 <= N <= 50

Sample Input 1:
3

Sample Output 1:
A
A B
A B C

Sample Input 2:
5  

Sample Output 2:
A
A B
A B C
A B C D
A B C D E
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col <= row; col++) {
            cout << (char) ('A' + col) << " ";
        }
        cout << endl;
    }

    return 0;
}