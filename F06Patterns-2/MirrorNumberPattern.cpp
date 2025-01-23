/*
Title: Mirror Number Pattern

Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 4
...1
..12
.123
1234

The dots represent spaces.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer N (Total no. of rows)

Output format :
Pattern in N lines

Constraints
0 <= N <= 50

Sample Input 1:
3

Sample Output 1:
  1 
 12
123

Sample Input 2:
4

Sample Output 2:
   1 
  12
 123
1234
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n - 1 - row; col++) {
            cout << "  "; 
        }

        for(int col = n-1-row, num = 1; col < n; col++, num++) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}