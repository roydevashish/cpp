/*
Title: Diamond of Stars

Problem statement
Print the following pattern for the given number of rows.
Note: N is always odd.

Pattern for N = 5
..*
.***
*****
.***
..*
The dots represent spaces.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
N (Total no. of rows and can only be odd)

Output format :
Pattern in N lines

Constraints :
1 <= N <= 49

Sample Input 1:
5

Sample Output 1:
  *
 ***
*****
 ***
  *

Sample Input 2:
3

Sample Output 2:
  *
 ***
  *
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n % 2 == 0) {
        return 0;
    }

    for(int row = 0; row < (n/2) + 1; row++) {
        for(int col = 0; col < (n/2+1)-1-row; col++) {
            cout << " ";
        }

        for(int col = 0; col < row*2+1; col++) {
            cout << "*";
        }
        cout << endl;
    }

    for(int row = 1; row <= (n/2); row++) {
        for(int col = 0; col < row; col++) {
            cout << " ";
        }

        for(int col = 0; col < n - 2*row; col++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}