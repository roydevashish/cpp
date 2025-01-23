/*
Title: Triangle Of Numbers

Problem statement
Print the following pattern for the given number of rows.

Pattern for N = 4
...1
..232
.34543
4567654

The dots represent spaces.

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
           1
          232
         34543
        4567654
       567898765

Sample Input 2:
4

Sample Output 2:
           1
          232
         34543
        4567654
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n-1-row; col++) {
            cout << " ";
        }

        for(int col = row+1; col <= row*2+1; col++) {
            cout << col;
        }

        for(int col = row*2; col >= row+1; col--) {
            cout << col;
        }
        cout << endl;
    }

    return 0;
}