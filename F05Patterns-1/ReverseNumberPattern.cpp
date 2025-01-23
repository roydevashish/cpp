/*
Title: Reverse Number Pattern

Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 4
1
21
321
4321

Detailed explanation ( Input/output format, Notes, Images )

Input format :
Integer N (Total no. of rows)

Output format :
Pattern in N lines

Constraints
0 <= N <= 50

Sample Input 1:
5

Sample Output 1:
1
21
321
4321
54321

Sample Input 2:
6

Sample Output 2:
1
21
321
4321
54321
654321
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = row+1; col >= 1; col--) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}