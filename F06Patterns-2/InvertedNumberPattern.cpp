/*
Title: Inverted Number Pattern

Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 4
4444
333
22
1

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer N (Total no. of rows)

Output format :
Pattern in N lines

Constraints :
0 <= N <= 50

Sample Input 1:
5

Sample Output 1:
55555 
4444
333
22
1

Sample Input 2:
6

Sample Output 2:
666666
55555 
4444
333
22
1
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n-row; col++) {
            cout << n-row << " ";
        }
        cout << endl;
    }

    return 0;
}