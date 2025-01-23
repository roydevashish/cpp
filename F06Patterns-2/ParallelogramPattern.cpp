/*
Title: Parallelogram Pattern

Problem statement
Write a program to print parallelogram pattern for the given N number of rows.

For N = 4
****
.****
..****
...****
The dots represent spaces.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
A single integer : N

Output Format :
Required Pattern

Constraints :
0 <= N <= 50

Sample Input 1 :
3

Sample Output 1 :
***
 ***
  ***

Sample Input 2 :
5

Sample Output 2 :
*****
 *****
  *****
   *****
    *****
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < row; col++) {
            cout << " ";
        }

        for(int col = 0; col < n; col++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}